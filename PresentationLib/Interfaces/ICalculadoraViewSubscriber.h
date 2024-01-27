#ifndef ICALCULADORAVIEWSUBSCRIBER_H
#define ICALCULADORAVIEWSUBSCRIBER_H

#include "qstring.h"
#include "qvector.h"

/*--------------------------------------------------------------------------------*/

class ICalculadoraViewSubscriber {

public:
	virtual ~ICalculadoraViewSubscriber() {};

	virtual void AdicionaParticipante(QString& _nomeParticipante) = 0;

	virtual void RemoveParticipante(QString& _nomeParticipante) = 0;
};

/*--------------------------------------------------------------------------------*/

#endif