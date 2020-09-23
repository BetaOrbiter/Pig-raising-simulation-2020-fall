#ifndef PEN_H
#define PEN_H

#include <QWidget>
#include "Pigs.h"
namespace Ui {
class pen;
}

class pen : public QWidget
{
    Q_OBJECT

public:
    explicit pen(const farm::Pigs &ps ,QWidget *parent = nullptr);
    ~pen();

private:
    Ui::pen *ui;
    const farm::Pigs& pigs;
};

#endif // PEN_H
