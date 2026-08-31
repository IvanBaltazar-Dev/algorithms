cmake_minimum_required(VERSION 4.2)
project(ex_02_2025_1_p3)

set(CMAKE_CXX_STANDARD 20)

add_executable(ex_02_2025_1_p3 main.cpp
        BibliotecaArbolBinarioBusqueda/ArbolBinarioBusqueda.h
        BibliotecaArbolBinarioBusqueda/ElementoArbolBinarioBusqueda.h
        BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.cpp
        BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.h
        BibliotecaArbolBinarioBusqueda/NodoArbolBinarioBusqueda.h
        Funciones.cpp
        Funciones.h)
