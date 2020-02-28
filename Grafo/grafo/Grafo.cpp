//
// Created by haziel on 27/2/20.
//

#include "Grafo.h"


Grafo::Grafo() {
    this->size = 0;
    this->first = NULL;
}

Vertice* Grafo::getVertice(string ciudad) {
    Vertice *aux = this->first;
    while(aux != NULL){
        if(aux->getCiudad() == ciudad){
            return aux;
        }
        aux = aux->getSiguiente();
    }
    return NULL;
}

void Grafo::insertVertice(string ciudad) {
    Vertice *nuevo = new Vertice();
    nuevo->setCiudad(ciudad);
    nuevo->setSiguiente(NULL);
    nuevo->setAristaAdy(NULL);

    if(this->size == 0){
        this->first = nuevo;
        this->size++;
    }
    else{
        Vertice *aux = this->first;
        while(aux->getSiguiente() != NULL){
            aux = aux->getSiguiente();
        }
        aux->setSiguiente(nuevo);
        this->size++;
    }
}

void Grafo::insertArista(Vertice *origen, Vertice *destino, int peso) {
    Arista *nueva = new Arista();
    nueva->setPeso(peso);
    nueva->setSiguiente(NULL);
    nueva->setVertAdy(NULL);

    Arista *aux;
    aux = origen->getAristaAdy();

    if(aux == NULL){
        origen->setAristaAdy(nueva);
        nueva->setVertAdy(destino);
    }
    else{
        while(aux->getSiguiente() != NULL){
            aux = aux->getSiguiente();
        }
        aux->setSiguiente(nueva);
        nueva->setVertAdy(destino);
    }
}

void Grafo::listaAdyacencia() {
    Vertice *vertAux;
    Arista *aristAux;

    vertAux = this->first;

    while(vertAux != NULL){
        cout<<vertAux->getCiudad()<<"->";
        aristAux = vertAux->getAristaAdy();

        while (aristAux != NULL){
            cout<<aristAux->getVerticeAdy()->getCiudad()<<"->";
            aristAux = aristAux->getSiguiente();
        }
        vertAux = vertAux->getSiguiente();
        cout<<endl;
    }
}

int Grafo::getSize() {
    return this->size;
}