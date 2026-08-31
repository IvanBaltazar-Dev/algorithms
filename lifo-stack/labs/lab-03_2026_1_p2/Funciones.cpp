//
// Created by aml on 16/05/2026.
//

#include "Funciones.h"

void solucion(int *arr,int n,Pila &pila) {

    int resuelto = 0;
    ElementoPila elemento{};
    //valida lo que quedo en la pila
    for (int i = 1; i <= n; i++) {
        elemento.numero = i;
        apilar(pila,elemento);
        if (arr[resuelto] == cima(pila).numero && !esPilaVacia(pila)) {
            // cout << arr[resuelto] << endl;
            elemento = desapilar(pila);
            resuelto++;
        }
        // imprimir(pila);
    }
    while (!esPilaVacia(pila)) {
        if (arr[resuelto] == cima(pila).numero) {
            elemento = desapilar(pila);
            resuelto++;
        }else {
            break;
        }
    }
    if (esPilaVacia(pila)) {
        cout<<"Se puede cumplir con lo solicitado"<<endl;
    }else {
        cout << "No se puede cumplir con lo solicitado" << endl;
    }
}
