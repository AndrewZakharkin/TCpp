cmake_minimum_required(VERSION 3.5)
project(FirstTest)

set(CMAKE_CXX_STANDARD 14)
INCLUDE_DIRECTORIES(~/jdk-11.0.1/include ~/jdk-11.0.1/include/linux)

add_executable(FirstTest main.cpp javah.h Algorythm/Builder.cpp Algorythm/Builder.h Algorythm/Node.cpp Algorythm/Node.h Algorythm/Algo.cpp Algorythm/Algo.h StlPlay.cpp StlPlay.h Sort/QuickSortInt.cpp Sort/QuickSortInt.h Algorythm/SimpleNode.cpp Algorythm/SimpleNode.h)
TARGET_LINK_LIBRARIES(FirstTest ~/jdk-11.0.1/lib/server/libjvm.so)