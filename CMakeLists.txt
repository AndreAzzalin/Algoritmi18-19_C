cmake_minimum_required(VERSION 3.14)
project(Esercizio_1 C)

set(CMAKE_C_STANDARD 99)

add_executable(Esercizio_1 linked_list/test_linked_list.c linked_list/linked_list.h linked_list/linked_list.c dynamic_list/dynamic_list.h dynamic_list/dynamic_list.c dynamic_list/test_dynamic_list.c)