import { logger } from "file-loggers";
import { drop } from "ramda";
import fs from "fs";
import path from "path";

export default {
  name: "guards",
  description: "Check header guards are consistent",
  action: () =>
    logger(
      `src/**/*.hpp`,
      async (file) => {
        const lines = fs.readFileSync(file, "utf8").split("\n");
        const guard = drop("#ifndef".length + 1, lines[0]);

        const derived = ["funky"]
          .concat(path.relative("src", file).split(path.sep))
          .join("_")
          .replace(/\./g, "_")
          .toUpperCase();

        if (
          lines.length < 2 ||
          !lines[0].startsWith("#ifndef") ||
          !lines[1].startsWith("#define")
        ) {
          throw new Error("The first lines should be a header guard");
        }

        if (guard !== derived) {
          console.log(`Replacing ${guard} with ${derived}`);
          lines[0] = `#ifndef ${derived}`;
          lines[1] = `#define ${derived}`;
        }

        fs.writeFileSync(file, lines.join("\n"));
      },
      {
        count: true,
        trail: true,
        timer: true,
      },
    ),
};
