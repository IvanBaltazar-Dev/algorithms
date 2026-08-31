//
// Created by Ivan Piero Baltazar on 9/07/2026.
//

#include "Funciones.h"
#include <fstream>
void llenadoArboles(Letra ABB[]) {
    ifstream archivo("volveran_las_oscuras_golondrinas.txt",ios::in);
    if (!archivo.is_open()) {
        cout<<"Error al abrir el archivo"<<endl;
        exit(1);
    }
    string palabra{};
    while (true) {
        archivo>>palabra;
        if (archivo.eof()) break;
        char letra_inicial = palabra[0];
        int index = letra_inicial - 97;

        ElementoArbolBinarioBusqueda elemento{};
        elemento.palabra = palabra;
        elemento.cantidad = 1;
        insertar(ABB[index].arbol,elemento);
    }
}

void imprimirFrecuencias(Letra ABB[]) {
    cout<<"=============================================="<<endl;
    cout<<"REPORTE DE FRECUENCIAS DE PALABRAS EN EL POEMA"<<endl;
    cout<<"=============================================="<<endl;

    for (int i = 0; i < 26; i++) {
        cout<<ABB[i].letra<<":"<<endl;
        recorrerEnOrden(ABB[i].arbol);
    }

}
