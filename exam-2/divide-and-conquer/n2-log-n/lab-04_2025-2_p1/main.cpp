#include "FuncionesAuxiliares/Funciones.h"

#include "EstructurasAuxiliares/Resultado.h"

int main() {

    string caja[][N] = {
        {"",       "Blanco", "Isabel", "Rojo",     "Rojo",     "Isabel"},
        {"Bruno",  "",       "Blanco", "Amarillo", "Bruno",    "Blanco"},
        {"Isabel", "Isabel", "Blanco", "Agata",    "Agata",    "Blanco"},
        {"Isabel", "Negro",  "",       "Isabel",   "Rojo",     "Negro"},
        {"Bruno",  "Amarillo", "Rojo", "Bruno",    "Amarillo", "Rojo"},
        {"Agata",  "",       "Isabel", "Negro",    "Isabel",   "Negro"}
    };

    cout << "Mutaciones faltantes por fila:" << endl;

    for (int i = 0; i < N; i++) {
        string faltante = encontrarFaltante(caja[i],N);
        cout << "Fila "<< i <<": "<<faltante<<endl;
    }
    return 0;
}
