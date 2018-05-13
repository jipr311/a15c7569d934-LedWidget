#include "Led2.h"

Led2::Led2(QWidget *parent, const QString &name): QWidget(parent), _name{name}
{
    groupBox = new QGroupBox(this);
    groupBox->setGeometry(QRect(0, 0, 170, 130));
    groupBox->setTitle(name);
    verticalLayout = new QVBoxLayout(groupBox);
    horizontalLayout = new QHBoxLayout(groupBox);
    horizontalLayout->setMargin( 0 );
    label = new QLabel( groupBox );
    label->setMaximumSize(QSize(60, 30));
    label->setPixmap(QPixmap(QString::fromUtf8(":/x/icon/rounded_grey.png")));
    label->setScaledContents(true);

    horizontalLayout->addWidget(label);
    messageLabel = new QLabel( "d0",  groupBox );
    QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(messageLabel->sizePolicy().hasHeightForWidth());
    messageLabel->setSizePolicy(sizePolicy);
    messageLabel->setMaximumSize(QSize(60, 30));
    messageLabel->setScaledContents(true);

    horizontalLayout->addWidget(messageLabel);

    verticalLayout->addLayout(horizontalLayout);

    pushButton = new QPushButton("Toggle", groupBox);

    verticalLayout->addWidget(pushButton);
    connect( pushButton, SIGNAL( clicked() ), this, SLOT( on_pushButton_clicked() ) );
}

Led2::~Led2()
{
    delete pushButton;
    delete verticalLayout;
    delete horizontalLayout;
    delete groupBox;
    delete label;
    delete messageLabel;
}

bool Led2::getControlState() const
{
    return _controlState;
}

void Led2::setControlLabel(const QString& msg)
{
    messageLabel->setText(msg);
}

QString Led2::getControlLabel() const
{
    return messageLabel->text();
}

void Led2::setControlState(bool newState)
{
    _controlState = newState;
    updateLed();
    emit controlStateChanged(_controlState, _labelMessage);
}

void Led2::updateLed()
{
    if (_controlState)
    {
        label->setPixmap(QPixmap(":/x/icon/rounded_green.png"));
    }
    else
    {
        label->setPixmap(QPixmap(":/x/icon/rounded_grey.png"));
    }
}

void Led2::toggleLedState()
{
    _controlState = !_controlState;
    setControlState(_controlState);
}

void Led2::on_pushButton_clicked()
{
    toggleLedState();
}
