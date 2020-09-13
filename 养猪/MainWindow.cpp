#include "mainwindow.h"
#include "ui_MainWindow.h"
#include <fstream>
#include <sstream>
#include <QTimer>
#include <QDialog>
#include <QMessageBox>
#include <QKeyEvent>
#include "Factory.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , fa(nullptr)
{
    ui->setupUi(this);

    connect(timer, &QTimer::timeout, [=]() {
        fa->purChase(farm::Pigs(10)[0]);
        fa->step();
        fa->sellOut();

        ui->money->setText(QString("钱： %1").arg(fa->getMoney()));
        ui->num->setText(QString("总数： %1").arg(fa->pigNum()));
        ui->day->setText(QString("日期： %1").arg(fa->getDay()));
        ui->weight->setText(QString("总质量： %1").arg(fa->getWeight()));
        ui->value->setText(QString("总价值： %1").arg(fa->getValue()));

        const auto& bla = (*fa)[farm::black];
        ui->num_black->setText(QString("总数： %1").arg(bla.size()));
        ui->illNum_black->setText(QString("病猪数： %1").arg(bla.getIllNum()));
        ui->weight_black->setText(QString("总质量： %1").arg(bla.getWeight()));
        ui->value_black->setText(QString("总价值： %1").arg(bla.getValue()));

        const auto& whi = (*fa)[farm::white];
        ui->num_white->setText(QString("总数： %1").arg(whi.size()));
        ui->illNum_white->setText(QString("病猪数： %1").arg(whi.getIllNum()));
        ui->weight_white->setText(QString("总质量： %1").arg(whi.getWeight()));
        ui->value_white->setText(QString("总价值： %1").arg(whi.getValue()));

        const auto& str = (*fa)[farm::stripe];
        ui->num_stripe->setText(QString("总数： %1").arg(str.size()));
        ui->illNum_stripe->setText(QString("病猪数： %1").arg(str.getIllNum()));
        ui->weight_stripe->setText(QString("总质量： %1").arg(str.getWeight()));
        ui->value_stripe->setText(QString("总价值： %1").arg(str.getValue()));


        if (rand() % 1000 < 5) {
            farm::SizeType pos = fa->BreakOut();
            int ret = QMessageBox::question(this, "疫情！", QString("疫情爆发于 %1 号猪圈！\n是否扑杀？").arg(pos));
            if (QMessageBox::Yes == ret)
                fa->kill(pos);
        }
        });

    connect(ui->inqure, &QPushButton::clicked,
        [=]() {
            
        });

    penButton* ppp[100];
    {
        ppp[0] = ui->pen_0;
        ppp[1] = ui->pen_1;
        ppp[2] = ui->pen_2;
        ppp[3] = ui->pen_3;
        ppp[4] = ui->pen_4;
        ppp[5] = ui->pen_5;
        ppp[6] = ui->pen_6;
        ppp[7] = ui->pen_7;
        ppp[8] = ui->pen_8;
        ppp[9] = ui->pen_9;
        ppp[10] = ui->pen_10;
        ppp[11] = ui->pen_11;
        ppp[12] = ui->pen_12;
        ppp[13] = ui->pen_13;
        ppp[14] = ui->pen_14;
        ppp[15] = ui->pen_15;
        ppp[16] = ui->pen_16;
        ppp[17] = ui->pen_17;
        ppp[18] = ui->pen_18;
        ppp[19] = ui->pen_19;
        ppp[20] = ui->pen_20;
        ppp[21] = ui->pen_21;
        ppp[22] = ui->pen_22;
        ppp[23] = ui->pen_23;
        ppp[24] = ui->pen_24;
        ppp[25] = ui->pen_25;
        ppp[26] = ui->pen_26;
        ppp[27] = ui->pen_27;
        ppp[28] = ui->pen_28;
        ppp[29] = ui->pen_29;
        ppp[30] = ui->pen_30;
        ppp[31] = ui->pen_31;
        ppp[32] = ui->pen_32;
        ppp[33] = ui->pen_33;
        ppp[34] = ui->pen_34;
        ppp[35] = ui->pen_35;
        ppp[36] = ui->pen_36;
        ppp[37] = ui->pen_37;
        ppp[38] = ui->pen_38;
        ppp[39] = ui->pen_39;
        ppp[40] = ui->pen_40;
        ppp[41] = ui->pen_41;
        ppp[42] = ui->pen_42;
        ppp[43] = ui->pen_43;
        ppp[44] = ui->pen_44;
        ppp[45] = ui->pen_45;
        ppp[46] = ui->pen_46;
        ppp[47] = ui->pen_47;
        ppp[48] = ui->pen_48;
        ppp[49] = ui->pen_49;
        ppp[50] = ui->pen_50;
        ppp[51] = ui->pen_51;
        ppp[52] = ui->pen_52;
        ppp[53] = ui->pen_53;
        ppp[54] = ui->pen_54;
        ppp[55] = ui->pen_55;
        ppp[56] = ui->pen_56;
        ppp[57] = ui->pen_57;
        ppp[58] = ui->pen_58;
        ppp[59] = ui->pen_59;
        ppp[60] = ui->pen_60;
        ppp[61] = ui->pen_61;
        ppp[62] = ui->pen_62;
        ppp[63] = ui->pen_63;
        ppp[64] = ui->pen_64;
        ppp[65] = ui->pen_65;
        ppp[66] = ui->pen_66;
        ppp[67] = ui->pen_67;
        ppp[68] = ui->pen_68;
        ppp[69] = ui->pen_69;
        ppp[70] = ui->pen_70;
        ppp[71] = ui->pen_71;
        ppp[72] = ui->pen_72;
        ppp[73] = ui->pen_73;
        ppp[74] = ui->pen_74;
        ppp[75] = ui->pen_75;
        ppp[76] = ui->pen_76;
        ppp[77] = ui->pen_77;
        ppp[78] = ui->pen_78;
        ppp[79] = ui->pen_79;
        ppp[80] = ui->pen_80;
        ppp[81] = ui->pen_81;
        ppp[82] = ui->pen_82;
        ppp[83] = ui->pen_83;
        ppp[84] = ui->pen_84;
        ppp[85] = ui->pen_85;
        ppp[86] = ui->pen_86;
        ppp[87] = ui->pen_87;
        ppp[88] = ui->pen_88;
        ppp[89] = ui->pen_89;
        ppp[90] = ui->pen_90;
        ppp[91] = ui->pen_91;
        ppp[92] = ui->pen_92;
        ppp[93] = ui->pen_93;
        ppp[94] = ui->pen_94;
        ppp[95] = ui->pen_95;
        ppp[96] = ui->pen_96;
        ppp[97] = ui->pen_97;
        ppp[98] = ui->pen_98;
        ppp[99] = ui->pen_99;
    }
    for (int i = 0; i <= 99; i++)
        connect(ppp[i], &QPushButton::clicked,
            [=]() {
                const auto &pigs = (*fa)[ppp[i]->penNum];
                std::stringstream ss;
                ss << pigs;
                std::string qs,tmp;
                while (!ss.eof()){
                    std::getline(ss, tmp);
                    tmp.push_back('\n');
                    qs.append(tmp);
                }
                QMessageBox::information(this, QString("%1").arg(ppp[i]->penNum), QString(qs.c_str()));
            });
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_load_clicked()
{
    fa = new farm::Factory("save.txt", "record.txt", farm::Factory::old);
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_begstop_clicked()
{
    if (timer->isActive()) {
        ui->begstop->setText("继续");
        timer->stop();
    }
    else {
        ui->begstop->setText("暂停");
        timer->start(200);
    }
}

void MainWindow::on_returnMain_clicked()
{
    on_begstop_clicked();
    on_save_clicked();
    delete fa;
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_newGame_clicked()
{
    fa = new farm::Factory("save.txt", "record.txt", farm::Factory::newF);
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_save_clicked()
{
    fa->save();
}

void MainWindow::closeEvent(QCloseEvent* event) {
    int ret = QMessageBox::question(this, "question", "是否需要关闭窗口");
    if (ret == QMessageBox::Yes)
        event->accept();
    else
        event->ignore();
}
