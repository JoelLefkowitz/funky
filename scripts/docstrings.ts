import { Parameter, Signature } from "cpp-signatures";
import { logger } from "file-loggers";
import fs from "fs";

const rewrite = (file: string, update: (text: string) => string): void =>
  fs.writeFileSync(file, update(fs.readFileSync(file, "utf8")));

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
  action: () =>
    logger(
      "src/**/*.hpp",
      async (file) =>
        rewrite(file, (text) =>
          text.split("\n\n").reduce((acc, block) => {
            const lines = block
              .split("\n")
              .filter((i) => !["namespace funky {", "}"].includes(i))
              .map((i) => i.trimStart());

            const [comment] = lines;

            if (comment?.startsWith("//")) {
              const [definition, concepts] = lines.reverse();
              const signature = new Signature(definition.replace(";", ""));

              const replacements = Object.fromEntries(
                ["A", "B", "C"].map((i) => [`F${i}`, `[ ${i} ]`]),
              );

              replacements["<A,B>"] = "<A, B>";

              const [_, type, output, inputs] =
                /requires Callable<(.*), (.*)\((.*)\)>/.exec(concepts) ?? [];

              if (type && output && inputs) {
                const callback = inputs.split(", ").concat(output).join(" -> ");
                replacements[type] = `( ${callback} )`;
              }

              signature.output = simplify(signature.output, replacements);
              signature.inputs = signature.inputs.map((input) =>
                simplify(input, replacements),
              );

              const formatted = `// ${signature.name}: ${signature.format().replaceAll("->", "→")}`;

              if (comment !== formatted) {
                return acc.replace(comment, formatted);
              }
            }

            return acc;
          }, text),
        ),
      {
        count: true,
        trail: true,
        timer: true,
      },
    ),
};
