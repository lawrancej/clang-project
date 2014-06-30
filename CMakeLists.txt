cmake_minimum_required(VERSION 2.8)

set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")

project(clangProject)

find_package(LLVM REQUIRED)

# c settings
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -std=c99 -fPIC")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g -O0")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -O4 -DNDEBUG") 
	
# c++ settings
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11 -fPIC")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O4 -DNDEBUG")

include_directories( ${LLVM_INCLUDE_DIRS} )
link_directories( ${LLVM_LIBRARY_DIRS} )
llvm_map_components_to_libraries(REQ_LLVM_LIBRARIES native)
add_definitions( ${LLVM_DEFINITIONS} )

add_executable(clang-project src/test.cpp)
target_link_libraries(clang-project c++abi ${REQ_LLVM_LIBRARIES} clang clangFrontend clangAST clangTooling)

