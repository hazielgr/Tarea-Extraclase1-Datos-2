//
// Created by haziel on 27/2/20.
//

#ifndef GRAFO_VERTICE_H
#define GRAFO_VERTICE_H
#include "Arista.h"
#include <iostream>

using namespace std;

class Arista;

class Vertice {
public:
    string getCiudad();
    void setCiudad(string ciudad);

    Vertice* getSiguiente();
    void setSiguiente(Vertice*);

    Arista* getAristaAdy();
    void setAristaAdy(Arista* aristaAdy);
private:
    Vertice *siguiente;
    Arista *adyacente;
    string ciudad;
};


#endif //GRAFO_VERTICE_H
