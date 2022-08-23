# Logger

If you use this as a standalone, you'll need [ETL](https://github.com/ETLCPP/etl).
You can add it with conan, or as a submodule, etc.
To add ETL through conan, there's already a `conanfile.txt` in the root directory. You can:

- `mkdir build && cd build`
- `conan install ..`

1. You might need to run `conan profile new default --detect` and `conan profile update settings.compiler.libcxx=libstdc++11 default`, to generate default profile detecting GCC, set old ABI and set `libcxx` to the C++11 ABI, respectively. This is done to [manage the GCC >= 5 ABI](https://docs.conan.io/en/latest/howtos/manage_gcc_abi.html#manage-gcc-abi)
2. After you've run `conan install`, a `conanbuildinfo.cmake` file will have been generated. You can then edit the `CMakeLists.txt` to add the lines `include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)` and `conan_basic_setup()`

Don't forget to include the line `add_compile_definitions<LOG_LEVEL>` in your `CmakeLists.txt`, for example `add_compile_definitions(LOGLEVEL_TRACE)`.
