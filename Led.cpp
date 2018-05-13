#include "Led.h"
#include "ui_Led.h"

Led::Led(QWidget *parent, const QString& name) :
    QWidget(parent), ui(new Ui::Led), _name{name}
{
    ui->setupUi(this);
    ui->groupBox->setTitle(_name);
    _enableState = true;
}

Led::~Led()
{
    delete ui;
}

void Led::setLedState(bool newState)
{
    if (newState)
    {
        ui->label->setPixmap(QPixmap(":/x/icon/rounded_green.png"));
    }
    else
    {
        ui->label->setPixmap(QPixmap(":/x/icon/rounded_grey.png"));
    }
}

void Led::setControlEnabled(bool newState)
{
//    if (newState)
    {
        ui->groupBox->setEnabled(newState);
    }
//    else
//    {
//        ui->label->setPixmap(QPixmap(":/x/icon/rounded_grey.png"));
//    }
}

void Led::toggleLedState()
{
     _ledState = !_ledState;
     setLedState(_ledState);
}

void Led::on_pushButton_clicked()
{
    toggleLedState();
}
