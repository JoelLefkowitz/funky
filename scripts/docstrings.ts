import { Parameter, Signature } from "cpp-signatures";
import { globSync } from "glob";
import {
  assoc,
  assocPath,
  concat,
  flatten,
  groupBy,
  intersperse,
  last,
  map,
  mergeRight,
  mergeWith,
  prop,
  replace,
  reverse,
  sortBy,
} from "ramda";
import fs from "fs";

interface Block {
  file: string;
  block: string;
}

interface Definition {
  name: string;
  include: string;
  signature: string;
  docstring: string;
}

interface Replacement {
  file: string;
  current: string;
  docstring: string;
}

const prepend =
  (prefix: string) =>
  (str: string): string =>
    prefix.concat(str);

const surround =
  (before: string, after: string, delimiter = "") =>
  (str: string): string =>
    [before, str, after].join(delimiter);

const markdown = {
  h2: prepend("## "),
  h3: prepend("### "),
  h4: prepend("#### "),
  inline: surround("`", "`"),
  block: surround("```cpp", "```", "\n"),
};

const tokens = {
  overview: markdown.h2("Overview"),
  tooling: markdown.h2("Tooling"),
};

const regexes = {
  callable: /requires Callable<(.*), (.*)\((.*)\)>/,
};

const format = {
  brace: surround("(", ")"),
  domain: (str: string) => last(str.split("/")).replace(".hpp", ""),
  available: (str: string) => `Available in: ${markdown.inline(str)}`,
  definition: ({ name }: Signature, docstring: string) =>
    ["//", name, "≔", docstring].join(" "),
};

const capitalise = (str: string): string =>
  str.slice(0, 1).toUpperCase() + str.slice(1);

const rewrite = (file: string, update: (text: string) => string): void =>
  fs.writeFileSync(file, update(fs.readFileSync(file, "utf8")));

const blocks = (file: string): Block[] =>
  fs
    .readFileSync(file, "utf8")
    .replaceAll("\n        ", "")
    .replaceAll("\n    );", ");")
    .split("\n\n")
    .map((block) => ({ file, block }));

const sanitise = (str: string): string =>
  str
    .replace(");", "")
    .split(", ")
    .map((i) => i.split(" = ")[0])
    .join(",")
    .concat(")");

const simplify = (
  input: Parameter,
  replacements: Record<string, string>,
): Parameter => {
  const parameter = Object.create(input);

  parameter.constant = false;
  parameter.reference = false;

  parameter.typename = Object.entries(replacements).reduce(
    (acc, [k, v]) => acc.replace(k, v),
    input.typename,
  );

  return parameter;
};

export default {
  name: "docstrings",
  description: "Check docstring formats",
  action: () => {
    const { definitions, replacements } = globSync("src/**/*.hpp")
      .flatMap(blocks)
      .reduce<{
        definitions: Definition[];
        replacements: Replacement[];
      }>(
        (acc, { file, block }) => {
          const lines = block
            .split("\n")
            .filter((i) => !["namespace funky {", "}"].includes(i))
            .map((i) => i.trimStart());

          const [current] = lines;

          if (current?.startsWith("//")) {
            const [signature, concepts] = lines.reverse();
            const parsed = new Signature(sanitise(signature));

            const updates = { "<A,B>": "<A, B>" };

            ["A", "B", "C"].forEach((i) => {
              updates[`F${i}`] = `[ ${i} ]`;
            });

            const [_, type, output, inputs] =
              regexes.callable.exec(concepts) ?? [];

            if (type && output && inputs) {
              updates[type] = format.brace(
                inputs.split(", ").concat(output).join(" -> "),
              );
            }

            parsed.output = simplify(parsed.output, updates);
            parsed.inputs = parsed.inputs.map((input) =>
              simplify(input, updates),
            );

            const docstring = parsed.format().replaceAll("->", "→");
            const formatted = format.definition(parsed, docstring);

            const definition = {
              name: parsed.name,
              include: file.replace("src", "funky"),
              signature,
              docstring,
            };

            const replacement = {
              file,
              current,
              docstring: formatted,
            };

            return mergeWith(concat, acc, {
              definitions: [definition],
              replacements: current === formatted ? [] : [replacement],
            });
          }

          return acc;
        },
        {
          definitions: [],
          replacements: [],
        },
      );

    replacements.forEach(({ file, current, docstring }) => {
      rewrite(file, (text) => text.replace(current, docstring));
    });

    rewrite("README.md", (text) => {
      const lines = text.split("\n");

      const hierarchy = map(
        groupBy(prop("name")),
        groupBy(prop("include"), definitions),
      );

      const sections = [
        "callables",
        "iterables",
        "sets",
        "pairs",
        "mutable",
        "booleans",
        "numbers",
        "strings",
        "vectors",
      ];
      const docs = sortBy(
        ([i]) => -reverse(sections).indexOf(format.domain(i)),
        Object.entries(hierarchy),
      ).reduce(
        (acc, [include, named]) =>
          acc.concat(
            markdown.h3(capitalise(format.domain(include))),
            format.available(include),
            Object.entries(named).reduce(
              (acc, [name, definitions]) =>
                acc.concat(
                  markdown.h4(name),
                  markdown.block(
                    definitions
                      .map(({ signature, docstring }) =>
                        ["// ", docstring, "\n", signature].join(""),
                      )
                      .join("\n\n"),
                  ),
                ),
              [],
            ),
          ),
        [tokens.overview],
      );

      return [
        lines.slice(0, lines.indexOf(tokens.overview) - 1),
        intersperse("", docs),
        lines.slice(lines.indexOf(tokens.tooling)),
      ]
        .map((i) => i.join("\n"))
        .join("\n\n");
    });
  },
};
