import { globSync } from "glob";
import path from "path";

export const src = path.resolve(__dirname, "..", "src");
export const headers = globSync(`${src}/**/*.hpp`);
