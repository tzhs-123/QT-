#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QString>
#include<QList>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
public:
    int num1;
    int num2 = 0;
    QString n;
    bool ok;
    bool flag = true;
    bool go;
    int num = 0;
public:
    void start();
    void math();
    int jiajian(QString list1);
    int chengchu(QString list1);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_12_clicked();
    
    void on_pushButton_11_clicked();
    
    void on_pushButton_13_clicked();
    
    void on_pushButton_14_clicked();
    
    void on_pushButton_15_clicked();

    void on_pushButton_17_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
