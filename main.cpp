#include <QApplication>

#include "Interfaces/ICalculadoraView.h"
#include "Interfaces/ICalculadoraViewSubscriber.h"
#include "Presenter/CalculadoraPresenter.h"
#include "Services/ParticipanteService.h"
#include "View/CalculadoraView.h"
#include "View/MainWindow.h"

/*--------------------------------------------------------------------------------*/

int main(int argc, char* argv[])
{
    QApplication application(argc, argv);

    TProdutoService* prodService = new TProdutoService();
    TParticipanteService* partService = new TParticipanteService(prodService);

    ICalculadoraView* view = new CalculadoraView();
    ICalculadoraViewSubscriber* presenter = new TCalculadoraPresenter(view, partService);

    view->Show();

    return application.exec();
}

/*--------------------------------------------------------------------------------*/
