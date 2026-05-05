#include "periodic_timer.h"

#include <cstdint>

PeriodicTimer::PeriodicTimer(uint32_t interval_ms)
    : interval(std::chrono::milliseconds(interval_ms)), last_time(std::chrono::steady_clock::now())
{

}

bool PeriodicTimer::isReady()
{
    auto current_time = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(current_time - last_time);

    if(elapsed >= interval)
    {
        last_time = current_time;
        return true;
    }
    return false;
}