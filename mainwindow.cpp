#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"
#include <QPainter>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    hMin = 0.0f;
    hMax = 0.0f;
    sMin = 0.0f;
    sMax = 1.0f;
    yMin = 30;
    yMax = 230;
    ui->colwheel->show();
    update();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update(){
    QImage img(200, 200, QImage::Format_RGB32);
    QTextStream out(stdout);
    //out << "Here\n";
    bool display;
    for (int i = 0; i < 200; i++)
    {
        for (int j = 0; j < 200; j++)
        {
            float dist = sqrt((i - 100) * (i - 100) + (j - 100) * (j - 100));
            if (dist < 100.0)
            {
                display = true;
                float s = dist / 100.0f;
                float h = atan2(i - 100, j - 100) / (2.0f * 3.14156);
                if (h < 0)
                {
                    h = 1.0f + h;
                }
                if (hMax > hMin)
                {
                    if (hMin > h || hMax < h)
                    {
                        display = false;
                    }
                } else if (hMin > h && hMax < h )
                {
                    display = false;
                }
                if (s < sMin || s > sMax)
                {
                    display = false;
                }
                QColor c;
                if (display)
                {
                    c.setHsvF(h, s, 0.75f);
                } else{
                    c.setHsvF(0.0, 0.0, 0.0f);
                }
                img.setPixel(i, j, c.rgb());
            } else{
                //img.setPixel(i, j, 0);
            }
        }
    }
    QPixmap pix;
    pix.convertFromImage(img);
    ui->colwheel->setPixmap(pix);
    ui->colwheel->repaint();

}

void MainWindow::on_hMin_valueChanged(int value)
{
    hMin = (float)value / 100.0f;
    update();
}

void MainWindow::on_hMax_valueChanged(int value)
{
    hMax = (float)value / 100.0f;
    update();
}

void MainWindow::on_sMin_valueChanged(int value)
{
    sMin = (float)value / 100.0f;
    update();
}

void MainWindow::on_sMax_valueChanged(int value)
{
    sMax = (float) value / 100.0f;
    update();
}

void MainWindow::on_yMin_valueChanged(int value)
{
    yMin = value;
}

void MainWindow::on_yMax_valueChanged(int value)
{
    yMax = value;
}
