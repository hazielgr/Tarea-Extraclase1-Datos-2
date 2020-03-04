//
// Created by haziel on 27/2/20.
//
//Codigo referencia tomado de Emmanuel L.G


#include "Vertice.h"
Vertice* Vertice::getSiguiente() {
    return this->siguiente;
}

string Vertice::getCiudad() {
    return this->ciudad;
}

void Vertice::setSiguiente(Vertice *sigueinte) {
    this->siguiente = sigueinte;
}

Arista* Vertice::getAristaAdy() {
    return this->adyacente;
}

void Vertice::setCiudad(string ciudad) {
    this->ciudad = ciudad;
}

void Vertice::setAristaAdy(Arista* aristaAdy) {
    this->adyacente = aristaAdy;
}