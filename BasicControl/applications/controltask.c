#include "main.h"


//values for PID Calculate.
float GimbalPitchPosRef=0.0f;
float GimbalPitchGyrRef=0.0f;
float GimbalYawPosRef=0.0f;
float GimbalYawGyrRef=0.0f;
float ChassisGoToward=0.0f;
float ChassisGoLeftRight=0.0f;
float ChassisMotorSpeed1,ChassisMotorSpeed2,ChassisMotorSpeed3,ChassisMotorSpeed4;

float ChassisRotateOut=0.0f;
float CMOutput1,CMOutput2,CMOutput3,CMOutput4;
/**
  * @brief ���̿��Ƴ���
  * @param _T�����������(s)
  * @retval None
  * @details 	���ݵ�ǰ�����������ƶ��ٶȺ͵�ǰ���̹���
	*						���ĸ����̵���ĵ������п���
  */
void ChassisControl(float _T)
{	
	if (SysMode!=SYS_CALISTATE&&SysMode!=SYS_STOPSTATE)
	{
		switch(ControlMode)
		{
			case MC_NORMAL:
				ChassisRotateOut=PID_calculate( _T,            //���ڣ���λ���룩
																				0,				//ǰ��ֵ
																				0,				//����ֵ���趨ֵ��
																				GMYawEncoder.ecd_value,			//����ֵ����
																				&Chassis_Rot_PID_arg, //PID�����ṹ��
																				&Chassis_Rot_PID_val,	//PID���ݽṹ��
																				0.2		//integration limit�������޷�
																				 );
				break;
			
			case MC_MODE1:
				
				break;
			
			case MC_MODE2:
				
				break;
			
			default:
				break;
		}
	}
	else
	{
		ChassisRotateOut=0.0f;
		ChassisGoToward=0.0f;
		ChassisGoLeftRight=0.0f;	
	}
	ChassisMotorSpeed1=-ChassisGoToward*0.075f+ChassisGoLeftRight*0.075f+ChassisRotateOut;
	ChassisMotorSpeed2=ChassisGoToward*0.075f+ChassisGoLeftRight*0.075f+ChassisRotateOut;
	ChassisMotorSpeed3=ChassisGoToward*0.075f-ChassisGoLeftRight*0.075f+ChassisRotateOut;
	ChassisMotorSpeed4=-ChassisGoToward*0.075f-ChassisGoLeftRight*0.075f+ChassisRotateOut;
	CMOutput1=PID_calculate( 			_T,            //���ڣ���λ���룩
																0,				//ǰ��ֵ
																ChassisMotorSpeed1,				//����ֵ���趨ֵ��
																CM1Encoder.filter_rate,			//����ֵ����
																&Chassis_Vec_PID_arg, //PID�����ṹ��
																&Chassis_Vec_PID_val1,	//PID���ݽṹ��
															 	0.2		//integration limit�������޷�
																 );
	CMOutput2=PID_calculate( 			_T,            //���ڣ���λ���룩
																0,				//ǰ��ֵ
																ChassisMotorSpeed2,				//����ֵ���趨ֵ��
																CM2Encoder.filter_rate,			//����ֵ����
																&Chassis_Vec_PID_arg, //PID�����ṹ��
																&Chassis_Vec_PID_val2,	//PID���ݽṹ��
																0.2		//integration limit�������޷�
																 );
	CMOutput3=PID_calculate( 			_T,            //���ڣ���λ���룩
																0,				//ǰ��ֵ
																ChassisMotorSpeed3,				//����ֵ���趨ֵ��
																CM3Encoder.filter_rate,			//����ֵ����
																&Chassis_Vec_PID_arg, //PID�����ṹ��
																&Chassis_Vec_PID_val3,	//PID���ݽṹ��
																0.2		//integration limit�������޷�
																 );
	CMOutput4=PID_calculate( 			_T,            //���ڣ���λ���룩
																0,				//ǰ��ֵ
																ChassisMotorSpeed4,				//����ֵ���趨ֵ��
																CM4Encoder.filter_rate,			//����ֵ����
																&Chassis_Vec_PID_arg, //PID�����ṹ��
																&Chassis_Vec_PID_val4,	//PID���ݽṹ��
																0.2		//integration limit�������޷�
																 );

	if (SysMode!=SYS_CALISTATE&&SysMode!=SYS_STOPSTATE)
	{
		ChassisSpeedSet(CAN1,CMOutput1,CMOutput2,CMOutput3,CMOutput4);
	}
	else
	{
		ChassisSpeedSet(CAN1,0,0,0,0);
	}
	//ChassisSpeedSet(CAN1,600,0,0,0);
}

/**
  * @brief ��̨���Ƴ���
  * @param _T�����������
  * @retval None
  * @details ���ݵ�ǰ��̨�������Ƕ�������������̨������������
  */
void GimbalControl(float _T)
{


}

/**
  * @brief ����������Ƴ���
  * @param _T�����������(s)
  * @retval None
  * @details ���ݸ���ң�������������źſ���Ħ���ֺͲ��������ת��
  */
void FireControl(float _T)
{


}

