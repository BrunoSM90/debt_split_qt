#include "CalculadoraView.h"

#include "ui_mainwindow.h"
#include <qmessagebox>

/*--------------------------------------------------------------------------------*/

CalculadoraView::CalculadoraView(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    Inicializa();
}

/*--------------------------------------------------------------------------------*/

CalculadoraView::~CalculadoraView()
{
    delete ui;
}

/*--------------------------------------------------------------------------------*/

void CalculadoraView::Show()
{
    show();
}

/*--------------------------------------------------------------------------------*/

void CalculadoraView::Subscribe(
    ICalculadoraViewSubscriber* _subscriber
)
{
    subscriber = _subscriber;
}

/*--------------------------------------------------------------------------------*/

void CalculadoraView::Inicializa()
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(PAGESINDEX::PARTICIPANTES_PAGE);

    InicializaConexoes();
}

/*--------------------------------------------------------------------------------*/

void CalculadoraView::InicializaConexoes()
{
    connect(ui->avancarButton, SIGNAL(clicked()), this, SLOT(AvancarStep1()));
    connect(ui->avancarButton2, SIGNAL(clicked()), this, SLOT(AvancarStep2()));
    connect(ui->calcularButton, SIGNAL(clicked()), this, SLOT(AvancarStep3()));

    connect(ui->voltarButton2, SIGNAL(clicked()), this, SLOT(VoltarStep1()));
    connect(ui->voltarButton3, SIGNAL(clicked()), this, SLOT(VoltarStep2()));

    connect(ui->adicionarParticipanteButton, SIGNAL(clicked()), this, SLOT(AdicionaParticipante()));
    connect(ui->removeParticipanterButton, SIGNAL(clicked()), this, SLOT(RemoveParticipante()));
}

/*--------------------------------------------------------------------------------*/

void CalculadoraView::AvancarStep1()
{
    ui->stackedWidget->setCurrentIndex(PAGESINDEX::PRODUTOS_PAGE);
}

/*--------------------------------------------------------------------------------*/


void CalculadoraView::AvancarStep2()
{
    ui->stackedWidget->setCurrentIndex(PAGESINDEX::CONSUMO_PAGE);
}

/*--------------------------------------------------------------------------------*/

void CalculadoraView::AvancarStep3()
{
    ui->stackedWidget->setCurrentIndex(PAGESINDEX::CALCULO_PAGE);
}

/*--------------------------------------------------------------------------------*/

void CalculadoraView::VoltarStep1()
{
    ui->stackedWidget->setCurrentIndex(PAGESINDEX::PARTICIPANTES_PAGE);
}

/*--------------------------------------------------------------------------------*/

void CalculadoraView::VoltarStep2()
{
    ui->stackedWidget->setCurrentIndex(PAGESINDEX::PRODUTOS_PAGE);
}

/*--------------------------------------------------------------------------------*/

void CalculadoraView::AdicionaParticipante()
{
    QString nomeParticipante = ui->nomeLineEdit->text();
    std::string nome = nomeParticipante.toStdString().c_str();
    subscriber->AdicionaParticipante(nomeParticipante);
    ui->nomeLineEdit->setFocus();
}

/*--------------------------------------------------------------------------------*/

void CalculadoraView::AdicionaParticipanteBox()
{
    ui->participantesList->addItem(ui->nomeLineEdit->text());
    ui->nomeLineEdit->clear();
}

/*--------------------------------------------------------------------------------*/

void CalculadoraView::RemoveParticipante()
{
    QModelIndexList selectedList = ui->participantesList->selectionModel()->selectedIndexes();
    if (!selectedList.isEmpty()) {
        const QModelIndex& index = selectedList.first();
        QString texto = index.data().toString();
        subscriber->RemoveParticipante(texto);
        ui->participantesList->model()->removeRow(index.row());
    }
}

/*--------------------------------------------------------------------------------*/

void CalculadoraView::MostraMensagemAviso(
    QString& texto
)
{
    QMessageBox::warning(this, QString("titulo"), texto);
}

/*--------------------------------------------------------------------------------*/

