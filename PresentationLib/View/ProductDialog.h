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

private slots:
    void AdicionaProdutoClick();

    void FechaJanela();

private:
    void Inicializar();

    void keyPressEvent(
        QKeyEvent* event
    ) override;

    void EnterKeyPressed();

    Ui::Dialog* ui;
};
#endif // WIDGET_H
