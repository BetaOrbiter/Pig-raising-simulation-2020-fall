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
    void on_load_clicked();


    void on_begstop_clicked();

    void on_returnMain_clicked();

    void on_newGame_clicked();

    void on_save_clicked();

    void on_autoPur_clicked();

    void on_explation_clicked();

    void on_purchase_clicked();

    void on_inqure_clicked();

protected:
    void closeEvent(QCloseEvent* event);
private:
    Ui::MainWindow* ui;
    farm::Factory* fa;
    QTimer* timer = new QTimer;
    QString name;
};
#endif // MAINWINDOW_H
