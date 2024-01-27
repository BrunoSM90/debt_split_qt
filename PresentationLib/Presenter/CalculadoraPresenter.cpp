#include "CalculadoraPresenter.h"

#include <qstring.h>
#include <string>

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

void TCalculadoraPresenter::AdicionaParticipante(
	QString& _nomeParticipante
)
{
	string nomeParticipante = _nomeParticipante.toStdString().c_str();
	if (nomeParticipante.empty()) {
		view->MostraMensagemAviso(QString("O participante deve ter um nome válido."));
		return;
	}
	else if (NomeJaConsta(nomeParticipante)) {
		view->MostraMensagemAviso(QString("O participante já consta na lista."));
		return;
	}

	nomesParticipantes.push_back(nomeParticipante);
	view->AdicionaParticipanteBox();
}

/*--------------------------------------------------------------------------------*/

bool TCalculadoraPresenter::NomeJaConsta(
	string _nomeParticipante
) const
{
	if (nomesParticipantes.size() == 0) {
		return false;
	}

	auto compare = [](char a, char b) {
		return std::tolower(static_cast<unsigned char>(a)) == 
			std::tolower(static_cast<unsigned char>(b));
	};

	for (const string& nome : nomesParticipantes) {
		if (_nomeParticipante.size() && nome.size() &&
			std::equal(_nomeParticipante.begin(), _nomeParticipante.end(),
				nome.begin(), nome.end(), compare)) {
			return true;
		}
	}

	return false;
}

/*--------------------------------------------------------------------------------*/

void TCalculadoraPresenter::RemoveParticipante(
	QString& _nomeParticipante
)
{
	using namespace std;
	const string nomeParticipante = _nomeParticipante.toStdString().c_str();
	nomesParticipantes.remove(nomeParticipante);
}

/*--------------------------------------------------------------------------------*/
