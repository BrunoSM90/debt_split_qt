#ifndef PRODUCTDIALOG_H
#define PRODUCTDIALOG_H

/*--------------------------------------------------------------------------------*/

#include <QDialog>

/*--------------------------------------------------------------------------------*/

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

/*--------------------------------------------------------------------------------*/

class ProductDialog : public QDialog
{
    Q_OBJECT

public:
    ProductDialog(
        QWidget *parent = nullptr
    );

    ~ProductDialog();

    void MostraMensagemAviso(
        QString& texto
    );

    void InicializaConexoes();

    QString GetNomeProduto();

    QString GetValorProduto();

    void DeveHabilitarAdicionarProdutoButton();

private slots:
    void AdicionaProdutoClick();

    void FechaJanela();

private:
    void Inicializar();

    void keyPressEvent(
        QKeyEvent* event
    ) override;

    bool AreInputsValid();

    void ShowWarningMessage(
        QString texto
    );

    Ui::Dialog* ui;
};
#endif // PRODUCTDIALOG_H
