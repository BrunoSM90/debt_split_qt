#ifndef CALCULADORAPRESENTER_H
#define CALCULADORAPRESENTER_H

#include <string>
#include <list>
#include <vector>
#include "Interfaces/ICalculadoraViewSubscriber.h"
#include "Interfaces/ICalculadoraView.h"

/*--------------------------------------------------------------------------------*/

class TCalculadoraPresenter : public ICalculadoraViewSubscriber {

public:
    TCalculadoraPresenter(
        ICalculadoraView* _view
    );

    ~TCalculadoraPresenter() = default;

    void CadastraParticipantes(
        QVector<QString>* participantes
    );

private:
    ICalculadoraView* view;
};

/*--------------------------------------------------------------------------------*/

#endif