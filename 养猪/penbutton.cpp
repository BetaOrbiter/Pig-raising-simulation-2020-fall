#include "penbutton.h"

int penButton::count = 0;
penButton::penButton(QWidget *parent) : QPushButton(parent),penNum(count++)
{

}
