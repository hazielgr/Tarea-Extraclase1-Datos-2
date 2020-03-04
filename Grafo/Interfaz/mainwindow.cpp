#include "mainwindow.h"
#include "/home/haziel/build-Interfaz-Desktop_Qt_5_14_1_GCC_64bit-Debug/Interfaz_autogen/include/ui_mainwindow.h"
#include <istream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_MainWindow_iconSizeChanged(const QSize &iconSize)
{

}

void MainWindow::on_pushButton_clicked()
{
    //this->vertices = "1Dallas,Orlando,Florida,Manhattan";
    contador = 1;

}

void MainWindow::on_pushButton_2_clicked()
{
    //this->aristas = "2Dallas,Orlando,129-Dallas,Manhattan,238-Florida,Orlando,573-Manhattan,Florida,98";
    contador = 2;
}

void MainWindow::on_pushButton_3_clicked()
{
    contador = 3;
}

string obtenerString(string srt){
    return srt;
}
