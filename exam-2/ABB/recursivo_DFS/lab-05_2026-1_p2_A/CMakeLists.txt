cmake_minimum_required(VERSION 4.2)
project(lab_05_2026_1_p2_A)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab_05_2026_1_p2_A main.cpp
        BibliotecaArbolBinarioBusqueda/ArbolBinarioBusqueda.h
        BibliotecaArbolBinarioBusqueda/ElementoArbolBinarioBusqueda.h
        BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.cpp
        BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.h
        BibliotecaArbolBinarioBusqueda/NodoArbolBinarioBusqueda.h
        Funciones.cpp
        Funciones.h
        EstructurasAdicionales/Letra.h)
