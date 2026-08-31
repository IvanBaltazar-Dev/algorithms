cmake_minimum_required(VERSION 4.2)
project(lab_05_2026_1_p1_A)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab_05_2026_1_p1_A main.cpp
        BibliotecaArbolBinarioBusqueda/ArbolBinarioBusqueda.h
        BibliotecaArbolBinarioBusqueda/ElementoArbolBinarioBusqueda.h
        BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.cpp
        BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.h
        BibliotecaArbolBinarioBusqueda/NodoArbolBinarioBusqueda.h
        BibliotecaCola/Cola.h
        BibliotecaCola/ElementoCola.h
        BibliotecaCola/funcionesCola.cpp
        BibliotecaCola/funcionesCola.h
        BibliotecaCola/NodoCola.h
        Funciones.cpp
        Funciones.h)
