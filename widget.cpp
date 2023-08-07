#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbCoffee->setEnabled(false); // 초기에 비활성화하기~~
    ui->pbTea->setEnabled(false); // 초기에 비활성화~~
    ui->pbMilk->setEnabled(false); // 초기에 비활성화~~
    updateButtons();
}

Widget::~Widget()
{
    delete ui;
}
void Widget::changeMoney(int diff){
    money += diff;
    ui->lcdNumber->display(money);
    updateButtons(); // 금액 변경 후 버튼 상태 업데이트
}
void Widget::updateButtons()
{
    ui->pbCoffee->setEnabled(money >= 100); //100원보다 돈이 적으면 비활성화
    ui->pbTea->setEnabled(money >= 150);//마찬가지
    ui->pbMilk->setEnabled(money >= 200);//마찬가지
}
void Widget::on_qb10_clicked()
{
    changeMoney(10);
}

void Widget::on_qb50_clicked()
{
    changeMoney(50);
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
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

void Widget::on_pbMilk_clicked()
{
    changeMoney(-200);
}

void Widget::on_pbReset_clicked() // 잔돈계산 후 반환
{
    int remainingMoney = money;
    int num500 = remainingMoney / 500;
    remainingMoney %= 500;

    int num100 = remainingMoney / 100;
    remainingMoney %= 100;

    int num50 = remainingMoney / 50;
    remainingMoney %= 50;

    int num10 = remainingMoney / 10;
    remainingMoney %= 10;

    QString message = "<잔돈> 500원 개수: " + QString::number(num500) +
                      ", 100원 개수: " + QString::number(num100) +
                      ", 50원 개수: " + QString::number(num50) +
                      ", 10원 개수: " + QString::number(num10) ;

    QMessageBox mb;
    mb.information(this, "잔돈반환", message);//메세지 출력하기

    changeMoney(-money); // 금액을 0으로 리셋
}
