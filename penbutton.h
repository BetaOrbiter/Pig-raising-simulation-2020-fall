#ifndef OENBUTTON_H
#define OENBUTTON_H

#include <QPushButton>

class penButton : public QPushButton
{
    Q_OBJECT
public:
    explicit penButton(QWidget *parent = nullptr): QPushButton(parent){}
    size_t penNum;//该按钮对应的猪圈编号

signals:

private:
};

#endif // OENBUTTON_H
