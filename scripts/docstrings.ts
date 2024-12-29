import { Signature } from "cpp-signatures";
import { globSync } from "glob";
import { range } from "ramda";
import fs from "fs";

globSync(`${__dirname}/../src/**/*.hpp`).slice(10, 11).forEach((file) => {
  const lines = fs.readFileSync(file, "utf8").split("\n");

  range(0, lines.length).forEach((i) => {
    if (lines[i].includes("/**")) {
      const signature = lines[i + 4].trim().replace(";", "");

      lines[i + 1] = lines[i + 1]
        .split("*", 1)
        .concat("* ", new Signature(signature).format())
        .join("");
    }

    console.log(lines);
  });
});
