#include "CalculadoraPresenter.h"

#include "mainwindow.h"

#include <QApplication>
#include <iostream>

/*--------------------------------------------------------------------------------*/

using namespace std;

/*--------------------------------------------------------------------------------*/

TCalculadoraPresenter::TCalculadoraPresenter()
{
}

/*--------------------------------------------------------------------------------*/

void TCalculadoraPresenter::CadastraParticipantes(
    vector<string>* participantes
)
{
    for (string nome : *participantes) {
        cout << nome << endl;
    }
}

/*--------------------------------------------------------------------------------*/

int TCalculadoraPresenter::ShowWindow(
    int argc,
    char* argv[]
) 
{
    QApplication a(argc, argv);

    MainWindow w(new TCalculadoraWrapper(this));
    w.show();

    return a.exec();
}

/*--------------------------------------------------------------------------------*/
