#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "watch.h"

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
    void RcvSignalShowTime();
    void RcvSignalStart();
    void RcvSignalStop();
    void RcvSignalClear();
    void RcvSignalLap();

    void on_btn_start_pressed();
    void on_btn_clear_pressed();
    void on_btn_lap_pressed();

private:
    Ui::MainWindow *ui;
    Stopwatch* sw;
};
#endif
