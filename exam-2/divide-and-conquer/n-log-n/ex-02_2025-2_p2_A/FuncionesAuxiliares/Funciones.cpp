//
// Created by Ivan Piero Baltazar on 10/07/2026.
//

#include "Funciones.h"
int resolverRotacion(Resultado datos[],int inicio,int fin) {
    if (inicio == fin) return inicio;

    int mitad = inicio + (fin - inicio)/2;

    if (datos[mitad].idActividad <= datos[fin].idActividad) {
        return resolverRotacion(datos,inicio,mitad);
    }else {
        return resolverRotacion(datos,mitad+1,fin);
    }
}

void mergesort(Resultado datos[],int inicio,int fin){
    if (inicio >= fin) return;

    int mitad = inicio + (fin - inicio)/2;

    mergesort(datos,inicio,mitad);
    mergesort(datos,mitad+1,fin);

    merge(datos,inicio,mitad,fin);
}

void merge(Resultado datos[],int inicio,int mitad,int fin) {
    int n1 = mitad - inicio + 1;
    int n2 = fin - (mitad+1)-1;

    Resultado izquierda[n1];
    Resultado derecha[n2];

    for (int i=0;i<n1;i++) {
        izquierda[i] = datos[inicio + i];
    }
    for (int j=0;j<n2;j++) {
        derecha[j] = datos[mitad + 1 + j];
    }
    int i = 0;
    int j = 0;
    int k = inicio;

    while (i < n1 && j < n2) {
        if (izquierda[i].idActividad == derecha[j].idActividad) {
            datos[k] = izquierda[i];
            i++;
            j++;
            k++;
        }else if (izquierda[i].idActividad < derecha[j].idActividad) {
            datos[k] = izquierda[i];
            i++;
            k++;
        }else {
            datos[k] = derecha[j];
            j++;
            k++;
        }
    }
    while (i < n1) {
        datos[k] = izquierda[i];
        i++;
        k++;
    }
    while (j < n2) {
        datos[k] = derecha[j];
        j++;
        k++;
    }
}
int mayor(int izquierda,int derecha,int cruzado) {
    int result = izquierda;
    if (derecha >= result) {
        result = derecha;
    }
    if (cruzado >= result) {
        result = cruzado;
    }
    return result;
}
int conteo(Resultado datos[],int inicio,int fin) {
    if (inicio >= fin) {
        int result = datos[inicio].riesgo;
        return result;
    }

    int mitad = inicio + (fin - inicio)/2;

    int izquierda = conteo(datos,inicio,mitad);
    int derecha = conteo(datos,mitad+1,fin);
    int cruzado = conteoCruzado(datos,inicio,mitad,fin);

    return mayor(izquierda,derecha,cruzado);
}

int conteoCruzado(Resultado datos[],int inicio,int mitad, int fin) {
    int inicioIzq = mitad;
    int finIzq = inicio;
    int sumaIzquierda = 0;

    int suma = 0;
    for (int i = inicioIzq; i >= finIzq; i--) {
        suma += datos[i].riesgo;
        if (suma > sumaIzquierda) {
            sumaIzquierda = suma;
        }
    }

    suma = 0;
    int inicioDer = mitad+1;
    int finDer = fin;
    int sumaDer = 0;
    for (int j = inicioDer; j <= finDer; j++) {
        suma += datos[j].riesgo;
        if (suma > sumaDer) {
            sumaDer = suma;
        }
    }

    int result = sumaIzquierda + sumaDer;
    return result;
}