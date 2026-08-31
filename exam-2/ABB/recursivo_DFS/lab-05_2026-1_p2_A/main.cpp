#include "Funciones.h"

int main() {

    Letra arrLetras[26];

    for(int i = 0; i < 26; i++) {
        construir(arrLetras[i].arbol);
        arrLetras[i].letra = char(i+97);
    }

    llenadoArboles(arrLetras);

    imprimirFrecuencias(arrLetras);

    for(int i = 0; i < 26; i++) {
        cout<<arrLetras[i].letra<<" ";
    }
    cout<<endl;

    return 0;
}
