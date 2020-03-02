#include <cstdio>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <cstdlib>
#include <unistd.h>
#include "Server.h"
#include "../grafo/Grafo.h"
#include <iostream>
#include <sstream>

using namespace std;
list<string> serializador(string str);
Grafo * agregarVertices(list<string> lista);
string listaRuta(list<string> lista);
void agregarAristas(string str, Grafo *graph);
list<string> serialRutaMin(string str, Grafo grafo);

Server::Server() {

    int serverdf;
    serverdf = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(serverdf == -1){
        perror("Socket creatin failed\n");
        exit(0);
    }

    struct sockaddr_in server{},client{};
    server.sin_family = AF_INET;
    server.sin_port= htons(8000);
    server.sin_addr.s_addr = inet_addr("192.168.0.4");

    int b = bind(serverdf,(struct sockaddr*)&server, sizeof(server));

    if(b == -1){
        perror("Bindind failure\n");
        exit(0);
    }
    listen(serverdf,5);

    int size = sizeof(struct sockaddr);

    char snd[500],rcv[500];
    Grafo *graph;
    string respuesta;
    while(true){
        int clientfd = accept(serverdf, (struct sockaddr*)&client, reinterpret_cast<socklen_t *>(&size));
        if(clientfd == -1 ){
            perror("Accept error\n");
            exit(0);
        }
        printf("Connection accepted\n");

        for(;;){
            int r = recv(clientfd, rcv, sizeof(rcv),0);
            rcv[r] = '\0';

            if(rcv[0]=='1'){
                respuesta = "Grafo Creado Correctamente";
                strcpy(snd,respuesta.c_str());
                graph = agregarVertices(serializador(rcv));
                send(clientfd,snd,strlen(snd),0);
            }

            else if(rcv[0]=='2'){
                respuesta = "Aristas Agregadas Correctamente";
                strcpy(snd,respuesta.c_str());
                agregarAristas(rcv,graph);
                send(clientfd,snd,strlen(snd),0);
            }
            else if(rcv[0]=='3'){
                respuesta = listaRuta(serialRutaMin(rcv,*graph));
                strcpy(snd,respuesta.c_str());
                send(clientfd,snd,strlen(snd),0);
            }
            else if(rcv[0]=='4'){
                break;
            }
            sleep(0.01);
        }
    }
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

Grafo * agregarVertices(list<string> lista) {
    Grafo *grafo1 = new Grafo();
    list<string> lista1 = lista;
    while (lista1.size() != 0) {
        grafo1->insertVertice(lista1.begin()->c_str());
        lista1.pop_front();
    }
    return grafo1;
}

int main(){
    Server *servidor = new Server();
    return 0;
}

void agregarAristas(string str, Grafo *graph){
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
                graph->insertArista(graph->getVertice(origen),graph->getVertice(destino),peso);
                destino = "";
                pes = "";
                origen = "";
                contador=0;
            }
        }
        else if(contador==3){
            stringstream geek(pes);
            geek>>peso;
            graph->insertArista(graph->getVertice(origen),graph->getVertice(destino),peso);
            destino = "";
            pes = "";
            origen = "";
            contador=0;
        }
    }

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


list<string> serialRutaMin(string str, Grafo grafo){
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
