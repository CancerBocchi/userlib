/*��cube����Ҫ��adc usart 
*���ļ���������ʹ��
*�����ֶ�����mylib.h��������Ӧͷ�ļ�����
*/

#include"mylib.h"

/*
* @brief  : ���IO�ڱ仯���� LTHĬ�ϵ͵�ƽ HTLĬ�ϸߵ�ƽ
* @param  : Port IO�˿� Pin ���ű��
* @retval : trueΪ�仯 falseΪ����
*/

_Bool Cancer_JudgeKey_LTH(GPIO_TypeDef *Port,uint16_t Pin)
{
	static uint32_t tick;
	static uint8_t flag = 1;
	if(flag)
	{
		tick = __HAL_TIM_GET_COUNTER(&TIMER);
		flag = 0;
	}
	int a = HAL_GPIO_ReadPin(Port,Pin);
	if(a)
	{
		if(__HAL_TIM_GET_COUNTER(&TIMER) - tick > 1000)
		{
			return true;
		}
		tick = __HAL_TIM_GET_COUNTER(&TIMER);
	}
	return false;
}

_Bool Cancer_JudgeKey_HTL(GPIO_TypeDef *Port,uint16_t Pin)
{
	static uint32_t tick;
	static uint8_t flag = 1;
	if(flag)
	{
		tick = HAL_GetTick();
		flag = 0;
	}
	if(!HAL_GPIO_ReadPin(Port,Pin))
	{
		if(HAL_GetTick() - tick > 100)
		{
			return true;
		}
		tick = HAL_GetTick();
	}
	return false;
}

void Cancer_F_Str(char* buf, float target)
{
	int digit = (int)target;
	int frac = (int)((target - (float)digit) * 1000000);
	if (frac < 10)
		sprintf(buf, "%d.00000%d\n", digit, frac);
	else if (frac < 100 && frac >= 10)
		sprintf(buf, "%d.0000%d\n", digit, frac);
	else if(frac<1000&&frac>=100)
		sprintf(buf, "%d.000%d\n", digit, frac);
	else if(frac<10000&&frac>=1000)
		sprintf(buf, "%d.00%d\n", digit, frac);
	else if(frac<100000&&frac>=10000)
		sprintf(buf, "%d.0%d\n", digit, frac);
	else if(frac<1000000&&frac>=100000)
		sprintf(buf, "%d.%d\n", digit, frac);
}

#ifdef __ADC_H__
/*for��adc��ѯģʽ
* why����װ����
* variable:hadcΪ��Ӧadc�ĵ�ַ timeoutΪ��ʱʱ��
* ��ת����ɷ���adc��ֵ��֮����-1
*/
float Cancer_Get_ADC_Value(ADC_HandleTypeDef* hadc,uint32_t TIMEOUT)
{
	HAL_ADC_Start(hadc);
	HAL_ADC_PollForConversion(hadc,TIMEOUT);
	if(HAL_IS_BIT_SET(HAL_ADC_GetState(hadc),HAL_ADC_STATE_REG_EOC))//�ж��Ƿ��Լ����ת��
	{
		return HAL_ADC_GetValue(hadc)*FACTOR_ADC;
	}
	else
	return FAIL;
}
/*for:��adc��ֵ�Զ�ת��Ϊvalue
*charactor��DMAģʽʱ���ת��
*variable:����Ϊadcֵ����ʵֵ������Ԫ�ظ��� ǰ��������Ԫ�ظ�����������һ��
*ps:��ǰ���ú�dma����
*/
void Cancer_ADC_Real(uint16_t*adc_value,float*real_value,uint16_t num)
{
	for(int i=0;i<num;i++)
	{
		real_value[i]=adc_value[i]*FACTOR_ADC;
	}
}

#endif

#ifdef __USART_H__
/*
* @brief:���ڴ�ӡ����
* @param�����ڱ��
* @param: ����ַ���
*/
void Block_UART_printf(UART_HandleTypeDef*uartbase,const char *format,...)
{
	va_list ap;
	va_start(ap,format);
	int length;
	char buffer[128];
	length=vsnprintf(buffer,128,format,ap);
	HAL_UART_Transmit(uartbase,(uint8_t*)buffer,length,0xffff);
}

void DMA_UART_printf(UART_HandleTypeDef*uartbase,const char *format,...)
{
	va_list ap;
	va_start(ap,format);
	int length;
	char buffer[128];
	length=vsnprintf(buffer,128,format,ap);
	HAL_UART_Transmit_DMA(uartbase,(uint8_t*)buffer,length);
}

void IT_UART_printf(UART_HandleTypeDef*uartbase,const char *format,...)
{
	va_list ap;
	va_start(ap,format);
	int length;
	char buffer[128];
	length=vsnprintf(buffer,128,format,ap);
	HAL_UART_Transmit_IT(uartbase,(uint8_t*)buffer,length);
}

#endif
