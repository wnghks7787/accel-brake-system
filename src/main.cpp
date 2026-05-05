#include <wiringPi.h>
#include <iostream>

#include "vehicle.h"
#include "vehicle_state.h"
#include "periodic_timer.h"


#define GPIO_ACCEL_PIN (27)
#define GPIO_BRAKE_PIN (28)
#define GPIO_BRAKE_LED_PIN (29)

#define LED_ON (1)
#define LED_OFF (0)
#define BUTTON_ON (1)
#define BUTTON_OFF (0)

int main()
{	
	PeriodicTimer physicsTimer(100U);
	// wiringPi 초기화
	int32_t retVal = wiringPiSetup();
	if(retVal == -1)
	{
		std::cout << "초기화 실패" << std::endl;
		return -1;
	}

	// PIN 번호 설정
	std::cout << "핀 번호 설정을 시작합니다." << std::endl;
	pinMode(GPIO_ACCEL_PIN, INPUT);
	pinMode(GPIO_BRAKE_PIN, INPUT);
	pinMode(GPIO_BRAKE_LED_PIN, OUTPUT);
	std::cout << "핀 번호 설정이 완료되었습니다." << std::endl;

	// 실행
	std::cout << "실행 시작" << std::endl;
	Vehicle& vehicle = Vehicle::getInstance();
	while(true)
	{
		// LED 상태
		if(physicsTimer.isReady())
		{
			switch(vehicle.getState())
			{
				case VehicleState::BRAKE:
					digitalWrite(GPIO_BRAKE_LED_PIN, LED_ON);
					vehicle.lossSpeed();
					break;

				case VehicleState::ACCEL:
					digitalWrite(GPIO_BRAKE_LED_PIN, LED_OFF);
					vehicle.gainSpeed();
					break;

				case VehicleState::CREEP:
					digitalWrite(GPIO_BRAKE_LED_PIN, LED_OFF);
					break;

				case VehicleState::FAULT:
					digitalWrite(GPIO_BRAKE_LED_PIN, LED_OFF);
					break;

				default:
					digitalWrite(GPIO_BRAKE_LED_PIN, LED_OFF);
					break;
			}
			std::cout << "\r\033[K현재 속력: " << vehicle.getSpeed() << " km/h" << std::flush;
		}

		if(digitalRead(GPIO_BRAKE_PIN) == BUTTON_ON)
		{
			vehicle.setState(VehicleState::BRAKE);
		}
		else if(digitalRead(GPIO_BRAKE_PIN) == BUTTON_OFF)
		{
			vehicle.setState(VehicleState::CREEP);
		}
		
		if(digitalRead(GPIO_ACCEL_PIN) == BUTTON_ON)
		{
			vehicle.setState(VehicleState::ACCEL);
		}
	}
	
	return 0;
}
