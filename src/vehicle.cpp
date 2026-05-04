#include "vehicle.h"

#define SPEED (5)
#define STOP (0)
#define MAX_SPEED (200)

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
void Vehicle::lossSpeed()
{
    if(speed > STOP)
    {
        speed -= SPEED;
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