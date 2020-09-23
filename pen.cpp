#include "pen.h"
#include "ui_pen.h"
#include <QLabel>
constexpr char const* colorName[3]{ "black","stripe","white" };
pen::pen(const farm::Pigs &ps,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pen),
    pigs(ps)
{
    ui->setupUi(this);
    QLabel *labels[8];
    labels[0]=ui->label;
    labels[1]=ui->label_2;
    labels[2]=ui->label_3;
    labels[3]=ui->label_4;
    labels[4]=ui->label_5;
    labels[5]=ui->label_6;
    labels[6]=ui->label_7;
    labels[7]=ui->label_8;
    farm::SizeType i;
    for(i=0;i<pigs.size();i++){

        const auto &pig = pigs[i];
        labels[i]->setStyleSheet("QLabel {border-image:url(:/new/prefix1/piggy.jpg)}");
        labels[i]->setText(QString("颜色:%1\n体重:%2\n价值:%3\n")
                           .arg(colorName[pig->getColor()]).arg(pig->getWeight()).arg(pig->getValue()));
    }
}

pen::~pen()
{
    delete ui;
}
