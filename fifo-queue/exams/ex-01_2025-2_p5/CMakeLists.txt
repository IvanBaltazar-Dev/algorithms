cmake_minimum_required(VERSION 4.2)
project(ex_01_2025_2_p5)

set(CMAKE_CXX_STANDARD 20)

add_executable(ex_01_2025_2_p5 main.cpp
        BibliotecaCola/ElementoCola.h
        BibliotecaCola/Cola.h
        BibliotecaCola/funcionesCola.cpp
        BibliotecaCola/funcionesCola.h
        BibliotecaCola/NodoCola.h
        Funciones.cpp
        Funciones.h)
