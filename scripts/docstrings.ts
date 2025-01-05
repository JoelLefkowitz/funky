import { Signature } from "cpp-signatures";
import { logger } from "file-loggers";
import { range } from "ramda";
import fs from "fs";

export default {
  name: "docstrings",
  description: "Check docstring formats",
  action: () =>
    logger(
      "src/**/*.hpp",
      async (file) => {
        const lines = fs.readFileSync(file, "utf8").split("\n");

        range(0, lines.length - 2).forEach((i) => {
          const signature = lines[i];
          const definition = (
            lines[i + 2].includes("(") ? lines[i + 2] : lines[i + 1]
          )
            .trim()
            .replace(";", "");

          if (
            definition !== "" &&
            signature.includes("//") &&
            !["namespace", "clang-format"].some((str) =>
              signature.includes(str),
            )
          ) {
            const derived = signature
              .split("//", 1)
              .concat("// ", new Signature(definition).format())
              .join("");

            if (signature !== derived) {
              console.log(`Replacing ${signature} with ${derived}`);
              lines[i] = derived;
            }
          }
        });

        fs.writeFileSync(file, lines.join("\n"));
      },
      {
        count: true,
        trail: true,
        timer: true,
      },
    ),
};
