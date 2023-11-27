#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>
#include <iostream>
#include <QTime>
#include <QMouseEvent>
using namespace std;
QImage img(500,500,QImage::Format_RGB888);
QColor color = qRgb(255,255,255);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    start = true;
    count = 0;
}
void delay(int millisecondsToWait)
{
    QTime dieTime = QTime::currentTime().addMSecs( millisecondsToWait);
    while(QTime::currentTime()<dieTime)
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    color = QColorDialog::getColor();
}

void MainWindow::line(int x1, int y1, int x2, int y2)
{
    float dx = x2 - x1;
    float dy = y2 - y1;
    float length;
    if (abs(dx)>abs(dy)){
        length = abs(dx);
    }
    else {
        length = abs(dy);
    }

    float xinc = dx/length;
    float yinc = dy/length;

    float x = x1;
    float y = y1;

    for(int i = 0; i<= length; i++){

        x = x + xinc;
        y = y + yinc;
        img.setPixel(x,y,color.rgb());
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(start)
    {
        int p = event->pos().x();
        int q = event->pos().y();
        a[count]=p;
        b[count]=q;
        if(event->button()==Qt::RightButton)
        {
            line(a[count-1],b[count-1],a[0],b[0]);
            line(a[count-1]+1,b[count-1]+1,a[0]+1,b[0]+1);
            start=false;
            cout<<"final"<<endl;
        }
        else
        {
            if(count>0)
            {
                line(a[count],b[count],a[count-1],b[count-1]);
                line(a[count]+1,b[count]+1,a[count-1]+1,b[count-1]+1);
            }
            count++;
        }
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    a[count] = a[0];
    b[count] = b[0];
    for(i=0; i<count; i++)
    {
        float dy = b[i+1]-b[i];
        float dx = a[i+1]-a[i];
        if(dy==0.0f) slope[i] = 1.0;
        if(dx==0.0f) slope[i] = 0.0;
        if((dy!=0.0f)&&(dx!=0.0f))
        {
            slope[i]=dx/dy;
        }
    }
    for(int y=0; y<500; y++)
    {
        k=0;
        for(i=0; i<count; i++)
        {
            if(((b[i]<=y)&&(b[i+1]>y))||((b[i]>y)&&(b[i+1]<=y)))
            {
                xi[k]=int(a[i]+slope[i]*(y-b[i]));
                k++;
            }
        }
        for(j=0; j<k-1; j++)
        {
            for(i=0;i<k-j-1;i++)
            {
                if(xi[i+1]>xi[i]){
                    temp=xi[i];
                    xi[i]=xi[i+1];
                    xi[i+1]=temp;
                }
            }
        }
        for(i=0; i<k; i+=2)
        {
            delay(20);
            line(xi[i],y,xi[i+1],y);
        }
    }
}

--------------- Header --------------------------------

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
    void line(int, int, int, int);
    void mousePressEvent(QMouseEvent *event);
    void on_pushButton_2_clicked();
private:

    Ui::MainWindow *ui;
    int count;
    bool start;
    int a[100],b[100],ver,i,xi[20],j,temp,k,m,n;
    float slope[20];
};

#endif // MAINWINDOW_H
