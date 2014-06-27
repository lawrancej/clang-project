cmake_minimum_required(VERSION 2.8)

# set(CMAKE_C++_COMPILER /usr/bin/g++)

project(clangProject C)

find_package(LLVM REQUIRED)
# find_library(LibClang_LIBRARY NAMES clang PATH_SUFFIXES llvm)

set(CMAKE_C_FLAGS "-std=c11 -lclang")
# set(LLVM_USED_LIBS clangTooling)

include_directories( ${LLVM_INCLUDE_DIRS} )
link_directories( ${LLVM_LIBRARY_DIRS} )
llvm_map_components_to_libraries(REQ_LLVM_LIBRARIES native)
add_definitions( ${LLVM_DEFINITIONS} )

add_executable(clang-project src/test.c)
target_link_libraries(clang-project ${REQ_LLVM_LIBRARIES})

