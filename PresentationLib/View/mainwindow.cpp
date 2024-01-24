#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <qmessagebox.h>
#include <qvector.h>
#include <iostream>


/*--------------------------------------------------------------------------------*/

MainWindow::MainWindow(
    TCalculadoraWrapper* _wrapper,
    QWidget* parent
) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    wrapper(_wrapper)
{
    Inicializa();
}

/*--------------------------------------------------------------------------------*/

MainWindow::~MainWindow()
{
    delete ui;
}

/*--------------------------------------------------------------------------------*/

void MainWindow::Inicializa()
{
    ui->setupUi(this);

    InicializaConexoes();

    ui->voltarButton->setEnabled(false);
    QString font = "font: 75 9pt 'MS Shell Dlg 2'";
    ui->insiraParticipantesLabel->setStyleSheet(font);
    ui->labelParticipantes->setStyleSheet(font);
}

/*--------------------------------------------------------------------------------*/

void MainWindow::InicializaConexoes()
{
    connect(ui->adicionarButton, SIGNAL(clicked()), this, SLOT(AdicionarParticipante()));
    connect(ui->removerButton, SIGNAL(clicked()), this, SLOT(RemoverParticipante()));
    connect(ui->avancarButton, SIGNAL(clicked()), this, SLOT(AvancarButtonClick()));
}

/*--------------------------------------------------------------------------------*/

void MainWindow::AdicionarParticipante()
{
    const QString nomeParticipante = ui->participantesLineEdit->text();
    if (!nomeParticipante.isEmpty()) {
        ui->listParticipantes->addItem(nomeParticipante);
        ui->participantesLineEdit->clear();
    }
    else {
        QMessageBox::warning(this, "Aviso", "O campo nome n�o pode estar vazio.");
    }

    ui->participantesLineEdit->setFocus();
}

/*--------------------------------------------------------------------------------*/

void MainWindow::RemoverParticipante()
{
    QModelIndexList selectedList = ui->listParticipantes->selectionModel()->selectedIndexes();
    if (!selectedList.isEmpty()) {
        for (const QModelIndex& singleIndex : selectedList) {
            ui->listParticipantes->model()->removeRow(singleIndex.row());
        }
    }
    else {
        QMessageBox::warning(this, "Aviso", "Voc� deve selecionar um participante para remover.");
    }
}

/*--------------------------------------------------------------------------------*/

void MainWindow::AvancarButtonClick()
{
    if (ui->listParticipantes->count() == 0) {
        QMessageBox::warning(this, "Aviso", "N�o h� participante cadastrado.");
        return;
    }

    QVector<QString>* participantes = new QVector<QString>();
    for (auto item : ui->listParticipantes->findItems("*", Qt::MatchWildcard)) {
        participantes->push_back(item->text());
    }

    wrapper->CadastraParticipantes(participantes);
}

/*--------------------------------------------------------------------------------*/