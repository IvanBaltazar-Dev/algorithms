//
// Created by Ivan Piero Baltazar on 9/07/2026.
//

#include "Funciones.h"

#include <algorithm>

int mergesort(Resultado resultado[],int inicio,int fin) {
    if (inicio>=fin) return 0;

    int mitad = inicio + (fin-inicio)/2;

    int contIzq = mergesort(resultado,inicio,mitad);
    int contDer = mergesort(resultado,mitad+1,fin);

    int contCruzado = merge(resultado,inicio,mitad,fin);

    return contIzq + contDer + contCruzado;
}

int merge(Resultado resultado[], int inicio, int mitad, int fin) {
    int n1 = mitad - inicio + 1;
    int n2 = fin - mitad +1 -1 ;

    Resultado izquierda[n1];
    Resultado derecha[n2];

    for (int i = 0; i <= n1; i++) {
        izquierda[i] = resultado[inicio + i];
    }

    for (int j = 0 ; j <= n2; j++) {
        derecha[j] = resultado[mitad + 1 + j];
    }
    int i = 0;
    int j = 0;
    //OJO K EMPIEZA EN INICIO
    int k = inicio;

    int cont = 0;
    while (i < n1 && j < n2) { //IZQUIERDA ES MAYOR
        if (izquierda[i].numero <= derecha[j].numero) {
            resultado[k] = izquierda[i];
            i++;
            k++;
        }else { //DERECHA ES MAYOR
            resultado[k] = derecha[j];
            k++;
            j++;
            cont++;
        }
    }
    while (i < n1) {
        resultado[k] = izquierda[i];
        k++;
        i++;
    }
    while (j < n2) {
        resultado[k] = derecha[j];
        k++;
        j++;
    }

    return cont;
}
