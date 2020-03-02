#include <cstdio>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(){
    int serverdf;
    serverdf = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(serverdf == -1){
        perror("Socket creatin failed\n");
        exit(0);
    }

    struct sockaddr_in server{},client{};
    server.sin_family = AF_INET;
    server.sin_port= htons(8000);
    server.sin_addr.s_addr = inet_addr("192.168.1.2");

    int b = bind(serverdf,(struct sockaddr*)&server, sizeof(server));

    if(b == -1){
        perror("Bindind failure\n");
        exit(0);
    }
    listen(serverdf,5);

    int size = sizeof(struct sockaddr);

    char snd[20], rcv[20];
    while(true){
    int clientfd = accept(serverdf, (struct sockaddr*)&client, reinterpret_cast<socklen_t *>(&size));

    if(clientfd == -1 ){
        perror("Accept error\n");
        exit(0);
    }
    printf("Connection accepted\n");

    for(;;){
        int r = recv(clientfd, rcv, sizeof(rcv),0);
        //cout<<r;
        //rcv[r] = '\0';
        cout<<rcv[0];
        cout<<rcv[1];
        printf("Msg from client is : %s\n",rcv);
        if(strcmp(rcv,"exit") == 0){
            exit(0);
        }
        printf("Enter msg to pass to client: ");
        scanf("%s",snd);
        send(clientfd,snd,strlen(snd),0);
    }
    }
}

