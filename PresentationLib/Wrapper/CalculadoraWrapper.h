#ifndef CALCULADORAWRAPPER_H
#define CALCULADORAWRAPPER_H

#include <string>
#include <list>
#include <CalculadoraPresenter.h>

#include <qvector.h>
#include <qstring.h>

/*--------------------------------------------------------------------------------*/

class TParticipante;

/*--------------------------------------------------------------------------------*/

class TCalculadoraWrapper {

public:
    TCalculadoraWrapper(
        TCalculadoraPresenter* _presenter
    );

    TCalculadoraWrapper() = delete;

    ~TCalculadoraWrapper() = default;

    void CadastraParticipantes(
        QVector<QString>* participantes
    );

private:
    TCalculadoraPresenter* presenter;
};

#endif