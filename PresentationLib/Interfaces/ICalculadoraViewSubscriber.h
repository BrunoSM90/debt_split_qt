#ifndef ICALCULADORAVIEWSUBSCRIBER_H
#define ICALCULADORAVIEWSUBSCRIBER_H

#include "qstring.h"
#include "qvector.h"

/*--------------------------------------------------------------------------------*/

class ICalculadoraViewSubscriber {

public:
	virtual ~ICalculadoraViewSubscriber() {};

	virtual void AdicionaParticipante(
		const QString& _nomeParticipante
	) = 0;

	virtual void RemoveParticipante(
		const QString& _nomeParticipante
	) = 0;

	virtual void CadastraParticipantes() = 0;

	virtual void AtualizaListaProdutos(
		const QString& _nomeParticipante
	) = 0;

	virtual void InsereProduto(
		const QString& _nomeParticipante,
		const QString& _nomeProduto,
		const QString& _valorProduto
	) = 0;

	virtual void RemoveProdutoComprado(
		const QString _nomeParticipante,
		const QString _nomeProduto
	) = 0;
};

/*--------------------------------------------------------------------------------*/

#endif