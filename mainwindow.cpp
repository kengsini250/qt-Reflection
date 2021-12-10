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
       auto obj = LineEdit::staticMetaObject.newInstance(Q_ARG(QMainWindow*,this));
       if(obj == nullptr){
           qDebug()<<"obj is null";
           return;
       }
       QMetaObject::invokeMethod(obj, "set",Q_ARG(int,0),Q_ARG(int,0),Q_ARG(int,100),Q_ARG(int,40));
       QMetaObject::invokeMethod(obj, "show");
    });

    //connect(ui->pushButton_2,&QPushButton::clicked,this,[this]{});


}

MainWindow::~MainWindow()
{
    delete ui;
}

