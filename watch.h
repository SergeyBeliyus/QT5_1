#ifndef WATCH_H
#define WATCH_H

#include <QObject>
#include <QTimer>
#include <QTime>

class Stopwatch : public QObject
{
    Q_OBJECT
public:
    explicit Stopwatch(QObject* parent = nullptr);
    void TimerStart();
    void TimerStop();
    void TimerClear();
    void TimerLap();
    void setTime(float time);
    void setLap(int lap);
    float getCurrentTime();
    float getStartTime();
    int getCurrentLap();
    bool isStart();
    QTimer* getQTimer();

signals:
    void sig_Start();
    void sig_Stop();
    void sig_Clear();
    void sig_Lap();

private:
    bool isStart_;
    float currentTime_;
    float startTime_;
    int currentLap_;
    QTimer* qTimer;
};

#endif
