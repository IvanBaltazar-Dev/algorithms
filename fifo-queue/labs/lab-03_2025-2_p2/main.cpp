#include "Funcion.h"

int main() {

    Cola cola{};
    construir(cola);

    ElementoCola elementoCola{};

    iniciar_datos(cola, "datos.txt");
    imprimir(cola);

    bool esOrdenable = false;
    esOrdenable = reordena_datos(cola);

    if (esOrdenable) {
        cout<<"Si se puede ordenar"<<endl;
    }else {
        cout<<"No se puede ordenar"<<endl;
    }

    return 0;
}
