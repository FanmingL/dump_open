#include "main.h"

/**
  * @brief main���������ڳ�ʼ��ִ����ѭ����
  * @param None
  * @retval �ɹ�����0��ʧ�ܷ��ش�����
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

