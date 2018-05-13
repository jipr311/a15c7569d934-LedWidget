#ifndef LED_H
#define LED_H

#include <QWidget>

namespace Ui {
class Led;
}

class Led : public QWidget
{
    Q_OBJECT

public:
    explicit Led(QWidget *parent = 0, const QString& name = "");
    ~Led();
public slots:
    void setLedState(bool newState);
    void setControlEnabled(bool newState);
    void toggleLedState();
private slots:
    void on_pushButton_clicked();

private:
    Ui::Led *ui;
    bool _ledState;
    bool _enableState;
    QString _name;
};

#endif // LED_H
