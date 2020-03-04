#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <iostream>
#include <QMainWindow>



using namespace std;
static string peticion = "0";

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int contador =0;
    string vertices;
    string aristas;
    string rutaCorta;
    void UpdateLabel(const QString text);
private slots:
    void on_MainWindow_iconSizeChanged(const QSize &iconSize);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();



private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
