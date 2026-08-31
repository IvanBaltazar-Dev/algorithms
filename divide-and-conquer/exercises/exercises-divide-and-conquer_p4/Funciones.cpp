//
// Created by Administrador on 20/06/2026.
//

#include "Funciones.h"

int mayor(int a, int b) {
    if (a > b) return a;
    return b;
}
int mayorTres(int a, int b, int c) {
    return mayor(mayor(a,b),c);
}

int sumaMaxima(int *arr,int inicio,int fin,int &iniMax, int &finMax) {
    if (inicio == fin) {
        return arr[inicio];
    }
    int mitad = inicio + (fin - inicio)/2;

    int iniIzq, finIzq;
    int iniDer, finDer;
    int iniCruzado, finCruzado;

    int izquierda = sumaMaxima(arr,inicio,mitad,iniIzq, finIzq);
    int derecha = sumaMaxima(arr,mitad+1,fin,iniDer, finDer);
    int cruzada = sumaCruzada(arr,inicio, mitad,fin,iniCruzado, finCruzado);

    int result = mayorTres(izquierda, derecha, cruzada);
    if (result == izquierda) {
        iniMax = iniIzq;
        finMax = finIzq;
    }
    if (result == derecha) {
        iniMax = iniDer;
        finMax = finDer;
    }
    if (result == cruzada) {
        iniMax = iniCruzado;
        finMax = finCruzado;
    }

    return result;
}

int sumaCruzada(int *arr,int inicio,int mitad,int fin,int &iniMax,int &finMax) {
    int suma = 0;
    int mejorIzquierda = arr[mitad];
    for (int i=mitad;i>=inicio;i--) {
        suma += arr[i];
        if (suma > mejorIzquierda) {
            mejorIzquierda = suma;
            iniMax = i;
        }
    }

    suma = 0;
    int mejorDerecha = arr[mitad+1];
    for (int i=mitad+1;i<=fin;i++) {
        suma += arr[i];
        if (suma > mejorDerecha) {
            mejorDerecha = suma;
            finMax = i;
        }
    }
    return mejorIzquierda+mejorDerecha;
}