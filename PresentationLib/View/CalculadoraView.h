#ifndef CALCULADORAVIEW_H
#define CALCULADORAVIEW_H

/*--------------------------------------------------------------------------------*/

#include <QWidget>

#include "Interfaces/ICalculadoraView.h"
#include "View/ProductDialog.h"

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

    void LimpaTelaParticipanteProduto() override;

    void InsereParticipanteTelaProduto(
        const QString& nome
    ) override;

    void InsereProduto(
        const QString& nomeProduto,
        double valorProduto
    ) override;

    bool MostraMensagemSimNao(
        QString& texto
    ) override;

    void MostraMensagemAviso(
        QString texto
    ) override;

    void LimpaListaProdutos() override;

    void RemoveProduto();


private slots:

    void AdicionaParticipanteClick();
    void RemoveParticipanteClick();

    void AtualizaListaProdutos();
    void AdicionaProdutoClick();
    void RemoveProdutoClick();

    void AvancarStep1();
    void AvancarStep2();
    void AvancarStep3();

    void VoltarStep1();
    void VoltarStep2();

private:

    void Inicializa();

    void InicializaConexoes();

    void keyPressEvent(
        QKeyEvent* event
    ) override;

    void EnterKeyPressed();

    Ui::Widget* ui;

    ICalculadoraViewSubscriber* subscriber;

    ProductDialog* productDialog;
};
#endif // CALCULADORAVIEW_H
