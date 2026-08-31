//
// Created by Ivan Piero Baltazar on 6/07/2026.
//

#include "Funciones.h"

void procesarTexto(Letra *letras,int size) {
    ifstream archivo("volveran_las_oscuras_golondrinas.txt",ios::in);
    if (!archivo.is_open()) {
        cout<<"Error al abrir el archivo"<<endl;
        exit(1);
    }
    string palabra;
    while (true) {
        archivo>>palabra;
        if (archivo.eof()) break;
        ElementoArbolBinarioBusqueda elemento{};
        elemento.palabra = palabra;
        char caracter = palabra[0];
        int number_caracter =  int(caracter)-97;
        cout<<"La palabra \""<<palabra<<"\" se insertara en el arbol "<<letras[number_caracter].letra<<endl;
        insertar(letras[number_caracter].arbol,elemento);

    }
}

void imprimirLetras(Letra *letras,int size) {
    for (int i = 0; i < size; i++) {
        cout << letras[i].letra<< ": "<<endl;
        recorrerEnOrden(letras[i].arbol);
    }
    cout << endl;
}