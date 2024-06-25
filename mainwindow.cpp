#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    sw = new Stopwatch(this);


    ui->btn_start->setText("Старт");
    ui->btn_clear->setText("Очистить");
    ui->btn_lap->setText("Круг");
    ui->lbl_time->setText("Время: ");
    ui->lbl_time->setText(QString::number(sw->getCurrentTime()) + " сек");
    ui->btn_lap->setEnabled(sw->isStart());

    connect(sw, &Stopwatch::Start, this, &MainWindow::RcvSignalStart);
    connect(sw, &Stopwatch::Stop, this, &MainWindow::RcvSignalStop);
    connect(sw, &Stopwatch::Clear, this, &MainWindow::RcvSignalClear);
    connect(sw, &Stopwatch::Lap, this, &MainWindow::RcvSignalLap);
    connect(sw->getQTimer(), &QTimer::timeout, this, &MainWindow::RcvSignalShowTime);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::RcvSignalStart()
{

}

void MainWindow::RcvSignalStop()
{

}

void MainWindow::RcvSignalClear()
{
    ui->lbl_time->setText(QString::number(sw->getCurrentTime()) + " сек");
    ui->lap_browser->clear();
}

void MainWindow::RcvSignalLap()
{
    ui->lap_browser->append("Круг " + QString::number(sw->getCurrentLap()) + ", время: " +
                            QString::number(sw->getCurrentTime() - sw->getStartTime()) + " сек");
    sw->setLap(sw->getCurrentLap() + 1);
}

void MainWindow::RcvSignalShowTime()
{
    if(sw->isStart())
    {
        ui->lbl_time->setText(QString::number(sw->getCurrentTime()) + " сек");
        sw->setTime(sw->getCurrentTime() + 0.1);
    }
}

void MainWindow::on_btn_start_pressed()
{
    if (!sw->isStart())
    {
        sw->TimerStart();
        ui->btn_start->setText("Стоп");
    }
    else
    {
        sw->TimerStop();
        ui->btn_start->setText("Старт");
    }
    ui->btn_lap->setEnabled(sw->isStart());
}


void MainWindow::on_btn_clear_pressed()
{
    sw->TimerClear();
}


void MainWindow::on_btn_lap_pressed()
{
    sw->TimerLap();
}

