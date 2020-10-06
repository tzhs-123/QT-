#include "widget.h"
#include "ui_widget.h"

#include<QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    start();
}

Widget::~Widget()
{
    delete ui;
}
void Widget::start()
{
    ui->pushButton->setEnabled(flag);
    ui->pushButton_2->setEnabled(flag);
    ui->pushButton_3->setEnabled(flag);
    ui->pushButton_4->setEnabled(flag);
    ui->pushButton_5->setEnabled(flag);
    ui->pushButton_6->setEnabled(flag);
    ui->pushButton_7->setEnabled(flag);
    ui->pushButton_8->setEnabled(flag);
    ui->pushButton_9->setEnabled(flag);
    ui->pushButton_10->setEnabled(flag);
    ui->pushButton_11->setEnabled(flag);
    ui->pushButton_12->setEnabled(flag);
    ui->pushButton_13->setEnabled(flag);
    ui->pushButton_14->setEnabled(flag);
    ui->pushButton_15->setEnabled(flag);
    ui->pushButton_17->setEnabled(flag);
    ui->pushButton_16->setEnabled(!flag);
}

void Widget::on_pushButton_17_clicked()
{
    QString str;
    str =  ui->textEdit->toPlainText();
    str = str.left(str.size() - 1);
    ui->textEdit->clear();
    ui->textEdit->insertPlainText(str);
}
void Widget::math()
{
    n = ui->textEdit->toPlainText();
    //思路：首先判断是不是只有乘除和加减
    //若是，则按照从左到右的顺序依次计算
    /*
     1.分为两类，只有乘除，只有加减
     2.只有加减：先将算式按照+分割，判断是否可以转换为10进制整型数据，若可以，直接加，若不可，按照减法分离，取前面的计算结果，进行减法运算。直至循环结束
     3.只有乘除：同上
    */
    //若不是，先算乘除，再算加减
    /*
    先算乘除，再算加减
    例如 12+3*5-4/2*4*5+9-6*9
    1.按加减划分，取
    */
    bool a,b,c,d;
    a = n.contains("+",Qt::CaseSensitive);
    b = n.contains("-",Qt::CaseSensitive);
    c = n.contains("×",Qt::CaseSensitive);
    d = n.contains("÷",Qt::CaseSensitive);
/**********************************************只有加减*************************************************************************/
//    if((a==1||b==1)&&(c==0||d==0))
//    {
//        int cnt;
//        QString list1 = n;
//        cnt  = jiajian(list1);
//        num = cnt;
//    }
///**********************************************只有乘除,未处理除不尽问题***********************************************************************/
//    if((a==0||b==0)&&(c==1||d==1))
//    {
//        int cnt;
//        QString list1 = n;
//        cnt = chengchu(list1);
//        num = cnt;
//    }
/**********************************************混合****************************************************************************************/
    if(a == 1||b==1||c==1||d==1)
    {
        int temp;
        QStringList list = n.split("+");
        int h = 0,answer = 0;
        for(int i =0;i<list.count();i++)
        {
            list[i].toInt(&ok,10);
            if(!ok)
            {
                if(list[i].contains("-",Qt::CaseSensitive))
                {
                    QStringList list1 = list[i].split("-");
                   for(int a = 0;a<list1.count();a++)
                   {
                       list1[a].toInt(&ok,10);
                       if(ok == false)
                       {
                           temp = chengchu(list1[a]);
                           if(h==0)
                           {
                               h = temp;
                           }
                           else
                               h-=temp;
                       }
                       if(h==0)
                       {
                           h = list1[a].toInt(&ok,10);
                       }
                       else
                           h -= list1[a].toInt(&ok,10);
                   }
                }
                else
                {
                    h = chengchu(list[i]);
                }
                answer+=h;
            }
            answer+=list[i].toInt(&ok,10);
        }
        num = answer;
    }
}
int Widget::jiajian(QString list1)
{
    bool a,b,c,d;
    a = list1.contains("+",Qt::CaseSensitive);
    b = list1.contains("-",Qt::CaseSensitive);
    c = list1.contains("×",Qt::CaseSensitive);
    d = list1.contains("÷",Qt::CaseSensitive);
    int cnt = 0;
    if((a==1||b==1)&&(c==0||d==0))
    {
        QStringList list = list1.split("+");
        for(int i=0;i<list.count();i++)
        {
            if(list[i].toInt(&ok,10))
            {
                cnt+=list[i].toInt(&ok,10);
            }
            else
            {
                QStringList temp = list[i].split("-");
                cnt+=temp[0].toInt(&ok,10);
                for(int j = 1;j<temp.count();j++)
                {
                    cnt -= temp[j].toInt(&ok,10);
                }
            }
        }
    }
    return cnt;
}
int Widget::chengchu(QString list1)
{
    bool a,b,c,d;
    a = list1.contains("+",Qt::CaseSensitive);
    b = list1.contains("-",Qt::CaseSensitive);
    c = list1.contains("×",Qt::CaseSensitive);
    d = list1.contains("÷",Qt::CaseSensitive);
    int cnt = 1;
    if((a==0||b==0)&&(c==1||d==1))
    {
        QStringList list = list1.split("×");
        for(int i=0;i<list.count();i++)
        {
            if(list[i].toInt(&ok,10))
            {
                cnt*=list[i].toInt(&ok,10);
            }
            else
            {
                QStringList temp = list[i].split("÷");
                cnt*=temp[0].toInt(&ok,10);
                for(int j = 1;j<temp.count();j++)
                {
                    cnt /= temp[j].toInt(&ok,10);
                }
            }
        }
    }
    return cnt;
}
