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



int main() {
    //system("clear");
    int clientfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (clientfd == -1) {
        perror("Socket creatin failed\n");
        exit(0);
    }

    struct sockaddr_in server{};

    server.sin_family = AF_INET;
    server.sin_port = htons(8000);
    server.sin_addr.s_addr = inet_addr("192.168.1.2");
    int c = connect(clientfd,(struct sockaddr*)&server, sizeof(server));

    if(c == -1){
        perror("Connection error\n");
        exit(0);
    }
    printf("Connected to Server\n");
    char snd[20],rcv[20];

    string prueba;

    while(true){

        printf("Enter msg to pass to server: ");

        //cin>>prueba;
        //cout<<prueba;

        scanf("%s",snd);
        send(clientfd,snd,strlen(snd),0);
        if(strcmp(snd,"exit") == 0){
            break;
        }
        int r = recv(clientfd, rcv, sizeof(rcv),0);
        rcv[r] = '\0';
        printf("Msg from server is : %s\n",rcv);

    }

}
