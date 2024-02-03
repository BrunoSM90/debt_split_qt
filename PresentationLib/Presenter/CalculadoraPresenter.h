#ifndef CALCULADORAPRESENTER_H
#define CALCULADORAPRESENTER_H

#include <string>
#include <list>
#include "Interfaces/ICalculadoraViewSubscriber.h"
#include "Interfaces/ICalculadoraView.h"

/*--------------------------------------------------------------------------------*/

class TParticipanteService;

/*--------------------------------------------------------------------------------*/

class TCalculadoraPresenter : public ICalculadoraViewSubscriber {

public:
    TCalculadoraPresenter(
        ICalculadoraView* _view,
        TParticipanteService* _partService
    );

    ~TCalculadoraPresenter() = default;

    void AdicionaParticipante(
        const QString& _nomeParticipante
    ) override;

    void RemoveParticipante(
        const QString& _nomeParticipante
    ) override;

    void CadastraParticipantes() override;

    void AtualizaListaProdutos(
        const QString& _nomeParticipante
    ) override;

    void InsereProduto(
        const QString& _nomeParticipante,
        const QString& _nomeProduto,
        const QString& _valor
    ) override;

    void RemoveProdutoComprado(
        const QString _nomeParticipante,
        const QString _nomeProduto
    ) override;

private:
    bool NomeJaConsta(
        std::string _nomeParticipante
    ) const;

    std::list<std::string> nomesParticipantes;

    ICalculadoraView* view;

    TParticipanteService* partService;
};

/*--------------------------------------------------------------------------------*/

#endif