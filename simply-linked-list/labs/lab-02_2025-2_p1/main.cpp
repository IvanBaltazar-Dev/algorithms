//Fecha:  sábado 30 Agosto 2025 
//Autor: Ana Roncal

#include <iostream>
#include "BibliotecaLista/Lista.h"
#include "BibliotecaLista/funcionesLista.h"
#include "Funciones.h"
using namespace std;

/*
 * laboratorio 2
 * ciclo: 2025 - 2
 * pregunta 1
 */
int main(int argc, char **argv) {

    Lista l1{};
    construir(l1);

    cargarLista("datos.txt",l1);

    // imprimir(l1);

    char formacion[4][15] = {
        {"Portero"},
        {"Defensa"},
        {"Mediocampo"},
        {"Delantero"},
    };

    reordenaFormacion(l1,formacion,4);

    return 0;
}


/* ERRORES COMUNES
 * archivo.close()
 * revisar el .txt por los espacios
 * OJO:
 * anterior NO avanza porque curr ya no esta en la lista pendiente
 * anterior solo avanza si curr se queda en la lista pendiente
 */