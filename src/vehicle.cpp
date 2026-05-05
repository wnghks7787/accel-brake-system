#include "vehicle.h"

Vehicle::Vehicle()
{
    speed = STOP;
    state = VehicleState::CREEP;
}

Vehicle::~Vehicle()
{

}

void Vehicle::setSpeed(int32_t speed)
{
    this->speed = speed;
}
int32_t Vehicle::getSpeed()
{
    return this->speed;
}

void Vehicle::setState(VehicleState state)
{
    this->state = state;
}
VehicleState Vehicle::getState()
{
    return this->state;
}

void Vehicle::gainSpeed()
{
    if(speed <= MAX_SPEED)
    {
        speed += SPEED;
    }

    if(speed > MAX_SPEED)
    {
        speed = MAX_SPEED;
    }
}
void Vehicle::lossSpeed(int32_t loss_speed)
{
    if(speed > STOP)
    {
        speed -= loss_speed;
    }

    if(speed < STOP)
    {
        speed = STOP;
    }
}

Vehicle& Vehicle::getInstance()
{
    static Vehicle instance;
    return instance;
}