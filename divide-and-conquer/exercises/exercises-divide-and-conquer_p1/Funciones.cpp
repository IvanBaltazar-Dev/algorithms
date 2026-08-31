//
// Created by Ivan Piero Baltazar on 3/06/2026.
//

#include "Funciones.h"

int resuelve(int *arr,int inicio,int fin){
    if (inicio>fin) return -1;
    if (inicio == fin) return inicio;

    int medio = inicio + (fin-inicio)/2;
    if (medio%2==1) {
        //medio debe ser par para buscar la derecha
        medio--;
    }
    if (arr[medio]==arr[medio+1]) {
        //Tienen par buscar derecha
        return resuelve(arr,medio+2,fin);
    }else {
        //Se rompio el unitario esta a la izquierda o es el elemento actual
        return  resuelve(arr,inicio,medio);
    }
}



