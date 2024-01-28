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
        QString& _nomeParticipante
    ) override;

    void RemoveParticipante(
        QString& _nomeParticipante
    ) override;

    void CadastraParticipantes();

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