#ifndef PERIODIC_TIMER_H
#define PERIODIC_TIMER_H
#include <chrono>

class PeriodicTimer
{
public:
    explicit PeriodicTimer(uint32_t interval_ms);
    bool isReady();

private:
    std::chrono::milliseconds interval;
    std::chrono::steady_clock::time_point last_time;
};

#endif // PERIODIC_TIMER_H