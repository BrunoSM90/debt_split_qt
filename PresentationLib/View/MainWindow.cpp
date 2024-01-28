#include "MainWindow.h"

#include "ui_mainwindow.h"
#include <qmessagebox>

/*--------------------------------------------------------------------------------*/

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
}

/*--------------------------------------------------------------------------------*/

MainWindow::~MainWindow()
{
    delete ui;
}

/*--------------------------------------------------------------------------------*/
