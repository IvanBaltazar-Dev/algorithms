#include "Funciones.h"
int main() {

    int mapa[N][M]={
        {0,0,-1,0,0,-1},
        {0,-0,0,0,0,0},
        {0,-1,0,-1,0,0},
        {0,-1,0,0,-1,0},
        {-1,0,0,0,0,0}
    };



    solucion(mapa, N, M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << setw(4)<<mapa[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}

/*Apuntes:
 * ORDEN INVERSO, SI QUEREMOS PRIORIZAR ABAJO
 * PRIMERO APILAMOS HACIA DERECHA
 * DESPUES APILAMOS HACIA ABAJO
 *
 * FINAL if( fila == N-1 && columna == M-1 )
 *
 */