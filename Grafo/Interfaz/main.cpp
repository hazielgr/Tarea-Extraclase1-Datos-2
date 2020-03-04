#include "mainwindow.h"
#include "../SocketServer/Client.h"
#include <QApplication>
#include <thread>
#include <unistd.h>



MainWindow* aux;
void hello();
void hello2();

int main(int argc, char *argv[])
{
    //thread hilo(hello);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    aux = &w;
    thread hilo(hello);
    a.exec();
    return 0;
}

void hello(){
    while(peticion != "exit") {
        if(aux->contador == 1){
            peticion = "1Dallas,Orlando,Florida,Manhattan";
        }
        if(aux->contador == 2){
            peticion = "2Dallas,Orlando,129-Dallas,Manhattan,238-Florida,Orlando,573-Manhattan,Florida,98";
        }
        if(aux->contador == 3){
            peticion = "3Dallas,Florida";
        }
        aux->contador = 0;
        Client *client = new Client(peticion);
        peticion = "0";
        sleep(0.1);
    }
}
