#include "main.h"

/**
  * @brief ����6��ʼ�� 
  * @param BaudRate
  * @retval None
  * @details DMA���ͣ�RXNE�����ж�
  */
void Usart6_Init(u32 br_num)
{ 
	
}

/**
  * @brief ����6�ж�
  * @param None
  * @retval None
  * @details RXNE�жϣ��ɴ˽���Usart6ͨѶЭ�����
  */
void USART6_IRQHandler(void)
{
	u8 com_data;
	
	if(USART6->SR & USART_SR_ORE)
	{
		com_data = USART6->DR;
	}
	if( USART_GetITStatus(USART6,USART_IT_RXNE) )
	{
		USART_ClearITPendingBit(USART6,USART_IT_RXNE);

		com_data = USART6->DR;
		Usart6_DataPrepare(com_data);
	}
}

/**
  * @brief ����6��DMA���ͺ���������һ������
  * @param DataToSend Ҫ�������ݵ������ָ��
	* @param data_num Ҫ���͵����ݵĸ���
  * @retval None
  */
void Usart6_Send(unsigned char *DataToSend ,u8 data_num)
{
  

}


