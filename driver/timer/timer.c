#include <stdio.h>
#include "irq.h"

#define TIMER_BASE  (0x51000000)
#define TCFG0   (*(volatile unsigned int *)(TIMER_BASE+0x0))
#define TCFG1   (*(volatile unsigned int *)(TIMER_BASE+0x4))
#define TCON    (*(volatile unsigned int *)(TIMER_BASE+0x8))
#define TCNTB4  (*(volatile unsigned int *)(TIMER_BASE+0x3c))

void timer_handler(void)
{
	static int count = 0;
	if(count%10 == 0)
//	printf("Hello, I am timer handler:%d\n", count);
//	count ++;
	_tx_timer_interrupt();	
}

void timer_init(void)
{

	register_irq_handler(TIMER4_OFFSET, timer_handler);

	TCFG0 &= 0xFF00FF;
	TCFG0 |= 0xf900;        // prescaler����249
	TCFG1 &= ~0xF0000;    
	TCFG1 |= 0x30000;     //divider����8�������ö�ʱ��4��ʱ��Ƶ��Ϊ25kHz
	TCNTB4 = 1000;              //�ö�ʱ��4ÿ��0.5���ж�һ��
	TCON &= ~0xF00000;
	TCON |= 0x700000;
	TCON &= ~0x200000 ;              //��ʱ��4��ʼ����

//	enable_irq();
}