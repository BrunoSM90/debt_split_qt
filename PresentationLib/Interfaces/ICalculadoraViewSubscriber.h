#ifndef ICALCULADORAVIEWSUBSCRIBER_H
#define ICALCULADORAVIEWSUBSCRIBER_H

#include "qstring.h"
#include "qvector.h"

/*--------------------------------------------------------------------------------*/

class ICalculadoraViewSubscriber {

public:
	virtual ~ICalculadoraViewSubscriber() {};

	virtual void CadastraParticipantes(QVector<QString>* participantes) = 0;
};

/*--------------------------------------------------------------------------------*/

#endif