cmake_minimum_required(VERSION 4.2)
project(lab_03_2025_2_p2)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab_03_2025_2_p2 main.cpp
        BibliotecaCola/ElementoCola.h
        BibliotecaCola/Cola.h
        BibliotecaCola/funcionesCola.cpp
        BibliotecaCola/funcionesCola.h
        BibliotecaCola/NodoCola.h
        BibliotecaPila/ElementoPila.h
        BibliotecaPila/funcionesPila.cpp
        BibliotecaPila/funcionesPila.h
        BibliotecaPila/NodoPila.h
        BibliotecaPila/Pila.h
        Funcion.cpp
        Funcion.h)
