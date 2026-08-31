//
// Created by Ivan Piero Baltazar on 18/06/2026.
//

#include "Funciones.h"

int resuelveRadiacion(int *arr, int inicio, int fin) {
    if (inicio > fin) {
        return -1;
    }
    if (inicio == fin) {
        if (arr[inicio] > 0) return inicio;
        return -1;
    }
    int mitad = inicio + (fin - inicio)/2;


    if (arr[mitad] > 0) {//Si es mayor esta en la izquierda
        return resuelveRadiacion(arr, inicio, mitad);
    }else {
        //Si es menor o 0 estamos parados en frontera o esta a la izquierda
        return resuelveRadiacion(arr, mitad+1, fin);
    }
}

int buscarPotenciaMaxima(int *arr,int inicio,int fin) {
    if (inicio == fin) {
        return inicio;
    }
    int mitad = inicio + (fin - inicio)/2;

    if (arr[mitad] < arr[mitad+1]) { //Creciente busca en la derecha
        return buscarPotenciaMaxima(arr, mitad+1, fin);
    }else {//Estamos en el pico o busca izquierda
        return buscarPotenciaMaxima(arr, inicio, mitad);
    }
}