#ifndef ICALCULADORAVIEW_H
#define ICALCULADORAVIEW_H

#include "ICalculadoraViewSubscriber.h"

#include <qvariant>

/*--------------------------------------------------------------------------------*/

class ICalculadoraView {

public:
    virtual ~ICalculadoraView() {};

    virtual void Subscribe(
        ICalculadoraViewSubscriber* subscriber
    ) = 0;

    virtual void Show() = 0;

    virtual void MostraMensagemAviso(
        QString& texto
    ) = 0;

    virtual void AdicionaParticipanteBox() = 0;

    virtual bool MostraMensagemSimNao(
        QString& texto
    ) = 0;

    virtual void AvancaStep(
        int step
    ) = 0;

    virtual void LimpaTelaParticipanteProduto() = 0;

    virtual void InsereParticipanteTelaProduto(
        const QString& nome
    ) = 0;

    virtual void InsereProduto(
        const QString& nomeProduto,
        double valorProduto
    ) = 0;
};

/*--------------------------------------------------------------------------------*/

#endif