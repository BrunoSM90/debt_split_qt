#include <QApplication>

#include "Presenter/CalculadoraPresenter.h"
#include "Interfaces/ICalculadoraView.h"
#include "Interfaces/ICalculadoraViewSubscriber.h"
#include "View/mainwindow.h"

/*--------------------------------------------------------------------------------*/

int main(int argc, char* argv[])
{
    QApplication application(argc, argv);

    ICalculadoraView* view = new CalculadoraView();
    ICalculadoraViewSubscriber* presenter = new TCalculadoraPresenter(view);

    view->Show();

    return application.exec();
}

/*--------------------------------------------------------------------------------*/
