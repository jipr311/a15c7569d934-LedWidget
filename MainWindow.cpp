#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Led2* led = new Led2(this, "ledMap");
    led->setControlState(true);
    Led2* led2 = new Led2(this, "ledMap");
    led2->setControlState(true);
    led3 = new Led2(this, "ledMap");
    led3->setControlState(true);

    ui->verticalLayout->addWidget(led);
    ui->verticalLayout->addWidget(led2);
    ui->verticalLayout->addWidget(led3);
}

MainWindow::~MainWindow()
{
    delete led3;
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
 led3->setEnabled(false);
}
