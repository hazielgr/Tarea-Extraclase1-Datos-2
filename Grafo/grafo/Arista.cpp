//
// Created by haziel on 27/2/20.
//
//Codigo referencia tomado de Emmanuel L.G
#include "Arista.h"

Arista* Arista::getSiguiente() {
    return this->siguiente;
}

void Arista::setSiguiente(Arista *siguiente) {
    this->siguiente = siguiente;
}

Vertice* Arista::getVerticeAdy() {
    return this->adyacente;
}
int Arista::getPeso() {
    return this->pesoKilometros;
}
void Arista::setPeso(int peso) {
    this->pesoKilometros = peso;
}

void Arista::setVertAdy(Vertice *vertAdy) {
    this->adyacente = vertAdy;
}