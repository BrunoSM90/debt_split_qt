#ifndef CALCULADORAVIEW_H
#define CALCULADORAVIEW_H

/*--------------------------------------------------------------------------------*/

#include <QWidget>

#include "Interfaces/ICalculadoraView.h"

/*--------------------------------------------------------------------------------*/

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

enum EPAGESINDEX {
    PARTICIPANTES_PAGE = 0,
    PRODUTOS_PAGE = 1,
    CONSUMO_PAGE = 2,
    CALCULO_PAGE = 3
};

/*--------------------------------------------------------------------------------*/

class CalculadoraView : public QWidget, public ICalculadoraView
{
    Q_OBJECT

public:
    CalculadoraView(
        QWidget *parent = nullptr
    );

    ~CalculadoraView();

    void Show() override;

    void Subscribe(
        ICalculadoraViewSubscriber* _subscriber
    ) override;

    void AvancaStep(
        int step
    ) override;

    void AdicionaParticipanteBox() override;

    void InsereParticipanteTelaProduto(
        const QString& nome
    ) override;

    bool MostraMensagemSimNao(
        QString& texto
    ) override;

    void MostraMensagemAviso(
        QString& texto
    ) override;

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

    Ui::Widget* ui;

    ICalculadoraViewSubscriber* subscriber;
};
#endif // WIDGET_H
