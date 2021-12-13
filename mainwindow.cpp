#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "lineedit.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setGeometry(100,100,800,600);


    connect(ui->pushButton,&QPushButton::clicked,this,[this]{
        if(all.size()>5)
            return;

       auto obj = LineEdit::staticMetaObject.newInstance(Q_ARG(QMainWindow*,this));
       if(obj == nullptr){
           qDebug()<<"obj is null";
           return;
       }
       QMetaObject::invokeMethod(obj, "setID",Q_ARG(int,count));
       all.insert(count,obj);
       count++;
       QMetaObject::invokeMethod(obj, "set",Q_ARG(int,0),Q_ARG(int,curr),Q_ARG(int,100),Q_ARG(int,h));
       QMetaObject::invokeMethod(obj, "show");
       curr += h+dh;

       connect(qobject_cast<QLineEdit*>(obj),&QLineEdit::textChanged,this,
               [obj](const QString&str)
       {
            int currCount;
            QMetaObject::invokeMethod(obj, "ID",Q_RETURN_ARG(int,currCount));
            //qDebug()<<currCount<<": "<<str;
       });


    });

    connect(ui->pushButton_2,&QPushButton::clicked,this,[this]{
        if(all.empty())
            return ;

        auto obj = all.last();
        delete obj;
        all.remove(all.lastKey());
        count--;
        curr -= h+dh;
    });


    connect(ui->pushButton_3,&QPushButton::clicked,this,[this]{
        QString str;
        for(auto p=all.begin();p!=all.end();p++){
            QString tmp;
            QMetaObject::invokeMethod(p.value(), "getText",Q_RETURN_ARG(QString,tmp));
            str+=tmp;
        }
        qDebug()<<str;
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

