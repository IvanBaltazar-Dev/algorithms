//
// Created by Ivan Piero Baltazar on 17/06/2026.
//

#include "Funciones.h"

void resuelve(int *arr, int inicio, int fin,int codigo, int &result) {
    if(inicio>fin) {
        return;
    }

    int mitad = inicio + (fin - inicio)/2;
    if (arr[mitad] == codigo) { //es la mitad
        result = mitad;
        return;
    }
    if (arr[mitad]>arr[fin] && codigo <= arr[fin]) { //busca derecha
        return resuelve(arr, mitad+1, fin,codigo,result);
    }else {//izquierda
        return resuelve(arr, inicio, mitad-1,codigo,result);
    }
}
