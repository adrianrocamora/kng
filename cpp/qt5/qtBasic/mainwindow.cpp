#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->plainTextEdit->setReadOnly(true);
    connect(ui->helloButton,
            &QPushButton::clicked,
            this,
            &MainWindow::displayHello);
    connect(ui->holaButton,
            &QPushButton::clicked,
            this,
            &MainWindow::onHolaClicked);
    connect(ui->bonjourButton,
            &QPushButton::clicked,
            this,
            &MainWindow::clearDisplay);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayHello()
{
    ui->plainTextEdit->appendPlainText(QString("Hello"));
}

void MainWindow::onHolaClicked()
{
    ui->plainTextEdit->appendPlainText(QString("Hola"));
    disconnect(ui->helloButton,
               &QPushButton::clicked,
               this,
               &MainWindow::displayHello);
}

void MainWindow::clearDisplay()
{
    ui->plainTextEdit->clear();
}
