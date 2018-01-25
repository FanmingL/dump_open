#include "main.h"

/**
  * @brief ����3��ʼ�� 
  * @param BaudRate
  * @retval None
  * @details	PD8	Tx
	*						PD9	Rx
	*						BaudRate	115200
	*						ʹ��DMA���ͣ�RXNE�ж�
  */
void Usart3_Init(u32 br_num)
{ 
	
}

/**
  * @brief ����3�ж�
  * @param None
  * @retval None
  * @details RXNE�жϣ��ɴ˽���Usart3ͨѶЭ�����
  */
void USART3_IRQHandler(void)
{
	u8 com_data;
	
	if(USART3->SR & USART_SR_ORE)
	{
		com_data = USART3->DR;
	}
	if( USART_GetITStatus(USART3,USART_IT_RXNE) )
	{
		USART_ClearITPendingBit(USART3,USART_IT_RXNE);

		com_data = USART3->DR;
		Usart3_DataPrepare(com_data);
	}
}

/**
  * @brief ����3��DMA���ͺ���������һ������
  * @param DataToSend Ҫ�������ݵ������ָ��
	* @param data_num Ҫ���͵����ݵĸ���
  * @retval None
  */
void Usart3_Send(unsigned char *DataToSend ,u8 data_num)
{
  

}


