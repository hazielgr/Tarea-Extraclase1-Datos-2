//
// Created by haziel on 27/2/20.
//

#ifndef GRAFO_ARISTA_H
#define GRAFO_ARISTA_H


#include "Vertice.h"
class Vertice;

class Arista {
public:
    Arista* getSiguiente();
    Vertice* getVerticeAdy();
    int getPeso();
    void setPeso(int peso);
    void setSiguiente(Arista* siguiente);

    void setVertAdy(Vertice* vertAdy);

private:
    Arista *siguiente;
    Vertice *adyacente;
    int pesoKilometros;


};


#endif //GRAFO_ARISTA_H
