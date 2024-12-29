import { Signature } from "cpp-signatures";
import { headers } from "./files";
import { range } from "ramda";
import fs from "fs";

headers.forEach((file) => {
  const lines = fs.readFileSync(file, "utf8").split("\n");

  range(0, lines.length - 2).forEach((i) => {
    const line = lines[i];
    const signature = lines[i + 2].trim().replace(";", "");

    if (
      line.includes("//") &&
      !["namespace", "clang-format"].some((str) => line.includes(str))
    ) {
      if (signature !== "") {
        lines[i] = line
          .split("//", 1)
          .concat("// ", new Signature(signature).format())
          .join("");
      }
    }
  });

  fs.writeFileSync(file, lines.join("\n"));
});
