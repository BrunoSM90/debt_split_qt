#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "CalculadoraWrapper.h"

/*--------------------------------------------------------------------------------*/

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/*--------------------------------------------------------------------------------*/

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(
        TCalculadoraWrapper* _wrapper,
        QWidget * parent = nullptr
    );

    ~MainWindow();

private slots:

    void AdicionarParticipante();
    void RemoverParticipante();
    void AvancarButtonClick();

private:

    void Inicializa();

    void InicializaConexoes();

    Ui::MainWindow *ui;

    TCalculadoraWrapper* wrapper;
};

/*--------------------------------------------------------------------------------*/

#endif // MAINWINDOW_H
