//
// Created by haziel on 27/2/20.
////Codigo referencia tomado de Emmanuel L.G

#ifndef GRAFO_GRAFO_H
#define GRAFO_GRAFO_H

#include <list>
#include "Vertice.h"



class Grafo {
public:
    Grafo();
    int getSize();
    void insertArista(Vertice *origen, Vertice *destino, int peso);
    void insertVertice(string ciudad);
    void listaAdyacencia();
    Vertice* getVertice(string ciudad);
    list<string> rutaMinima(Vertice *origen, Vertice *destino);
private:
    Vertice *first;
    int size;
};

#endif //GRAFO_GRAFO_H