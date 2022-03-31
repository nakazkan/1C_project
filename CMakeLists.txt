cmake_minimum_required(VERSION 3.14)
project(1C_project)

set(CMAKE_CXX_STANDARD 20)

add_executable(1C_project main.cpp suff_automaton.h suff_automation.cpp find_occurrence.h)
