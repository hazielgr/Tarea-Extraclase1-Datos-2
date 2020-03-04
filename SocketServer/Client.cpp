#include <cstdio>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <cstdlib>
#include "Client.h"
#include <iostream>
#include <unistd.h>
#include <thread>
#include "../Interfaz/mainwindow.h"

using namespace std;


void run(string demanda, QByteArray *dmd1);

Client::Client(string demanda, QByteArray *dmd1) {
    thread hilo(run,demanda,dmd1);
    hilo.join();
}
void run(string demand, QByteArray *dmd1){
    while(true) {
    int clientfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (clientfd == -1) {
        perror("Socket creatin failed\n");
        exit(0);
    }
    struct sockaddr_in server{};
    server.sin_family = AF_INET;
    server.sin_port = htons(8000);
    server.sin_addr.s_addr = inet_addr("192.168.0.4");
    int c = connect(clientfd, (struct sockaddr *) &server, sizeof(server));

    if (c == -1) {
        perror("Connection error\n");
        exit(0);
    }
    //printf("Connected to Server\n");

    char rcv[1000];
    char snd[1000];

    if (demand == "exit") {
        break;
    }
    else if ((demand).at(0) == '1' || (demand).at(0) == '2') {
        strcpy(snd, (demand).c_str());//copia el string en el array de char
        send(clientfd, snd, strlen(snd), 0);
        int r = recv(clientfd, rcv, sizeof(rcv), 0);
        rcv[r] = '\0';
        printf("Msg from server is : %s\n", rcv);
    }
    else if ((demand).at(0) == '3') {
        strcpy(snd, (demand).c_str());//copia el string en el array de char
        send(clientfd, snd, strlen(snd), 0);
        int r = recv(clientfd, rcv, sizeof(rcv), 0);
        rcv[r] = '\0';
        *dmd1 = rcv;
        printf("La ruta mas corta es : %s\n", rcv);
    }
    close(clientfd);
    break;
    }
}
