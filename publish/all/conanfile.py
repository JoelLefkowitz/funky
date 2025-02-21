import os

from conan import ConanFile
from conan.tools.files import copy, get
from conan.tools.scons import SConsDeps
from conan.tools.layout import basic_layout


class FunkyConan(ConanFile):
    name = "funky"
    description = "Functional and ergonomic transformations."
    license = "MIT"

    url = "https://github.com/conan-io/conan-center-index"
    homepage = "https://github.com/JoelLefkowitz/funky"

    topics = (
        "functional",
        "immutable",
        "iterables",
        "generics",
    )

    settings = (
        "os",
        "arch",
        "compiler",
        "build_type",
    )

    def layout(self):
        basic_layout(self)

    def package_id(self):
        self.info.clear()

    def source(self):
        get(
            self,
            **self.conan_data["sources"][self.version],
            strip_root=True,
        )

    def generate(self):
        SConsDeps(self).generate()

    def build_requirements(self):
        self.test_requires("gtest/1.12.1")

    def build(self):
        self.run("scons build", cwd="..")

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
        self.run("tree .. -L 5")
        
    def package_info(self):
        self.cpp_info.bindirs = []
        self.cpp_info.libs = [self.name]
