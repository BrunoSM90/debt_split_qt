#include "CalculadoraView.h"
#include "ui_mainwindow.h"

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

    InicializaConexoes();

    //QString font = "font: 75 9pt 'MS Shell Dlg 2'";
    //ui->insiraParticipantesLabel->setStyleSheet(font);
    //ui->labelParticipantes->setStyleSheet(font);
}

/*--------------------------------------------------------------------------------*/

void CalculadoraView::InicializaConexoes()
{
    connect(ui->avancarButton, SIGNAL(clicked()), this, SLOT(AvancarStep1()));
    connect(ui->avancarButton2, SIGNAL(clicked()), this, SLOT(AvancarStep2()));
    connect(ui->calcularButton, SIGNAL(clicked()), this, SLOT(CalularDividas()));

    connect(ui->voltarButton2, SIGNAL(clicked()), this, SLOT(VoltarStep1()));
    connect(ui->voltarButton3, SIGNAL(clicked()), this, SLOT(VoltarStep2()));

    //connect(ui->removerButton, SIGNAL(clicked()), this, SLOT(RemoverParticipante()));
    //connect(ui->avancarButton, SIGNAL(clicked()), this, SLOT(AvancarButtonClick()));
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

void CalculadoraView::CalularDividas()
{
    ui->stackedWidget->setCurrentIndex(3);
}

/*--------------------------------------------------------------------------------*/
void CalculadoraView::AdicionarParticipante()
{
    /*const QString nomeParticipante = ui->participantesLineEdit->text();
    if (!nomeParticipante.isEmpty()) {
        ui->listParticipantes->addItem(nomeParticipante);
        ui->participantesLineEdit->clear();
    }
    else {
        QMessageBox::warning(this, "Aviso", "O campo nome não pode estar vazio.");
    }

    ui->participantesLineEdit->setFocus();*/
}

/*--------------------------------------------------------------------------------*/

void CalculadoraView::RemoverParticipante()
{
    /*QModelIndexList selectedList = ui->listParticipantes->selectionModel()->selectedIndexes();
    if (!selectedList.isEmpty()) {
        for (const QModelIndex& singleIndex : selectedList) {
            ui->listParticipantes->model()->removeRow(singleIndex.row());
        }
    }
    else {
        QMessageBox::warning(this, "Aviso", "Você deve selecionar um participante para remover.");
    }*/
}

/*--------------------------------------------------------------------------------*/

