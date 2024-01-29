#include "ProductDialog.h"

#include "ui_productDialog.h"
#include <qevent.h>
#include <qmessagebox>

/*--------------------------------------------------------------------------------*/

ProductDialog::ProductDialog(QWidget *parent)
    : QDialog(parent),
      ui(new Ui::Dialog)
{
    Inicializar();
}

/*--------------------------------------------------------------------------------*/

ProductDialog::~ProductDialog()
{
    delete ui;
}

/*--------------------------------------------------------------------------------*/

void ProductDialog::Inicializar()
{
    ui->setupUi(this);
    InicializaConexoes();
}

/*--------------------------------------------------------------------------------*/

void ProductDialog::InicializaConexoes()
{
    connect(ui->adicionarProdutoButton, SIGNAL(clicked()), this, SLOT(AdicionaProdutoClick()));
    connect(ui->cancelarButton, SIGNAL(clicked()), this, SLOT(FechaJanela()));
}

/*--------------------------------------------------------------------------------*/

void ProductDialog::keyPressEvent(QKeyEvent* event)
{
    if (event->type() == QEvent::KeyPress) {
        if (event->key() == Qt::Key_Return) {
            AdicionaProdutoClick();
        }
        else if (event->key() == Qt::Key_Escape) {
            FechaJanela();
        }
    }
}

/*--------------------------------------------------------------------------------*/

bool ProductDialog::AreInputsValid()
{
    bool valido = true;
    const QString nomeProduto = ui->nomeProdutoEdit->text();
    const QString valorProduto = ui->valorProdutoEdit->text();
    if (nomeProduto.isEmpty() || valorProduto.isEmpty()) {
        ShowWarningMessage("Todos os campos devem estar preenchidos.");
        return false;
    }

    QRegExp re("[+-]?\\d*\\.?\\d+");
    if (!re.exactMatch(valorProduto)) {
        ShowWarningMessage("O valor deve estar em formato numérico. Exemplo: 129.90");
        return false;
    }

    return true;
}

/*--------------------------------------------------------------------------------*/

void ProductDialog::ShowWarningMessage(
    QString texto
)
{
    QMessageBox::warning(this, "Aviso", texto);
}

/*--------------------------------------------------------------------------------*/

void ProductDialog::AdicionaProdutoClick()
{
    if (AreInputsValid()) {
        QDialog::accept();
    }
}

/*--------------------------------------------------------------------------------*/

QString ProductDialog::GetNomeProduto()
{
    return ui->nomeProdutoEdit->text();
}

/*--------------------------------------------------------------------------------*/

QString ProductDialog::GetValorProduto()
{
    return ui->valorProdutoEdit->text();
}

/*--------------------------------------------------------------------------------*/

void ProductDialog::FechaJanela()
{
    QDialog::reject();
}

/*--------------------------------------------------------------------------------*/

void ProductDialog::MostraMensagemAviso(
    QString& texto
)
{
    QMessageBox::warning(this, QString("Aviso"), texto);
}

/*--------------------------------------------------------------------------------*/
