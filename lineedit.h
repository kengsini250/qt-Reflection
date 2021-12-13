#ifndef LINEEDIT_H
#define LINEEDIT_H

#include <QObject>
#include <QLineEdit>
#include <QMainWindow>

class LineEdit : public QLineEdit
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit LineEdit(QMainWindow *parent = nullptr);
    Q_INVOKABLE explicit LineEdit(int id,QMainWindow *parent = nullptr);
public slots:
    Q_INVOKABLE void set(int x,int y,int w,int h);
    Q_INVOKABLE void show();
    Q_INVOKABLE	void setID(int i);
    Q_INVOKABLE	int ID();
private:
    int id = -1;

};

#endif // LINEEDIT_H
