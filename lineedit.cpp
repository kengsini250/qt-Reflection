#include "lineedit.h"

LineEdit::LineEdit(QMainWindow *parent) : QLineEdit(parent)
{

}

void LineEdit::set(int x, int y, int w, int h)
{
    setGeometry(x,y,w,h);
}

void LineEdit::show()
{
    QLineEdit::show();
}
