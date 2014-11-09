/*
  Sleep.cpp - Arduino Sleep library
  Copyright (c) arms22<arms22 at gmail.com>.  All right reserved.
  
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.
  
  Version 003 20 Oct 2009
*/

#include "Sleep.h"
#include <avr/sleep.h>

#define set_sleep_mode_and_sleep(mode)			\
	do {										\
		cli();									\
		set_sleep_mode(mode);					\
		sleep_enable();							\
		sei();									\
		sleep_cpu();							\
		sleep_disable();						\
	}while(0);

void sleep(unsigned long ms)
{
	uint16_t start = (uint16_t)micros();
	while (ms > 0) {
		if (((uint16_t)micros() - start) >= 1000) {
			ms--;
			start += 1000;
		}else{
            set_sleep_mode_and_sleep(SLEEP_MODE_IDLE);
        }
	}
}

void sleep(void)
{
    set_sleep_mode_and_sleep(SLEEP_MODE_IDLE);
}

void powerDown(void)
{
    set_sleep_mode_and_sleep(SLEEP_MODE_PWR_DOWN);
}
