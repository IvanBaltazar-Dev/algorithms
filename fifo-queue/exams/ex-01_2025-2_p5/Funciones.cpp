//
// Created by Ivan Piero Baltazar on 15/05/2026.
//

#include "Funciones.h"

#include <cstring>

void solucion(Cola &cola,const char* nombre) {
     ifstream arch(nombre, ios::in);
     if (!arch.is_open()) {
          cout << "Error al abrir el archivo " << nombre << endl;
          exit(1);
     }
     ofstream archRep("salida.txt", ios::out);
     if (!archRep.is_open()) {
          cout << "Error al abrir el archivo de reporte" << endl;
          exit(1);
     }

     char buffer[20]{};
     ElementoCola elemento{};
     NodoCola* last1 = nullptr; // Siempre inicializar los punteros en nullptr
     int cant_atencion;

     // El bucle lee directamente la palabra del comando.
     // Controla el fin de archivo (EOF) de forma automática y segura.
     while (arch >> buffer) {

          if (strcmp(buffer, "llegada") == 0) { // LLEGADA (ENCOLAR)
               arch >> elemento.codigo;         // Lee el código entero
               arch >> buffer;                  // Lee "preferente" o "regular" ignorando el espacio anterior

               if (strcmp(buffer, "preferente") == 0) {
                    elemento.tipo = 1;
               } else if (strcmp(buffer, "regular") == 0) {
                    elemento.tipo = 2;
               }
               operacionLlegada(cola, elemento, last1);
          }
          else if (strcmp(buffer, "atender") == 0) { // ATENDER (DESENCOLAR)
               arch >> cant_atencion;                // Lee la cantidad directamente
               operacionAtencion(cola, last1, archRep, cant_atencion);
          }
          else if (strcmp(buffer, "imprimir") == 0) { // IMPRIMIR
               operacionImprime(cola, archRep);
          }
     }

     arch.close();
     archRep.close();
};
void operacionAtencion(Cola &cola, NodoCola* &last1, ofstream &archRep, int cant_atencion) {
     ElementoCola atendido{};

     for (int i = 0; i < cant_atencion; i++) {
          //CASO 1 COLA VACIA
          if (esColaVacia(cola)) {
               cout << "No se puede desencolar cola vacia" << endl;
          } else {
               if (last1 != nullptr) {
                    if (last1->siguiente != nullptr && last1->siguiente->elemento.tipo == 2) {
                         last1 = nullptr;
                    }
               }
               atendido = desencolar(cola);


               archRep << "Atendido: " << atendido.codigo << " (" << (atendido.tipo == 1 ? "P1)" : "P2)") << endl;
               cout << "Atendido: " << atendido.codigo << " (" << (atendido.tipo == 1 ? "P1)" : "P2)") << endl;
          }
     }
}
void operacionLlegada(Cola & cola, ElementoCola elemento, NodoCola * &last1) {
     if (esColaVacia(cola)) {
          //CASO 1: COLA VACIA + P1 (ACTUALIZA LAST1)
          if (esColaVacia(cola) && elemento.tipo==1) {
               encolar(cola,elemento);
               last1 = cola.inicio;
               //CASO 2: COLA VACIA + P2 (NO ACTUALIZA LAST1)
          }else if(esColaVacia(cola) && elemento.tipo==2) {
               encolar(cola,elemento);
          }else {
               cout<<"NINGUN CASO"<<endl;
          }
     }else {
          //CASO 3: COLA CON P1 Y CON P2 + P1 (ANADE ENTRE SECCIONES, ACTUALIZA LAST1)
          if (last1 != nullptr && elemento.tipo==1 ) {
               encolar(cola,elemento,last1);
          }
          //CASO 4: COLA CON P1 Y SIN P2 + P1 (ANADE AL FINAL, ACTUALIZA LAST1)
          else if (elemento.tipo==1 && last1 == cola.fin) {
               encolar(cola,elemento);
               last1 = cola.fin;
          }
          //CASO 5: COLA SIN P1 Y CON P2 + P1 (ANADE AL INICIO, ACTUALIZA LAST1)
          else if (elemento.tipo==1 && last1 == nullptr) {
               NodoCola *nuevo;
               nuevo = new NodoCola{};
               nuevo->elemento = elemento;

               //CONEXION
               nuevo->siguiente = cola.inicio;
               cola.inicio = nuevo;
               last1 = cola.inicio;
          }
          //CASO 5: COLA CON P1 Y SIN P2 + P2 (ANADE AL FINAL, NO ACTUALIZA LAST1)
          else if (elemento.tipo==2 && last1 == cola.fin) {
               encolar(cola,elemento);
          }
          //CASO 6: COLA CON P1 Y CON P2 + P2 (ANADE AL FINAL, NO ACTUALIZA LAST1)
          else if (elemento.tipo==2) {
               encolar(cola,elemento);
          }else {
               cout<<"NINGUN CASO"<<endl;
          }
     }
}

void encolar(Cola &cola, ElementoCola elemento, NodoCola *last) {
     struct NodoCola *nuevo;
     nuevo = new NodoCola{};
     nuevo->elemento = elemento;
     if(esColaVacia(cola)){
          cout<<"NO SE PUDO INSERTAR COLA VACIA"<<endl;
          exit(1);
     }
     else {
          //CONEXION
          nuevo->siguiente = last->siguiente;
          //ACTUALIZACION
          last->siguiente = nuevo;
     }
     cola.longitud++;
}

void operacionImprime(const Cola cola,ofstream &archRep) {
     cout<<"Estado: ";
     imprimir(cola,1);
     imprimir(cola,2);
     cout<<endl;
     archRep<<"Estado: ";
     imprimir(cola,1,archRep);
     imprimir(cola,2,archRep);
     archRep<<endl;

}

void imprimir(const struct Cola & colaTAD, int prioridad,ofstream &archRep) {
     if (esColaVacia(colaTAD)) {
          archRep << "[P"<<prioridad<<":]";
     } else {
          struct NodoCola * recorrido = colaTAD.inicio;
          int estaImprimiendoLaCabeza = 1;
          archRep << "[P"<<prioridad<<": ";
          while (recorrido != nullptr) {
               if (recorrido->elemento.tipo == prioridad)
                    break;

               recorrido = recorrido->siguiente;
          }
          while (recorrido != nullptr && recorrido->elemento.tipo == prioridad) {
               /*Este artificio coloca las comas despues del inicio*/
               if ( not estaImprimiendoLaCabeza)
                    archRep << ", ";
               estaImprimiendoLaCabeza = 0;
               archRep << recorrido->elemento.codigo;
               recorrido = recorrido->siguiente;
          }
          archRep << "]";
     }
}

void imprimir(const struct Cola & colaTAD, int prioridad) {
     if (esColaVacia(colaTAD)) {
          cout << "[P"<<prioridad<<":]";
     } else {
          struct NodoCola * recorrido = colaTAD.inicio;
          int estaImprimiendoLaCabeza = 1;
          cout << "[P"<<prioridad<<": ";
          while (recorrido != nullptr) {
               if (recorrido->elemento.tipo == prioridad)
                    break;

               recorrido = recorrido->siguiente;
          }
          while (recorrido != nullptr && recorrido->elemento.tipo == prioridad) {
               /*Este artificio coloca las comas despues del inicio*/
               if ( not estaImprimiendoLaCabeza)
                    cout << ", ";
               estaImprimiendoLaCabeza = 0;
               cout << recorrido->elemento.codigo;
               recorrido = recorrido->siguiente;
          }
          cout << "]";
     }
}