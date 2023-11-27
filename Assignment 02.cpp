#include "mainwindow.h"
#include "ui_mainwindow.h"
QImage img(500,500,QImage::Format_RGB888);
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



void MainWindow::on_pushButton_clicked()
{
    int x1,y1,x2,y2,x3,y3;
    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();
    x3=ui->textEdit_5->toPlainText().toInt();
    y3=ui->textEdit_6->toPlainText().toInt();
    r1=ui->textEdit_7->toPlainText().toFloat();
    r2=ui->textEdit_8->toPlainText().toFloat();
    cx=ui->textEdit_9->toPlainText().toFloat();
    cy=ui->textEdit_10->toPlainText().toFloat();
    circle(cx,cy,r1);
    circle(cx,cy,r2);
    DDA(x1,y1,x2,y2);
    DDA(x1,y1,x3,y3);
    DDA(x2,y2,x3,y3);
    ui->label->setPixmap(QPixmap::fromImage(img));
}
void MainWindow::DDA(int x1,int y1,int x2,int y2)
{
    float dx,dy,len,xin,yin;
    dx=x2-x1;
    dy=y2-y1;
    if(abs(dx)>=abs(dy))    len=abs(dx);
    else len=abs(dy);
    xin=dx/len;
    yin=dy/len;
    int i=0,x=x1,y=y1;
    while(i<len)
    {
        img.setPixel(x,y,qRgb(255,255,255));
        x+=xin;
        y+=yin;
        i++;
    }
}
void MainWindow::circle(float p, float q, float r)
{
    float x=0,y=r,d3-(2*r);
    while(x<y)
    {
        img.setPixel(y+p,x+q,qRgb(255,255,255));
        img.setPixel(x+p,y+q,qRgb(255,255,255));
        img.setPixel(-x+p,y+q,qRgb(255,255,255));
        img.setPixel(-y+p,x+q,qRgb(255,255,255));
        img.setPixel(-y+p,-x+q,qRgb(255,255,255));
        img.setPixel(-x+p,-y+q,qRgb(255,255,255));
        img.setPixel(x+p,-y+q,qRgb(255,255,255));
        img.setPixel(y+p,-x+q,qRgb(255,255,255));
        if(d<0)
        {
            d=d+x*4+6;
            x=x+1;
        }
        else
        {
            d=d+4*(x-y)+10;
            x=x+1;
            y=y-1;
        }
    }

}
