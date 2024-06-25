#include "watch.h"

Stopwatch::Stopwatch(QObject *parent)
    : QObject{parent}
{
    isStart_ = false;
    currTime_ = 0.;
    startTime_ = 0.;
    currLap_ = 1;
    qTimer = new QTimer(this);
}

void Stopwatch::TimerStart()
{
    isStart_ = true;
    qTimer->start(100);
    emit Start();
}

void Stopwatch::TimerStop()
{
    isStart_ = false;
    qTimer->stop();
    emit Stop();
}

void Stopwatch::TimerClear()
{
    currTime_ = 0.;
    startTime_ = 0.;
    currLap_ = 1;
    emit Clear();
}

void Stopwatch::TimerLap()
{
    emit Lap();
}

void Stopwatch::setTime(float time)
{
    currTime_ = time;
}

void Stopwatch::setLap(int lap)
{
    currLap_ = lap;
}

float Stopwatch::getCurrentTime()
{
    return currTime_;
}

float Stopwatch::getStartTime()
{
    return startTime_;
}

int Stopwatch::getCurrentLap()
{
    startTime_ = currTime_;
    return currLap_;
}

bool Stopwatch::isStart()
{
    return isStart_;
}

QTimer *Stopwatch::getQTimer()
{
    return qTimer;
}

