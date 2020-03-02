
#include <iostream>

#include <list>
#include <sstream>
#include "Grafo.h"

using namespace std;

void agregarAristas(string str, Grafo graph);
string listaRuta(list<string> lista);
Grafo * agregarVertices(list<string> lista);
list<string> serializador(string str);
list<string> serializador2(string str, Grafo grafo);
int main(int argc,char* argv[]){

    Grafo *graph1;

    string str = "1Haziel,Mario,Rovira";
    string str2 = "2Haziel,Mario,2-Mario,Rovira,5-Haziel,Rovira,34-Rovira,Haziel,56-Mario,Haziel,87-Rovira,Mario,98";
    graph1 = agregarVertices(serializador(str));


    agregarAristas(str2,*graph1);
    //graph1->listaAdyacencia();

    string str3 = "3Haziel,Rovira";


    cout <<listaRuta(serializador2(str3,*graph1));


    //cout<<agregarVertices(graph->rutaMinima(graph->getVertice("New York"), graph->getVertice("Manhattan")));

    //string hola = "hola";
    //hola.append(1,'2');
    //cout<<hola.size();

    return 0;
}

string listaRuta(list<string> lista){
    list<string> lista1 = lista;
    string ruta;

    while(lista1.size() != 0){
        ruta += lista1.begin()->c_str();
        lista1.pop_front();
    }

    ruta.erase(ruta.size()-2);
    return ruta;
}

void agregarAristas(string str, Grafo graph){
    string string1 = str;
    string origen,destino,pes;
    int i = 1;
    int contador = 0;
    int peso;
    while(i<str.size()){
        if(contador == 0){
            origen += str.at(i);
            i++;
            if(str.at(i) == ','){
                contador=1;
                i++;
            }
        }
        else if(contador == 1){
            destino += str.at(i);
            i++;
            if(str.at(i) == ','){
                contador=2;
                i++;
            }
        }
        else if(contador == 2){
            pes += str.at(i);
            i++;
            if(i<str.size() && str.at(i) == '-'){
                if(i==str.size()-1){
                    contador=3;
                }
                else{
                    contador=3;
                    i++;
                }
            }
            if(i==str.size()){
                stringstream geek(pes);
                geek>>peso;
                graph.insertArista(graph.getVertice(origen),graph.getVertice(destino),peso);
                destino = "";
                pes = "";
                origen = "";
                contador=0;
            }
        }
        else if(contador==3){
            stringstream geek(pes);
            geek>>peso;
            graph.insertArista(graph.getVertice(origen),graph.getVertice(destino),peso);
            destino = "";
            pes = "";
            origen = "";
            contador=0;
        }
    }

}

Grafo * agregarVertices(list<string> lista){
    Grafo *grafo1= new Grafo();
    list<string> lista1 = lista;
    while(lista1.size()!= 0){
        grafo1->insertVertice(lista1.begin()->c_str());
        lista1.pop_front();
    }
    return grafo1;
}

list<string> serializador(string str){
    list<string> lista;
    string comp;
    int i = 1;
    while(i<str.size()){

        if(i==str.size()-1){
            comp += str.at(i);
            lista.push_back(comp);
            i++;
        }
        else if(str.at(i) == ','){
            lista.push_back(comp);
            i++;
            comp = str.at(i);
            i++;
        }

        else{
            comp += str.at(i);
            i++;
        }
    }
    return lista;
}





list<string> serializador2(string str, Grafo grafo){
    string origen,destino;
    int i = 1, contador =0;
    while(i<str.size()) {
        if(contador==0){
            origen += str.at(i);
            i++;
        }
        if(str.at(i)==','){
            i++;
            contador=1;
        }
        if(contador==1){
            destino += str.at(i);
            i++;
        }
    }
    return grafo.rutaMinima(grafo.getVertice(origen),grafo.getVertice(destino));
}
