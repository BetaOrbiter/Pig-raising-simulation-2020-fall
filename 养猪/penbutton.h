#ifndef OENBUTTON_H
#define OENBUTTON_H

#include <QPushButton>

class penButton : public QPushButton
{
    Q_OBJECT
public:
    explicit penButton(QWidget *parent = nullptr);
    int penNum;

signals:

private:
    static int count;
};

#endif // OENBUTTON_H
