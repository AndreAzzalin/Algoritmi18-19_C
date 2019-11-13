cmake_minimum_required(VERSION 3.14)
project(Esercizio_1 C)

set(CMAKE_C_STANDARD 99)

add_executable(Esercizio_1 main.c list.h list.c test/unitTest_list.c test/unitTest_list.h)