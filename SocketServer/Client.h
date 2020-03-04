//
// Created by haziel on 2/3/20.
//

#ifndef GRAFO_CLIENT_H
#define GRAFO_CLIENT_H

#include <iostream>
#include <QtCore/QByteArray>

using namespace std;
#endif //GRAFO_CLIENT_H

static QByteArray dmd;

class Client{
public:
    Client(string demanda, QByteArray *dmd1);
    int bandera = 0;
    int clientfd;
};

