#include "widget.h"
#include "ui_widget.h"


#include<QDebug>
void Widget::on_pushButton_clicked()
{
    ui->textEdit->insertPlainText("1");
}

void Widget::on_pushButton_2_clicked()
{
    ui->textEdit->insertPlainText("2");
}

void Widget::on_pushButton_7_clicked()
{
    ui->textEdit->insertPlainText("3");
}

void Widget::on_pushButton_3_clicked()
{
    ui->textEdit->insertPlainText("4");
}

void Widget::on_pushButton_6_clicked()
{
    ui->textEdit->insertPlainText("5");
}

void Widget::on_pushButton_4_clicked()
{
    ui->textEdit->insertPlainText("6");
}

void Widget::on_pushButton_5_clicked()
{
    ui->textEdit->insertPlainText("7");
}

void Widget::on_pushButton_8_clicked()
{
    ui->textEdit->insertPlainText("8");
}

void Widget::on_pushButton_9_clicked()
{
    ui->textEdit->insertPlainText("9");
}

void Widget::on_pushButton_10_clicked()
{
    ui->textEdit->insertPlainText("0");
}

void Widget::on_pushButton_16_clicked()
{
    ui->textEdit->clear();
    flag = true;
    start();
}

void Widget::on_pushButton_12_clicked()
{
    n = ui->textEdit->toPlainText();
    num1 = n.toInt(&ok,10);
    ui->textEdit->insertPlainText("+");
}


void Widget::on_pushButton_11_clicked()
{
    ui->textEdit->insertPlainText("-");
}

void Widget::on_pushButton_13_clicked()
{
    ui->textEdit->insertPlainText("×");
}

void Widget::on_pushButton_14_clicked()
{
    ui->textEdit->insertPlainText("÷");
}

void Widget::on_pushButton_15_clicked()
{
        QString s;
        math();
        flag = false;
        start();
        s = QString::number(num);
        ui->textEdit->append(s);
//        ui->textEdit->append("\n");
}
