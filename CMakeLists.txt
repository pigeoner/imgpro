cmake_minimum_required(VERSION 3.10)
project(imgpro)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_BUILD_TYPE "Debug")

find_package(OpenCV REQUIRED)

# 是否使用 CMake 缓存，OFF 代表每次重新生成
# set(CMAKE_SUPPRESS_REGENERATION ON)

# 优化选项
# -Os 旨在优化代码大小，-g0 禁用调试信息
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Os -g0")
# 去除符号表和重定位信息
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s")

add_executable(imgpro imgpro.cpp symmetrize/symmetrize.cpp)
target_link_libraries(imgpro ${OpenCV_LIBS})