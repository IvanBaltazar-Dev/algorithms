cmake_minimum_required(VERSION 4.2)
project(2025_2_ex1_p3)

set(CMAKE_CXX_STANDARD 20)

add_executable(2025_2_ex1_p3 main.cpp
        BibliotecaLista/ElementoLista.h
        BibliotecaLista/funcionesLista.cpp
        BibliotecaLista/funcionesLista.h
        BibliotecaLista/Lista.h
        BibliotecaLista/NodoLista.h
        Funciones.cpp
        Funciones.h)
