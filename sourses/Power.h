#ifndef __POWER_H
#define __POWER_H

//AXP173��Դ����оƬ

#include "ONboard_IIC.h"

extern unsigned char xdata powerStat;


extern void powerInit();
extern void getBatteryState();


#endif
