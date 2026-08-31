cmake_minimum_required(VERSION 4.2)
project(ex_02_2025_2_p5)

set(CMAKE_CXX_STANDARD 20)

add_executable(ex_02_2025_2_p5 main.cpp
        BibliotecaCola/funcionesCola.cpp
        BibliotecaCola/Cola.h
        BibliotecaCola/ElementoCola.h
        BibliotecaCola/NodoCola.h
        BibliotecaCola/funcionesCola.h
        Funciones.cpp
        Funciones.h)
