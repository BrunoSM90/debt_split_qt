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
            EnterKeyPressed();
        }
    }
}

/*--------------------------------------------------------------------------------*/

void ProductDialog::EnterKeyPressed()
{
    //if (ui->nomeLineEdit->hasFocus() && ui->nomeLineEdit->text() != "") {
    //    AdicionaParticipanteClick();
    //}
}

/*--------------------------------------------------------------------------------*/

void ProductDialog::AdicionaProdutoClick()
{
    
}

/*--------------------------------------------------------------------------------*/

void ProductDialog::FechaJanela()
{
    
}

/*--------------------------------------------------------------------------------*/

void ProductDialog::MostraMensagemAviso(
    QString& texto
)
{
    QMessageBox::warning(this, QString("Aviso"), texto);
}

/*--------------------------------------------------------------------------------*/
