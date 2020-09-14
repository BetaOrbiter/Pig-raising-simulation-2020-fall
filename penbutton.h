#ifndef OENBUTTON_H
#define OENBUTTON_H

#include <QPushButton>

class penButton : public QPushButton
{
    Q_OBJECT
public:
    explicit penButton(QWidget *parent = nullptr);
    size_t penNum;

signals:

private:
};

#endif // OENBUTTON_H
