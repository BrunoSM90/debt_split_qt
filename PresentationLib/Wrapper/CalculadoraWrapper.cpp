#include "CalculadoraWrapper.h"
#include <qvector.h>
#include <vector>
#include <qstring.h>

/*--------------------------------------------------------------------------------*/

TCalculadoraWrapper::TCalculadoraWrapper(
	TCalculadoraPresenter* _presenter
) :
	presenter(_presenter)
{

}

/*--------------------------------------------------------------------------------*/

void TCalculadoraWrapper::CadastraParticipantes(
	QVector<QString>* participantes
) 
{
	using namespace std;
	vector<string>* nomes = new vector<string>();
	for (QString nome : *participantes) {
		nomes->push_back(nome.toStdString().c_str());
	}

	presenter->CadastraParticipantes(nomes);
	
	delete participantes;
}

/*--------------------------------------------------------------------------------*/

