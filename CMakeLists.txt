cmake_minimum_required(VERSION 4.1)
project(my_Hashtable C)

set(CMAKE_C_STANDARD 11)

add_executable(my_Hashtable main.c
        my_Strings.c
        my_Strings.h
        hashtable.c
        hashtable.h
)
