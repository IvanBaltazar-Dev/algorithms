#include "Funciones.h"

using namespace std;

int main() {
    Lista l1{};
    construir(l1);

    cargarDatos(l1,"datos.txt");

    imprimir(l1);

    char tipoOrden[][10]={
        {"Par"},
        {"Impar"}
    };
    reordenaLista(l1,tipoOrden,2);
    cout << endl << endl;
    imprimir(l1);

    return 0;
}
