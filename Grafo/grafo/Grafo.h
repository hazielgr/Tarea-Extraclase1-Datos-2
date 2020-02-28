//
// Created by haziel on 27/2/20.
//

#ifndef GRAFO_GRAFO_H
#define GRAFO_GRAFO_H


#include "Vertice.h"



class Grafo {
public:
    Grafo();
    int getSize();
    void printGrafo();
    void insertArista(Vertice *origen, Vertice *destino, int peso);
    void insertVertice(string ciudad);
    void listaAdyacencia();
    Vertice* getVertice(string ciudad);
private:
    Vertice *first;
    int size;
};

#endif //GRAFO_GRAFO_H