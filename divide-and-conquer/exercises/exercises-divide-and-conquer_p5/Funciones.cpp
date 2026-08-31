//
// Created by Ivan Piero Baltazar on 17/06/2026.
//

#include "Funciones.h"


int resuelve(int *arr, int inicio,int fin) {
    if (inicio == fin) {
        return inicio;
    }
    int mitad = inicio + (fin - inicio)/2;

    if (arr[mitad] < arr[mitad+1]) {
        //Estoy en la parte creciente, el máximo está a la derecha
        return resuelve(arr,mitad+1,fin);
    }else { //Estoy bajando o estoy en el pico
        return resuelve(arr,inicio,mitad);
    }
}