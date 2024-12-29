import os

from conan import ConanFile
from conan.tools.files import copy, get
from conan.tools.scons import SConsDeps
from conan.tools.layout import basic_layout


class FunkyConan(ConanFile):
    name = "funky"
    description = "Funky type classes and instances."
    license = "MIT"

    url = "https://github.com/conan-io/conan-center-index"
    homepage = "https://github.com/JoelLefkowitz/funky"

    topics = (
        "functional",
        "instance",
        "functor",
        "applicative",
        "monad",
    )

    settings = (
        "os",
        "arch",
        "compiler",
        "build_type",
    )

    exports_sources = (
        "src/*.[cht]pp",
        "conanfile.py",
        "Sconstruct.py",
        "LICENSE.md",
    )

    def layout(self):
        basic_layout(self, src_folder="src")

    def generate(self):
        SConsDeps(self).generate()

    def source(self):
        get(self, **self.conan_data["sources"][self.version], strip_root=True)

    def build(self):
        os.chdir("..")
        self.run("scons build")

    def package(self):
        copy(
            self,
            "LICENSE.md",
            os.path.join(self.build_folder, ".."),
            os.path.join(self.package_folder, "licenses"),
        )
        copy(
            self,
            "*.[ht]pp",
            os.path.join(self.build_folder, "..", "src"),
            os.path.join(self.package_folder, "include", self.name),
        )
        copy(
            self,
            "*.a",
            os.path.join(self.build_folder, "..", "dist"),
            os.path.join(self.package_folder, "lib"),
        )

    def package_info(self):
        self.cpp_info.bindirs = []
        self.cpp_info.libs = [self.name]
