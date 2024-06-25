#include "watch.h"

Stopwatch::Stopwatch(QObject *parent)
    : QObject{parent}
{
    isStart_ = false;
    currentTime_ = 0.;
    startTime_ = 0.;
    currentLap_ = 1;
    qTimer = new QTimer(this);
}

void Stopwatch::TimerStart()
{
    isStart_ = true;
    qTimer->start(100);
    emit sig_Start();
}

void Stopwatch::TimerStop()
{
    isStart_ = false;
    qTimer->stop();
    emit sig_Stop();
}

void Stopwatch::TimerClear()
{
    currentTime_ = 0.;
    startTime_ = 0.;
    currentLap_ = 1;
    emit sig_Clear();
}

void Stopwatch::TimerLap()
{
    emit sig_Lap();
}

void Stopwatch::setTime(float time)
{
    currentTime_ = time;
}

void Stopwatch::setLap(int lap)
{
    currentLap_ = lap;
}

float Stopwatch::getCurrentTime()
{
    return currentTime_;
}

float Stopwatch::getStartTime()
{
    return startTime_;
}

int Stopwatch::getCurrentLap()
{
    startTime_ = currentTime_;
    return currentLap_;
}

bool Stopwatch::isStart()
{
    return isStart_;
}

QTimer *Stopwatch::getQTimer()
{
    return qTimer;
}
