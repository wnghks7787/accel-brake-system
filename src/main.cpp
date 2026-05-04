#include <wiringPi.h>
#include <iostream>
#include "vehicle.h"
#include "vehicle_state.h"

#define GPIO_ACCEL_PIN 27
#define GPIO_BRAKE_PIN 28
#define GPIO_BRAKE_LED_PIN 29

#define LED_ON 1
#define LED_OFF 0
#define BUTTON_ON 1
#define BUTTON_OFF 0

int main()
{
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
	while(1)
	{
		if(vehicle.getState() == VehicleState::BRAKE)
		{
			digitalWrite(GPIO_BRAKE_LED_PIN, LED_ON);
		}
		else
		{
			digitalWrite(GPIO_BRAKE_LED_PIN, LED_OFF);
		}

		if(digitalRead(GPIO_BRAKE_PIN) == BUTTON_ON)
		{
			vehicle.setState(VehicleState::BRAKE);
		}
	}
	
	return 0;
}
