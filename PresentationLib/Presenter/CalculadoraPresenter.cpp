#include "CalculadoraPresenter.h"

#include "mainwindow.h"

#include <QApplication>
#include <iostream>

#include <qvector.h>
#include <qstring.h>

/*--------------------------------------------------------------------------------*/

using namespace std;

/*--------------------------------------------------------------------------------*/

TCalculadoraPresenter::TCalculadoraPresenter(
    ICalculadoraView* _view
) :
    view(_view)
{
    view->Subscribe(this);
}

/*--------------------------------------------------------------------------------*/

void TCalculadoraPresenter::CadastraParticipantes(
	QVector<QString>* participantes
)
{
	using namespace std;
	vector<string>* nomes = new vector<string>();
	for (QString nome : *participantes) {
		nomes->push_back(nome.toStdString().c_str());
	}
}

/*--------------------------------------------------------------------------------*/
