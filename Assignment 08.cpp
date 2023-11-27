#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <cmath>

QImage img(500,500,QImage::Format_RGB888);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    dda(0,250,500,250);
    dda(250,0,250,500);

    ui->label->setPixmap(QPixmap::fromImage(img));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    float x1,x2,y1,y2;
    x1 = ui->textEdit->toPlainText().toInt();
    y1 = ui->textEdit_2->toPlainText().toInt();
    x2 = ui->textEdit_3->toPlainText().toInt();
    y2 = ui->textEdit_4->toPlainText().toInt();

    dda(x1+250,y1+250,x2+250,y2+250);

    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::dda(float x1, float y1, float x2, float y2)
{
    float dx,dy,xinc,yinc;
    float length;

    dx = x2-x1;
    dy = y2-y1;

    if(abs(dx)>abs(dy)){
        length = abs(dx);
    }else{
        length = abs(dy);
    }

    xinc = dx/length;
    yinc = dy/length;
    int i=0;
    while(i<=length){
        img.setPixel(x1,y1,qRgb(255,255,255));
        x1+=xinc;
        y1+=yinc;
        i++;
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    float x1,x2,y1,y2;
    x1 = ui->textEdit->toPlainText().toInt();
    y1 = ui->textEdit_2->toPlainText().toInt();
    x2 = ui->textEdit_3->toPlainText().toInt();
    y2 = ui->textEdit_4->toPlainText().toInt();

    float tx,ty;
    tx = ui->textEdit_5->toPlainText().toInt();
    ty = ui->textEdit_6->toPlainText().toInt();

    float p,q,r,s;

    p = x1+tx;
    q = y1+ty;
    r = x2+tx;
    s = y2+ty;

    dda(p+250,q+250,r+250,s+250);
    ui->label->setPixmap(QPixmap::fromImage(img));

}

void MainWindow::on_pushButton_3_clicked()
{
    float x1,x2,y1,y2;
    x1 = ui->textEdit->toPlainText().toInt();
    y1 = ui->textEdit_2->toPlainText().toInt();
    x2 = ui->textEdit_3->toPlainText().toInt();
    y2 = ui->textEdit_4->toPlainText().toInt();

    float sx,sy;
    sx = ui->textEdit_7->toPlainText().toInt();
    sy = ui->textEdit_8->toPlainText().toInt();

    float p,q,r,s;
    p = x1*sx;
    q = y1*sy;
    r = x2*sx;
    s = y2*sy;

    dda(p+250,q+250,r+250,s+250);
    ui->label->setPixmap(QPixmap::fromImage(img));

}

void MainWindow::on_pushButton_4_clicked()
{
    float x1,x2,y1,y2;
    x1 = ui->textEdit->toPlainText().toInt();
    y1 = ui->textEdit_2->toPlainText().toInt();
    x2 = ui->textEdit_3->toPlainText().toInt();
    y2 = ui->textEdit_4->toPlainText().toInt();


    float angle;
    angle = ui->textEdit_9->toPlainText().toInt();

    angle = angle*(3.142/180);

    float p,q,r,s;
    p = x1*cos(angle) + y1*sin(angle);
    q = -x1*sin(angle) + y1*cos(angle);
    r = x2*cos(angle) + y2*sin(angle);
    s = -x2*sin(angle) + y2*cos(angle);

    dda(p+250,q+250,r+250,s+250);
    ui->label->setPixmap(QPixmap::fromImage(img));
}


// Header file contents
#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_pushButton_clicked();
    void dda(float,float,float,float);


    void on_pushButton_2_clicked();


    void on_pushButton_3_clicked();


    void on_pushButton_4_clicked();


private:
    Ui::MainWindow *ui;


    int xshift = 250,yshift = 250;
};
#endif // MAINWINDOW_H
