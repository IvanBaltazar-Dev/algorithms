//
// Created by Ivan Piero Baltazar on 15/05/2026.
//

#include "Funciones.h"

void solucion(int matrizReceptor[N][M],int n,int m) {
    Pila pila{};
    construir(pila);
    ElementoPila elementoPila{};
    for (int i = 6; i >= 0; i--) {
        elementoPila.numero = i;
        apilar(pila,elementoPila);
    }
    // imprimir(pila);
    while (pila.longitud > 1) {
        ElementoPila candidato_a = desapilar(pila);
        ElementoPila candidato_b = desapilar(pila);
        //CASO CANDIDATO_A NO ENVIA CANDIDATO_B GANA CANDIDATO_B
        if (matrizReceptor[candidato_a.numero][candidato_b.numero] == 0) {
            apilar(pila,candidato_b);
        }
        //CASO CANDIDATO_B NO ENVIA CANDIDATO_A GANA CANDIDATO_A
        else if (matrizReceptor[candidato_b.numero][candidato_a.numero] == 0) {
            apilar(pila,candidato_a);
        }
        // imprimir(pila);
    }

    if (esPilaVacia(pila)) {
        cout << "SkyNerd no está en la red" << endl;
    }else {
        ElementoPila candidato = desapilar(pila);
        int cant_paquetes = 0;
        bool validacion = true;
        //VALIDACION DE COLUMNA
        for (int i = 0; i < n; i++) {
            if (matrizReceptor[candidato.numero][i] == 0 && candidato.numero != i) {
                validacion = false;
            }
            if (matrizReceptor[candidato.numero][i] > cant_paquetes) {
                cant_paquetes = matrizReceptor[candidato.numero][i];
            }
        }
        //VALIDACION DE FILA
        for (int i = 0; i < n; i++) {
            if (matrizReceptor[i][candidato.numero] != 0 && candidato.numero != i ) {
                validacion = false;
            }
        }
        if (validacion) {
            cout << "SkyNerd ha sido detectado en el servidor: " << candidato.numero+1 << endl;
            cout << "Maximo de paquetes enviados por SkyNerd: " << cant_paquetes << endl;
        }
    }
}