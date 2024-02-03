#include "CalculadoraView.h"

#include "ui_widget.h"
#include <qevent.h>
#include <qmessagebox>

/*--------------------------------------------------------------------------------*/

CalculadoraView::CalculadoraView(QWidget *parent)
    : QWidget(parent),
      ui(new Ui::Widget)
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

    ui->produtosTableWidget->setColumnCount(2);

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

void CalculadoraView::keyPressEvent(QKeyEvent* event)
{
    if (event->type() == QEvent::KeyPress) {
        if (event->key() == Qt::Key_Return) {
            EnterKeyPressed();
        }
        else if (event->key() == Qt::Key_Backspace) {
            //VoltarButtonClick();
        }
    }
}

/*--------------------------------------------------------------------------------*/

void CalculadoraView::EnterKeyPressed()
{
    if (ui->stackedWidget->currentIndex() == 0) {
        if (ui->nomeLineEdit->hasFocus() && ui->nomeLineEdit->text() != "") {
            AdicionaParticipanteClick();
        }
        else {
            AvancarStep1();
        }
    }

    else if (ui->avancarButton->hasFocus()) {
        AvancarStep1();
    }
    else if (ui->listaParticipantesProdutos->selectedItems().size() > 0) {
        AdicionaProdutoClick();
    }
}

/*--------------------------------------------------------------------------------*/

void CalculadoraView::InicializaConexoes()
{
    connect(ui->avancarButton, SIGNAL(clicked()), this, SLOT(AvancarStep1()));
    connect(ui->avancarButton2, SIGNAL(clicked()), this, SLOT(AvancarStep2()));
    connect(ui->calcularButton, SIGNAL(clicked()), this, SLOT(AvancarStep3()));

    connect(ui->voltarButton2, SIGNAL(clicked()), this, SLOT(VoltarStep1()));
    connect(ui->voltarButton3, SIGNAL(clicked()), this, SLOT(VoltarStep2()));

    connect(ui->adicionarParticipanteButton, SIGNAL(clicked()), this, SLOT(AdicionaParticipanteClick()));
    connect(ui->removeParticipanterButton, SIGNAL(clicked()), this, SLOT(RemoveParticipanteClick()));

    connect(ui->adicionarProdutoButton, SIGNAL(clicked()), this, SLOT(AdicionaProdutoClick()));
    connect(ui->removerProdutoButton, SIGNAL(clicked()), this, SLOT(RemoveProdutoClick()));

    connect(ui->listaParticipantesProdutos, SIGNAL(itemSelectionChanged()), this, SLOT(AtualizaListaProdutos()));
}

/*--------------------------------------------------------------------------------*/

void CalculadoraView::AvancaStep(
    int step
)
{
    if (step == 1) {
        ui->participantesList->selectionModel()->clearSelection();
    }

    ui->stackedWidget->setCurrentIndex(step);
}

/*--------------------------------------------------------------------------------*/

void CalculadoraView::AvancarStep1()
{
    if (ui->participantesList->count() == 0) {
        MostraMensagemAviso(QString("Nenhum participante foi inserido."));
    }
    else {
        subscriber->CadastraParticipantes();
        ui->adicionarProdutoButton->setEnabled(false);
    }
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

void CalculadoraView::AdicionaParticipanteClick()
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

void CalculadoraView::RemoveParticipanteClick()
{
    QModelIndexList selectedList = ui->participantesList->selectionModel()->selectedIndexes();
    if (!selectedList.isEmpty()) {
        const QModelIndex& index = selectedList.first();
        const QString nomeParticipante = index.data().toString();
        subscriber->RemoveParticipante(nomeParticipante);
        ui->participantesList->model()->removeRow(index.row());
    }
}

/*--------------------------------------------------------------------------------*/

void CalculadoraView::LimpaTelaParticipanteProduto()
{
    ui->listaParticipantesProdutos->clear();
}

/*--------------------------------------------------------------------------------*/

void CalculadoraView::InsereParticipanteTelaProduto(
    const QString& nome
)
{
    ui->listaParticipantesProdutos->addItem(nome);
}

/*--------------------------------------------------------------------------------*/

void CalculadoraView::AtualizaListaProdutos()
{
    if (ui->listaParticipantesProdutos->selectedItems().size() > 0) {
        const QListWidgetItem& item = *ui->listaParticipantesProdutos->selectedItems().first();
        const QString nomeParticipante = item.text();
        subscriber->AtualizaListaProdutos(nomeParticipante);
        ui->adicionarProdutoButton->setEnabled(true);
    }
}

/*--------------------------------------------------------------------------------*/

void CalculadoraView::LimpaListaProdutos()
{
    QAbstractItemModel* model = ui->produtosTableWidget->model();
    int rowsCount = model->rowCount();
    for (int i = 0; i < rowsCount; i++) {
        model->removeRow(i);
    }
}

/*--------------------------------------------------------------------------------*/

void CalculadoraView::InsereProduto(
    const QString& nomeProduto,
    double valorProduto
)
{
    const int count = ui->produtosTableWidget->rowCount();
    ui->produtosTableWidget->insertRow(count);

    QTableWidgetItem* nome = new QTableWidgetItem(nomeProduto);
    QTableWidgetItem* valor = new QTableWidgetItem(valorProduto);
    ui->produtosTableWidget->setItem(count, 0, nome);
    ui->produtosTableWidget->setItem(count, 1, valor);
}

/*--------------------------------------------------------------------------------*/

void CalculadoraView::AdicionaProdutoClick()
{
    productDialog = new ProductDialog(this);
    if (productDialog->exec() == QDialog::Accepted) {
        const QListWidgetItem& item = *ui->listaParticipantesProdutos->selectedItems().first();
        const QString nomeParticipante = item.text();
        const QString nomeProduto = productDialog->GetNomeProduto();
        const QString valorProduto = productDialog->GetValorProduto();

        subscriber->InsereProduto(nomeParticipante, nomeProduto, valorProduto);
    }
}

/*--------------------------------------------------------------------------------*/

void CalculadoraView::RemoveProdutoClick()
{
    const QList<QTableWidgetItem*>& produtosSelecionados = ui->produtosTableWidget->selectedItems();
    if (produtosSelecionados.size() > 0) {
        const QListWidgetItem* participante = ui->listaParticipantesProdutos->selectedItems().first();
        const QTableWidgetItem* produto = produtosSelecionados.first();
        subscriber->RemoveProdutoComprado(participante->text(), produto->text());
        ui->produtosTableWidget->model()->removeRow(produto->row());
    }
    else {
        MostraMensagemAviso("Nenhum produto selecionado.");
    }
}

/*--------------------------------------------------------------------------------*/

void CalculadoraView::MostraMensagemAviso(
    QString texto
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



