#ifndef ICALCULADORAVIEW_H
#define ICALCULADORAVIEW_H

#include "ICalculadoraViewSubscriber.h"

/*--------------------------------------------------------------------------------*/

class ICalculadoraView {

public:
    virtual ~ICalculadoraView() {};

    virtual void Subscribe(ICalculadoraViewSubscriber* subscriber) = 0;

    virtual void Show() = 0;
};

/*--------------------------------------------------------------------------------*/

#endif