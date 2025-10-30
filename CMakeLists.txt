cmake_minimum_required(VERSION 3.27.7)
project(P4_DecodeHuffman)

set(CMAKE_CXX_STANDARD 20)

add_executable(P4_DecodeHuffman
        main.cpp
        TreeNode.hpp
        utils.cpp
        utils.hpp
)


