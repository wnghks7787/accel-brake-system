#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include "vehicle_state.h"

#define SPEED (3)
#define STOP (0)
#define MAX_SPEED (200)

class Vehicle
{
private:
    int32_t speed;
    VehicleState state;

    static Vehicle instance;

    Vehicle();
    ~Vehicle();


public:

    void setSpeed(int32_t speed);
    int32_t getSpeed();

    void setState(VehicleState state);
    VehicleState getState();

    void gainSpeed();
    void lossSpeed(int32_t loss_speed);

    static Vehicle& getInstance();

    Vehicle(const Vehicle&) = delete;
    Vehicle operator=(const Vehicle&) = delete;
};

#endif // VEHICLE_H