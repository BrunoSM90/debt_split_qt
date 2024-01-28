#include "CalculadoraView.h"

#include "ui_widget.h"
#include <qmessagebox>

/*--------------------------------------------------------------------------------*/

CalculadoraView::CalculadoraView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    Inicializa();
}

/*--------------------------------------------------------------------------------*/

CalculadoraView::~CalculadoraView()
{
    delete ui;
}

/*--------------------------------------------------------------------------------*/

void CalculadoraView::Inicializa()
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(EPAGESINDEX::PARTICIPANTES_PAGE);

    InicializaConexoes();
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

void CalculadoraView::AvancaStep(
    int step
)
{
    ui->stackedWidget->setCurrentIndex(step);
}

/*--------------------------------------------------------------------------------*/

void CalculadoraView::AvancarStep1()
{
    subscriber->CadastraParticipantes();
}

/*--------------------------------------------------------------------------------*/


void CalculadoraView::AvancarStep2()
{
    ui->stackedWidget->setCurrentIndex(EPAGESINDEX::CONSUMO_PAGE);
}

/*--------------------------------------------------------------------------------*/

void CalculadoraView::AvancarStep3()
{
    ui->stackedWidget->setCurrentIndex(EPAGESINDEX::CALCULO_PAGE);
}

/*--------------------------------------------------------------------------------*/

void CalculadoraView::VoltarStep1()
{
    ui->stackedWidget->setCurrentIndex(EPAGESINDEX::PARTICIPANTES_PAGE);
}

/*--------------------------------------------------------------------------------*/

void CalculadoraView::VoltarStep2()
{
    ui->stackedWidget->setCurrentIndex(EPAGESINDEX::PRODUTOS_PAGE);
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

void CalculadoraView::InsereParticipanteTelaProduto(
    const QString& nome
)
{
    //ui->listaParticipantes2Label->addItem(nome);
}

/*--------------------------------------------------------------------------------*/

void CalculadoraView::MostraMensagemAviso(
    QString& texto
)
{
    QMessageBox::warning(this, QString("Aviso"), texto);
}

/*--------------------------------------------------------------------------------*/

bool CalculadoraView::MostraMensagemSimNao(
    QString& texto
)
{
    return QMessageBox::question(this, QString("Aviso"), texto, QMessageBox::Yes | QMessageBox::No);
}

/*--------------------------------------------------------------------------------*/



