#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    checkAvailable();
}

Widget::~Widget()
{
    delete ui;
}
void Widget::checkAvailable(){
    bool flag[3] = {true, true, true};

    if (money<100)
        flag[0] = false;
    if (money<150)
        flag[1] = false;
    if (money<200)
        flag[2] = false;

    ui->pbCoffee->setEnabled(flag[0]);
    ui->pbTea->setEnabled(flag[1]);
    ui->pbGongcha->setEnabled(flag[2]);
}
void Widget::changeMoney(int n){
    money += n;
    ui->lcdNumber->display(QString::number(money));
    checkAvailable();
}
void Widget::returnMoney(){
    QMessageBox msg;
    std::string rtnString;
    int rtn500,rtn50,rtn100,rtn10;
    rtn500=money/500;
    money=money%500;
    rtn100=money/100;
    money=money%100;
    rtn50=money/50;
    money=money%50;
    rtn10=money/10;
    money=money%10;
    changeMoney(0);
    rtnString = "Your change is \n500 : " + std::to_string(rtn500)
            + "\n100 : " + std::to_string(rtn100) + "\n50 : " + std::to_string(rtn50)
            + "\n10 : " + std::to_string(rtn10);
    msg.setText(rtnString.c_str());
    msg.exec();
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}

void Widget::on_pbGongcha_clicked()
{
    changeMoney(-200);
}


void Widget::on_pbReturn_clicked()
{
    returnMoney();
}
