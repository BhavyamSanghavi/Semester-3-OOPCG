#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>
#include <iostream>
#include <QTime>
using namespace std;
QImage img(300,300,QImage::Format_RGB888);
QImage img_1(300,300,QImage::Format_RGB888);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::line_1(int x1, int y1, int x2, int y2)
{
    float dx = x2 - x1;
    float dy = y2 - y1;
    float length;
    if (abs(dx)>abs(dy))  length = abs(dx);
    else length = abs(dy);
    float xinc = dx/length;
    float yinc = dy/length;
    int sign;
    if(dx>0) sign = +1;
    else if(dx == 0) sign = 0;
    else sign = -1;
    float x = x1+0.5*(sign);
    float y = y1+0.5*(sign);
    for(int i = 0; i<= length; i++)
    {
        x = x + xinc;
        y = y + yinc;
        img.setPixel(int(x),int(y),qRgb(255,255,255));
    }
}

void MainWindow::window()
{
    line(100,100,200,100);
    line(200,100,200,200);
    line(200,200,100,200);
    line(100,200,100,100);
}

void MainWindow::outcode_init(int a[], int x, int y)
{
    if(y>200) a[0]=1;
    if(y<100) a[1]=1;
    if(x>200) a[2]=1;
    if(x<100) a[3]=1;
}

void MainWindow::on_pushButton_clicked()
{
    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();
    line(x1,y1,x2,y2);
    window();
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_2_clicked()
{
    window();
    float x,y;
    float m;
    int outcode[4]={0,0,0,0};
    int outcode_1[4]={0,0,0,0};
    outcode_init(outcode,x1,y1);
    outcode_init(outcode_1,x2,y2);

    m=(y2-y1)/(x2-x1);

    if((outcode[0]&outcode_1[0])!=0 || (outcode[1]&outcode_1[1])!=0 || (outcode[2]&outcode_1[2])!=0 || (outcode[3]&outcode_1[3])!=0)
    {
        line_1(x1,y1,x2,y2);
    }

    else{
        if(outcode[3]==1)
        {
            y=m*(100-x2)+y2;
            line_1(100,y,x2,y2);
        }
        else if(outcode_1[3]==1)
        {
            y=m*(100-x2)+y2;
            line_1(100,y,x1,y1);
        }
        else if(outcode[2]==1)
        {
            y=m*(200-x2)+y2;
            line_1(200,y,x2,y2);
        }
        else if(outcode_1[2]==1)
        {
            y=m*(200-x2)+y2;
            line_1(200,y,x1,y1);
        }
        else if(outcode[1]==1)
        {
            x=x2+(100-y2)/m;
            line_1(x,100,x2,y2);
        }
        else if(outcode_1[1]==1)
        {
            x=x2+(100-y2)/m;
            line_1(x,100,x1,y1);
        }
        else if(outcode[0]==1)
        {
            x=x2+(100-y2)/m;
            line_1(x,200,x2,y2);
        }
        else if(outcode_1[0]==1)
        {
            x=x2+(100-y2)/m;
            line_1(x,200,x1,y1);
        }
    }
    ui->label_2->setPixmap(QPixmap::fromImage(img_1));
}
