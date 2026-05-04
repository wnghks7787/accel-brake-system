#include <wiringPi.h>
#include <iostream>

int main()
{
	int32_t retVal = wiringPiSetup();
	if(retVal == -1)
	{
		std::cout << "초기화 실패" << std::endl;
		return -1;
	}
	std::cout << "핀 번호 설정을 시작합니다." << std::endl;
	
	return 0;
}
