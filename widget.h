#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    int money = 0;
    void changeMoney(int diff); // 바뀐 돈 목록을 저장하기 위해 함수 선언
private slots:
    void on_qb10_clicked();

    void on_qb50_clicked();

    void on_pb100_clicked();

    void on_pb500_clicked();

    void on_pbCoffee_clicked();

    void on_pbTea_clicked();

    void on_pbMilk_clicked();

    void on_pbReset_clicked();

private:
    Ui::Widget *ui;
    void updateButtons(); // 업데이트 목록을 저장하기 위해 함수 선언
};
#endif // WIDGET_H
