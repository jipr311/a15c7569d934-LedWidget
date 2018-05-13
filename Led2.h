#ifndef LED2_H
#define LED2_H

#include <QWidget>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

class Led2 : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(bool _controlState READ getControlState WRITE setControlState NOTIFY controlStateChanged)
    Q_PROPERTY(QString _labelMessage READ getControlLabel WRITE setControlLabel NOTIFY controlStateChanged)
public:
    explicit Led2(QWidget *parent = nullptr, const QString& name = "");
    ~Led2();
    bool getControlState() const;
    QString getControlLabel() const;

signals:
    void controlStateChanged(const bool newState, const QString& msg) const;

public slots:
    void setControlLabel(const QString& msg);
    void setControlState(bool newState);
    void toggleLedState();
    void updateLed();
private slots:
    void on_pushButton_clicked();


private:
    bool _controlState;
    QString _name;
    QString _labelMessage;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *messageLabel;
    QPushButton *pushButton;
};

#endif // LED2_H
