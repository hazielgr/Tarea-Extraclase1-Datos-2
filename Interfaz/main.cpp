#include "mainwindow.h"
#include "../SocketServer/Client.h"
#include <QApplication>
#include <thread>
#include <unistd.h>


static MainWindow* aux;

void hello();

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
        QByteArray *dmd1 = &dmd;
        if(aux->contador == 0){
            aux->UpdateLabel(*dmd1);
        }
        if(aux->contador == 1){
            peticion = "1Dallas,Orlando,Florida,Manhattan";
        }
        if(aux->contador == 2){
            peticion = "2Dallas,Orlando,129-Dallas,Manhattan,238-Florida,Orlando,573-Manhattan,Florida,98";
        }
        if(aux->contador == 3){
            peticion = "3Dallas,Florida";
            aux->contador = 4;
            sleep(0.1);
        }
        aux->contador = 0;
        Client *client = new Client(peticion,dmd1);
        peticion = "0";
        sleep(0.1);
    }
}
