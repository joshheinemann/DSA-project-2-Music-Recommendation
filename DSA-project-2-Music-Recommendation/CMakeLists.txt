cmake_minimum_required(VERSION 3.30)
project(DSA_project_2_Music_Recommendation)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(DSA_project_2_Music_Recommendation
    src/Dataset.cpp
    src/Dataset.h
    src/KNN.cpp
    src/main.cpp
    src/parsingtest.cpp
    src/Song.cpp
    src/Song.h
    src/Songkdtree.h)
