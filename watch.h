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

private:
    bool isStart_;
    float currTime_;
    float startTime_;
    int currLap_;
    QTimer* qTimer;

signals:
    void Start();
    void Stop();
    void Clear();
    void Lap();

};

#endif
