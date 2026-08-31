//
// Created by Ivan Piero Baltazar on 10/07/2026.
//

#include "Funciones.h"

int contadorSemillas(int arr[],int size) {
    int result = 0;

    Pila pila{};
    construir(pila);

    for (int i = 0; i < size; i++) {
        while (!esPilaVacia(pila) && arr[i] > arr[cima(pila).numero]) {

            ElementoPila fondo = desapilar(pila);

            if (esPilaVacia(pila)) break;

            ElementoPila izquierda = cima(pila);

            int ancho = i - izquierda.numero - 1;

            int menorAltura;

            if (arr[izquierda.numero] < arr[i]) {
                menorAltura = arr[izquierda.numero];
            }else {
                menorAltura = arr[i];
            }

            int altura = menorAltura - arr[fondo.numero];

            result += ancho * altura;
        }
        
        ElementoPila elemento_pila{};
        elemento_pila.numero = i;
        apilar(pila,elemento_pila);
    }

    return result;
}