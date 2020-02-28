
#include <iostream>
#include "Grafo.h"

using namespace std;
class Arista;
class Vertice;
class Grafo;
int main(int argc,char* argv[]){



    Grafo *grafo = new Grafo();





    grafo->insertVertice("New York");


    grafo->insertVertice("Manhattan");
    grafo->insertVertice("Haziel");

    grafo->insertArista(grafo->getVertice("New York"),grafo->getVertice("Manhattan"),120);

    grafo->insertArista(grafo->getVertice("New York"),grafo->getVertice("Haziel"),120);

    grafo->insertArista(grafo->getVertice("Manhattan"),grafo->getVertice("Haziel"),30);

    grafo->insertArista(grafo->getVertice("Haziel"),grafo->getVertice("New York"),60);

    grafo->listaAdyacencia();

    return 0;
}