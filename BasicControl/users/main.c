#include "main.h"

/**
  * @brief main函数，用于初始化执行主循环等
  * @param None
  * @retval 成功返回0，失败返回错误码
  */
u16 timeRefreshFlag=0;
u16 timedelay=0;
int main()
{

	AppInit();
	All_Init();

	while (1)
	{
//		if (ParaSavingFlag)
//		{
//			ParametersSave();
//			ParaSavingFlag=0;
//		}
		if (timeRefreshFlag)
		{
		SetFrictionWheelSpeed(1500);
		delay_ms(1000);
		SetFrictionWheelSpeed(1450);
		delay_ms(timedelay);
			SetFrictionWheelSpeed(1500);
		timeRefreshFlag=0;
		}
		delay_ms(1000);
		
	}
}

