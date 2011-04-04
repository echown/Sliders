#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void update();

private slots:
    void on_hMin_valueChanged(int value);

    void on_hMax_valueChanged(int value);

    void on_sMin_valueChanged(int value);

    void on_sMax_valueChanged(int value);

    void on_yMin_valueChanged(int value);

    void on_yMax_valueChanged(int value);

    void on_slice_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    float hMin;
    float hMax;
    float sMin;
    float sMax;
    float zValue;
    int yMin;
    int yMax;
};

#endif // MAINWINDOW_H
