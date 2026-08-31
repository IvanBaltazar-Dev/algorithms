cmake_minimum_required(VERSION 4.2)
project(lab_05_2026_1_p2)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab_05_2026_1_p2 main.cpp
        BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.h
        BibliotecaArbolBinarioBusqueda/ArbolBinarioBusqueda.h
        BibliotecaArbolBinarioBusqueda/ElementoArbolBinarioBusqueda.h
        BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.cpp
        BibliotecaArbolBinarioBusqueda/NodoArbolBinarioBusqueda.h
        Functions/Funciones.cpp
        Functions/Funciones.h
        EstructurasAdicionales/Letra.h)
