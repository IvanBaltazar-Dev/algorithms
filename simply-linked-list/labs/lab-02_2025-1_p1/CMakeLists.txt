cmake_minimum_required(VERSION 4.2)
project(2025_1_lab_02_p1)

set(CMAKE_CXX_STANDARD 20)

add_executable(2025_1_lab_02_p1 main.cpp
        Funciones.cpp
        Funciones.h
        BibliotecaLista/ElementoLista.h
        BibliotecaLista/funcionesLista.cpp
        BibliotecaLista/funcionesLista.h
        BibliotecaLista/Lista.h
        BibliotecaLista/NodoLista.h)
