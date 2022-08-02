# fraction
A fraction library for c++

## Usage
Clone repo.
~~~bash
git clone https://github.com/johansolbakken/fraction.git
~~~

Update CMake.
~~~CMake
add_subdirectory(path/to/fraction/CMakeLists.txt)
add_executable(executableName main.cpp)
target_include_directories(executableName PRIVATE path/to/fraction/include)
target_link_libraries(executableName PRIVATE fraction)
~~~
