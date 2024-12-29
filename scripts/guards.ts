import { src, headers } from "./files";
import fs from "fs";
import path from "path";

headers.forEach((file) => {
  const lines = fs.readFileSync(file, "utf8").split("\n");

  const guard = ["funky"]
    .concat(path.relative(src, file).split(path.sep))
    .join("_")
    .replaceAll(".", "_")
    .toUpperCase();

  if (lines.length < 2) {
    console.log(`${file} has no header guard`);
  } else if (lines[0] !== `#ifndef ${guard}`) {
    console.log(`${file}: The first line should be "#ifndef ${guard}"`);
  } else if (lines[1] !== `#define ${guard}`) {
    console.log(`${file}: The second line should be #define ${guard}`);
  } else if (lines[lines.length - 2] !== `#endif`) {
    console.log(`${file}: The second last line should be #endif`);
  } else if (lines[lines.length - 1] !== "") {
    console.log(`${file}: The last line should be ""`);
  }
});
