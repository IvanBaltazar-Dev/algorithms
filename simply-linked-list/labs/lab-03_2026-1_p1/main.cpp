#include "Funcion.h"

int main() {

    Lista lista{};
    construir(lista);

    cargarDatos(lista,"datos.txt");

    cout<<"Lista de intentos fallidos: ";
    imprimir(lista);

    Lista listaSospechosos{};
    construir(listaSospechosos);

    evaluacionSospechosos(lista,listaSospechosos);
    cout<<"Lista de usuarios sospechosos: ";
    imprimir(listaSospechosos);

    //lista original depurada
    depuracionLista(lista,listaSospechosos);
    cout<<"Lista depurada: ";
    imprimir(lista);


    destruir(listaSospechosos);
    destruir(lista);

    return 0;
}