#include <cstdio>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <cstdlib>
#include "Client.h"
#include <iostream>
#include <unistd.h>
using namespace std;


Client::Client() {
    //system("clear");sencillos
    int clientfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (clientfd == -1) {
        perror("Socket creatin failed\n");
        exit(0);
    }

    struct sockaddr_in server{};

    server.sin_family = AF_INET;
    server.sin_port = htons(8000);
    server.sin_addr.s_addr = inet_addr("192.168.0.4");
    int c = connect(clientfd,(struct sockaddr*)&server, sizeof(server));
    if(c == -1){
        perror("Connection error\n");
        exit(0);
    }
    printf("Connected to Server\n");
    char rcv[1000];
    char snd[1000];
    string peticion;
    while(true) {
        cin >> peticion;
        if (peticion == "exit") {
            break;
        }
        else if (peticion.at(0) == '1' || peticion.at(0) == '2') {
            strcpy(snd, peticion.c_str());//copia el string en el array de char
            send(clientfd, snd, strlen(snd), 0);
            int r = recv(clientfd, rcv, sizeof(rcv),0);
            rcv[r] = '\0';
            printf("Msg from server is : %s\n",rcv);
        }
        else if (peticion.at(0) == '3') {
            strcpy(snd, peticion.c_str());//copia el string en el array de char
            send(clientfd, snd, strlen(snd), 0);
            int r = recv(clientfd, rcv, sizeof(rcv),0);
            rcv[r] = '\0';
            printf("La ruta mas corta es : %s\n",rcv);
        }
    }
}

int main(){
    Client *cliente = new Client;
    return 0;
}

