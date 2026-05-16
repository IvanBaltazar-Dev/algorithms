cmake_minimum_required(VERSION 4.1)
project(20196388_LAB3_P1)

set(CMAKE_CXX_STANDARD 20)

add_executable(20196388_LAB3_P1 main.cpp
        Funcion.cpp
        Funcion.h
        BibliotecaLista/funcionesLista.h
        BibliotecaLista/funcionesLista.cpp
        BibliotecaLista/ElementoLista.h
        BibliotecaLista/NodoLista.h
        BibliotecaLista/Lista.h)
