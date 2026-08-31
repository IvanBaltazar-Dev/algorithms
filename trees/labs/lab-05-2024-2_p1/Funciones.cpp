//
// Created by Ivan Piero Baltazar on 1/07/2026.
//

#include "Funciones.h"

#include "BibliotecaArbolBinarioBusqueda/ArbolBinarioBusqueda.h"


void insertadiaturno(ArbolBinarioBusqueda &ABB, int cantidades[7][4]) {
    //CREACION DE LOS ELEMENTOS
    ElementoArbolBinarioBusqueda lista[28]{};
    int n = 0;
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 4; j++) {
            // i -> dia, j -> turno
            lista[n].dia = i+1;
            lista[n].turno = j+1;
            lista[n].numero = (i+1)*10+(j+1);
            lista[n].cantidad = cantidades[i][j];
            n++;
        }
    }

    //INSERTAR POR MITADES PARA QUE ABB NAZCA EQUILIBRADO
    insertarMitad(ABB, lista, 0, n-1);
}

void insertarMitad(ArbolBinarioBusqueda& ABB,ElementoArbolBinarioBusqueda *lista, int inicio, int fin){
    if (inicio > fin) {
        return;
    }
    int medio = (inicio + fin) / 2;

    insertar(ABB, lista[medio]);

    insertarMitad(ABB, lista, inicio, medio-1);
    insertarMitad(ABB, lista, medio + 1 , fin);
}

void insertaCantidad(ArbolBinarioBusqueda &ABB, int cantidades[7][4]) {
    //CREACION DE LOS ELEMENTOS
    ElementoArbolBinarioBusqueda lista[28]{};
    int n = 0;
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 4; j++) {
            lista[n].dia = i+1;
            lista[n].turno = j+1;
            lista[n].numero = cantidades[i][j]*100+(i+1)*10+(j+1);
            lista[n].cantidad = cantidades[i][j];
            n++;
        }
    }

    mergeSort(lista, 0, n-1);

    insertarMitad(ABB, lista, 0, n-1);
}

void mergeSort(ElementoArbolBinarioBusqueda *lista, int inicio, int fin) {
    if (inicio >= fin) return;
    int mitad = inicio + (fin - inicio)/2;

    mergeSort(lista,inicio,mitad);
    mergeSort(lista,mitad+1,fin);

    merge(lista,inicio,mitad,fin);
}

void merge(ElementoArbolBinarioBusqueda *lista, int inicio, int mitad, int fin) {
    ElementoArbolBinarioBusqueda temp[28]{};

    int i = inicio; //frente izquierda
    int j = mitad+1; //frente derecha
    int k = inicio; //pos donde se insertara al temp

    while (i <= mitad && j <= fin) {
        if (esMenor(lista[i],lista[j])) {
            temp[k] = lista[i];
            i++;
        }else {
            temp[k] = lista[j];
            j++;
        }
        k++;
    }
    while (i <= mitad) {
        temp[k] = lista[i];
        i++;
        k++;
    }
    while (j <= fin) {
        temp[k] = lista[j];
        j++;
        k++;
    }
    for (int p = inicio; p <= fin; p++) {
        lista[p] = temp[p];
    }
}

bool esMenor(ElementoArbolBinarioBusqueda a,ElementoArbolBinarioBusqueda b) {
    if (a.cantidad < b.cantidad) return true;
    if (a.cantidad > b.cantidad) return false;
    return a.numero < b.numero;
}


//ERORES COMETIDOS
// while (i <= mitad && j <= fin) {
//     if (esMenor(lista[i],lista[j])) {
//         temp[k] = lista[i];
//         i++;
//     }else {
//         temp[k] = lista[j];
//         j++;
//     }
//     k++;   // <-- corregido
// }



















