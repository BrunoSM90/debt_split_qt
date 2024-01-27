#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/*--------------------------------------------------------------------------------*/

#include <QMainWindow>

#include "Interfaces/ICalculadoraView.h"

/*--------------------------------------------------------------------------------*/

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

enum PAGESINDEX {
    PARTICIPANTES_PAGE = 0,
    PRODUTOS_PAGE = 1,
    CONSUMO_PAGE = 2,
    CALCULO_PAGE = 3
};

/*--------------------------------------------------------------------------------*/

class CalculadoraView : public QMainWindow, public ICalculadoraView
{
    Q_OBJECT

public:
    CalculadoraView(QWidget *parent = nullptr);

    ~CalculadoraView();

    void Show() override;

    void Subscribe(
        ICalculadoraViewSubscriber* _subscriber
    ) override;

    void MostraMensagemAviso(
        QString& texto
    );

    void AdicionaParticipanteBox() override;

private slots:

    void AdicionaParticipante();
    void RemoveParticipante();

    void AvancarStep1();
    void AvancarStep2();
    void AvancarStep3();

    void VoltarStep1();
    void VoltarStep2();


private:
    void Inicializa();

    void InicializaConexoes();

    Ui::MainWindow *ui;

    ICalculadoraViewSubscriber* subscriber;
};

/*--------------------------------------------------------------------------------*/

#endif // MAINWINDOW_H
