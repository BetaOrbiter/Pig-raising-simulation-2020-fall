#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Typedef.h"
#include <QTimer>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void on_load_clicked();//按钮：读取存档


    void on_begstop_clicked(); //按钮：暂停、继续游戏

    void on_returnMain_clicked();//按钮：保存游戏并返回主界面

    void on_newGame_clicked();//按钮：创建新游戏

    void on_save_clicked();//按钮：保存游戏

    void on_autoPur_clicked();//按钮：自动购买开关

    void on_explation_clicked();//按钮：弹出游戏说明

    void on_purchase_clicked();//按钮：手动买猪

    void on_inqure_clicked();//按钮：查询流水

protected:
    void closeEvent(QCloseEvent* event);
private:
    Ui::MainWindow* ui;
    farm::Factory* fa;
    QTimer* timer = new QTimer;
    QString name;
};
#endif // MAINWINDOW_H
