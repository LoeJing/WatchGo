#include "Timer.h"
#include "STC8.h"

    unsigned int xdata TickCount=0;
    unsigned int xdata Hour=0;
    unsigned int xdata Minute=0;
    unsigned int xdata Second=0;
    unsigned int xdata preHourH;
    unsigned int xdata preMinuteH;
    bit isHourChange=1;
    bit isMinuteChange=1;
    bit isSecondChange=1;

void Timer0Init(void)		//20����@24.000MHz
{  
    
	EA=1;
    AUXR &= 0x7F;		//��ʱ��ʱ��12Tģʽ
	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
	TMOD |= 0x01;		//���ö�ʱ��ģʽ
	TL0 = 0xC0;		//���ö�ʱ��ֵ
	TH0 = 0x63;		//���ö�ʱ��ֵ
	ET0 = 1;                                    //???????
	TR0 = 1;		//��ʱ��0��ʼ��ʱ
}

void Timer1Init(void)		//20����@24.000MHz
{
	AUXR &= 0xBF;		//��ʱ��ʱ��12Tģʽ
	TMOD &= 0x0F;		//���ö�ʱ��ģʽ
	TMOD |= 0x10;		//���ö�ʱ��ģʽ
	TL1 = 0xC0;		//���ö�ʱ��ֵ
	TH1 = 0x63;		//���ö�ʱ��ֵ
	TF1 = 0;		//���TF1��־
    ET1=1;
	TR1 = 0;		//��ʱ��1����ʱ
}


void Tick_20msIsr() interrupt 1
{
    TickCount++;
    if(TickCount==50)
    {
        Second++;
        isSecondChange=1;
        TickCount=0;
        if(Second==60)
        {
            Minute++;
            isMinuteChange=1;
            Second=0;
            if(Minute==60)
            {
                Hour++;
                isHourChange=1;
                Minute=0;

            }
        }
    }

	TL0 = 0xC0;		//���ö�ʱ��ֵ
	TH0 = 0x63;		//���ö�ʱ��ֵ


}


