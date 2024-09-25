from conan import ConanFile
from conan.tools.cmake import CMake, CMakeToolchain, CMakeDeps, cmake_layout

class CompressorRecipe(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    # generators = "CMakeToolchain", "CMakeDeps"


    def requirements(self):
        self.requires("cpp-httplib/0.16.3")
        self.requires("gtest/1.15.0")
        self.requires("spdlog/1.14.0")

        self.tool_requires("cmake/3.27.9")
        pass

    def configure(self):
        self.options["*"].shared = False
        self.options["*"].fpic = True
        pass

    def layout(self):
        cmake_layout(self)
        pass

    def generate(self):
        # build_type = self.settings.get_safe("build_type", default="Release")
        # print(build_type)

        tc = CMakeToolchain(self)
        tc.generate()
        deps = CMakeDeps(self)
        deps.generate()
        pass

    def build(self):
        cmake = CMake(self)
        cmake.configure()  # equivalent to self.run("cmake . <other args>")
        cmake.build() # equivalent to self.run("cmake --build . <other args>")
        pass
