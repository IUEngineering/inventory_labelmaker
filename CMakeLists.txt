cmake_minimum_required(VERSION 3.20)
project(inventory_labelmaker C)

set(CMAKE_C_STANDARD 99)

add_executable(inventory_labelmaker main.c lib/pdfgen.c)
