#include "lineedit.h"

LineEdit::LineEdit(QMainWindow *parent) : QLineEdit(parent)
{

}

LineEdit::LineEdit(int id, QMainWindow *parent)
{
    setID(id);
}

void LineEdit::set(int x, int y, int w, int h)
{
    setGeometry(x,y,w,h);
}

void LineEdit::show()
{
    QLineEdit::show();
}

void LineEdit::setID(int i)
{
    id = i;
}

int LineEdit::ID()
{
    return id;
}
