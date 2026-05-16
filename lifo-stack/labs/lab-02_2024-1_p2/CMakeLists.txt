cmake_minimum_required(VERSION 4.2)
project(lab_02_2024_1_p2)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab_02_2024_1_p2 main.cpp
        Funciones.cpp
        Funciones.h
        BibliotecaLista/ElementoLista.h
        BibliotecaLista/funcionesLista.cpp
        BibliotecaLista/funcionesLista.h
        BibliotecaLista/Lista.h
        BibliotecaLista/NodoLista.h
        BibliotecaPila/ElementoPila.h
        BibliotecaPila/funcionesPila.cpp
        BibliotecaPila/funcionesPila.h
        BibliotecaPila/NodoPila.h
        BibliotecaPila/Pila.h)
