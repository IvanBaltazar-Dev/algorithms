#include "Funciones.h"

using namespace std;

int main() {

    Lista l1{};
    construir(l1);

    cargarDatos(l1,"datos.txt");

    imprimir(l1);

    char ArrTipo[3]={'A','B','C'};

    reordenaLista(l1,ArrTipo,3);

    imprimir(l1);

    return 0;
}
