cmake_minimum_required(VERSION 2.8)
project(neighcol)
find_package(MPI REQUIRED)
set(CMAKE_CXX_COMPILER ${MPI_CXX_COMPILER})

set(SRC_FILES
	NclLocalArray.cpp
	NclDecomp.cpp)

add_library(neighcol STATIC ${SRC_FILES})

add_executable(test0 test0.cxx)
add_executable(test1 test1.cxx)

