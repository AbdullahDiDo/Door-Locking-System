/*
 * micro_config.h
 *
 *  Created on: Oct 22, 2017
 *      Author: Abdullah
 */


#ifndef MICRO_CONFIG_H_
#define MICRO_CONFIG_H_


#ifndef F_CPU
#define F_CPU 8000000UL //1MHz Clock frequency
#endif  

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#endif /* MICRO_CONFIG_H_ */
