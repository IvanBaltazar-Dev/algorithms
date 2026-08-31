//Fecha:  jueves 30 Octubre 2025 
//Autor: Ana Roncal 

#ifndef ARBOLBINARIOBUSQUEDA_FUNCIONESARBOLBINARIOBUSQUEDA_H
#define ARBOLBINARIOBUSQUEDA_FUNCIONESARBOLBINARIOBUSQUEDA_H

void construir(struct ArbolBinarioBusqueda &arbol) ;
bool esArbolVacio(const struct ArbolBinarioBusqueda &nodo);
bool esNodoVacio(const struct NodoArbolBinarioBusqueda *nodo);
void plantarArbolBinario(struct ArbolBinarioBusqueda &arbol, const struct ArbolBinarioBusqueda &izquierda,
               const struct ElementoArbolBinarioBusqueda &elemento, const struct ArbolBinarioBusqueda &derecha) ;
void plantarNodoArbolBinario(struct NodoArbolBinarioBusqueda *&nodo, struct NodoArbolBinarioBusqueda *izquierda,
    const struct ElementoArbolBinarioBusqueda &elemento, struct NodoArbolBinarioBusqueda *derecha);

void imprimirNodo(struct NodoArbolBinarioBusqueda *raiz);
void imprimir(const struct ArbolBinarioBusqueda &arbol);

void recorrerPreOrden(const struct ArbolBinarioBusqueda &arbol) ;
void recorrerPreOrdenRecursivo(struct NodoArbolBinarioBusqueda *nodo);
void recorrerEnOrden(const struct ArbolBinarioBusqueda &arbol) ;
void recorrerEnOrdenRecursivo(struct NodoArbolBinarioBusqueda *nodo);
void recorrerPostOrden(const struct ArbolBinarioBusqueda &arbol) ;
void recorrerPostOrdenRecursivo(struct NodoArbolBinarioBusqueda *nodo) ;

int numeroHojas(const struct ArbolBinarioBusqueda &arbol);
int numeroHojasRecursivo(struct NodoArbolBinarioBusqueda *nodo) ;
int numeroNodos(const struct ArbolBinarioBusqueda &arbol);
int numeroNodosRecursivo(struct NodoArbolBinarioBusqueda *nodo) ;
int altura(const struct ArbolBinarioBusqueda & arbol);
int alturaRecursivo(struct NodoArbolBinarioBusqueda * nodo);
int maximo(int a, int b);
bool esEquilibrado(const struct ArbolBinarioBusqueda & arbol);
bool esEquilibradoRecursivo(struct NodoArbolBinarioBusqueda * nodo);
void destruirArbolBinario(struct ArbolBinarioBusqueda & arbol);
void destruirRecursivo(struct NodoArbolBinarioBusqueda * nodo);


#endif //ARBOLBINARIOBUSQUEDA_FUNCIONESARBOLBINARIOBUSQUEDA_H