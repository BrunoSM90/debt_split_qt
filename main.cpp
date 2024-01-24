
#include "Presenter/CalculadoraPresenter.h"

/*--------------------------------------------------------------------------------*/

int Inicializa(int argc, char* argv[]);

/*--------------------------------------------------------------------------------*/

int main(int argc, char* argv[])
{
    return Inicializa(argc, argv);
}

/*--------------------------------------------------------------------------------*/

int Inicializa(int argc, char* argv[])
{
    //vai receber injeção dos serviços
    auto presenter = new TCalculadoraPresenter();

    return presenter->ShowWindow(argc, argv);
}

/*--------------------------------------------------------------------------------*/
