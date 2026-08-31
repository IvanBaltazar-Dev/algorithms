#include "EstructurasAdicionales/Letra.h"
#include "Functions/Funciones.h"

int main() {

    Letra letras[26]{};
    for (int i = 0; i < 26; i++) {
        construir(letras[i].arbol);
        letras[i].letra = char(97+i);
    }

    for (int i = 0; i < 26; i++) {
        cout << letras[i].letra << " ";
    }
    cout << endl;

    procesarTexto(letras,26);

    imprimirLetras(letras,26);
    return 0;
}
