//
// Created by haziel on 27/2/20.
//

#include "Grafo.h"
#include <stack>
#include <list>

Grafo::Grafo() {
    this->size = 0;
    this->first = NULL;
}

Vertice* Grafo::getVertice(string ciudad) {
    Vertice *aux;
    aux = this->first;
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
        Vertice *aux;
        aux = this->first;
        while(aux->getSiguiente() != NULL){
            aux = aux->getSiguiente();
        }
        aux->setSiguiente(nuevo);
        this->size++;
    }
}

void Grafo::insertArista(Vertice *origen, Vertice *destino, int peso) {
    if(this->size == 0){
        cout<<"Se debe insertar un vertice primero"<<endl;
    }
    else {
        Arista *nueva = new Arista();
        nueva->setPeso(peso);
        nueva->setSiguiente(NULL);
        nueva->setVertAdy(NULL);

        Arista *aux;
        aux = origen->getAristaAdy();

        if (aux == NULL) {
            origen->setAristaAdy(nueva);
            nueva->setVertAdy(destino);
        } else {
            while (aux->getSiguiente() != NULL) {
                aux = aux->getSiguiente();
            }
            aux->setSiguiente(nueva);
            nueva->setVertAdy(destino);
        }
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


bool comparacion(pair<Vertice *, int> a, pair<Vertice *, int> b) {
    return a.second < b.second;
}


void Grafo::rutaMinima(Vertice *origen, Vertice *destino) {

    int band, band2 = 0;
    int costoActual = 0;
    Vertice *verticeActual, *destinoActual;
    Arista *aux;
    typedef  pair<Vertice *, int> verticeCosto;
    typedef pair<Vertice *, Vertice *> verticeVertice;
    list<verticeCosto> listaCosto; //lista para guardar el vertice y el peso
    list<verticeCosto> listaOrdenada; //Lista ordenada de vertice y peso;
    stack<verticeVertice> pila; //pila para guardar pares origen-destino;
    list<verticeCosto>::iterator i, j;

    listaCosto.push_back(verticeCosto(origen,0));//por ser origen el costo es cero
    listaOrdenada.push_back(verticeCosto(origen, 0));//por ser origen el costo es cero

    while(!listaOrdenada.empty()){
        verticeActual = listaOrdenada.front().first;
        costoActual = listaOrdenada.front().second;
        listaOrdenada.pop_front();

        if(verticeActual == destino){

            band2 = 1;
            destinoActual = destino;

            while(!pila.empty()){
                cout<<destinoActual->getCiudad()<<"<-";

                while(!pila.empty() && pila.top().second != destinoActual){
                    pila.pop();
                }

                if(!pila.empty()){

                    destinoActual = pila.top().first;
                }

            }

            break;
        }

        aux = verticeActual->getAristaAdy();
        while(aux != NULL){
            band = 0;
            costoActual = costoActual + aux->getPeso();

            for(i=listaCosto.begin(); i != listaCosto.end(); i++){

                if(aux->getVerticeAdy() == i->first){

                    band = 1;
                    if(costoActual < i->second){
                        (*i).second = costoActual;

                        for(j=listaOrdenada.begin(); j!=listaOrdenada.end(); j++){

                            if(j->first == aux->getVerticeAdy()){
                                (*j).second = costoActual;
                            }
                        }

                        listaOrdenada.sort(comparacion);
                        pila.push(verticeVertice(verticeActual, aux->getVerticeAdy()));
                        costoActual = costoActual - aux->getPeso();
                    }

                }
            }

            if(band == 0){
                listaCosto.push_back(verticeCosto(aux->getVerticeAdy(),costoActual));
                listaOrdenada.push_back(verticeCosto(aux->getVerticeAdy(),costoActual));
                listaOrdenada.sort(comparacion);
                pila.push(verticeVertice(verticeActual, aux->getVerticeAdy()));
                costoActual = costoActual - aux->getPeso();
            }


            aux = aux->getSiguiente();
        }
    }
    if(band2 == 0){
        cout<<"NO SE ENCONTRO RUTA"<<endl;
    }
}