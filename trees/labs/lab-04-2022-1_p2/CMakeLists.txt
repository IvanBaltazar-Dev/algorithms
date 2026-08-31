cmake_minimum_required(VERSION 4.2)
project(lab_04_2022_1_p2)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab_04_2022_1_p2 main.cpp
        BibliotecaArbolBinarioBusqueda/ArbolBinarioBusqueda.h
        BibliotecaArbolBinarioBusqueda/ElementoArbolBinarioBusqueda.h
        BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.cpp
        BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.h
        BibliotecaArbolBinarioBusqueda/NodoArbolBinarioBusqueda.h
        Funciones.cpp
        Funciones.h
)
