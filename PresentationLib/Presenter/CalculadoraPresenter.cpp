#include "CalculadoraPresenter.h"

#include <qstring.h>
#include <string>
#include "Services/ParticipanteService.h"

/*--------------------------------------------------------------------------------*/

using namespace std;

/*--------------------------------------------------------------------------------*/

TCalculadoraPresenter::TCalculadoraPresenter(
    ICalculadoraView* _view,
	TParticipanteService* _partService
) :
    view(_view),
	partService(_partService)
{
    view->Subscribe(this);
}

/*--------------------------------------------------------------------------------*/

void TCalculadoraPresenter::AdicionaParticipante(
	const QString& _nomeParticipante
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
	const QString& _nomeParticipante
)
{
	const string nomeParticipante = _nomeParticipante.toStdString().c_str();
	bool deveRemover = true;
	if (partService->ParticipanteComprouProdutos(nomeParticipante)) {
		deveRemover = view->MostraMensagemSimNao(QString("O participante tem produtos comprados.\nDeseja remover mesmo assim?"));
	}
	
	if (deveRemover) {
		partService->RemoveParticipante(nomeParticipante);
		nomesParticipantes.remove(nomeParticipante);
	}
}

/*--------------------------------------------------------------------------------*/

void TCalculadoraPresenter::CadastraParticipantes()
{
	partService->CadastraParticipantes(nomesParticipantes);

	view->LimpaTelaParticipanteProduto();
	for (const string& nomeParticipante : nomesParticipantes) {
		QString nome = QString::fromStdString(nomeParticipante);
		view->InsereParticipanteTelaProduto(nome);
	}

	view->AvancaStep(1);
}

/*--------------------------------------------------------------------------------*/

void TCalculadoraPresenter::AtualizaListaProdutos(
	const QString& _nomeParticipante
)
{
	if (!_nomeParticipante.isEmpty()) {
		view->LimpaListaProdutos();
		const string nomeParticipante = _nomeParticipante.toStdString();
		map<string, double> produtos = partService->Produtos(nomeParticipante);
		for (const pair<string, double>& pair : produtos) {
			view->InsereProduto(QString(pair.first.c_str()), pair.second);
		}
	}
}

/*--------------------------------------------------------------------------------*/

void TCalculadoraPresenter::InsereProduto(
	const QString& _nomeParticipante,
	const QString& _nomeProduto,
	const QString& _valorProduto
)
{
	const string nomeParticipante = _nomeParticipante.toStdString();
	const string nomeProduto = _nomeProduto.toStdString();
	const double valorProduto = atof(_valorProduto.toStdString().c_str());

	partService->InsereProdutoComprado(nomeParticipante, nomeProduto, valorProduto);
	AtualizaListaProdutos(_nomeParticipante);
}

/*--------------------------------------------------------------------------------*/

void TCalculadoraPresenter::RemoveProdutoComprado(
	const QString _nomeParticipante,
	const QString _nomeProduto
)
{
	const string nomeParticipante = _nomeParticipante.toStdString();
	const string nomeProduto = _nomeProduto.toStdString();
	partService->RemoveProdutoComprado(nomeParticipante, nomeProduto);
}

/*--------------------------------------------------------------------------------*/
