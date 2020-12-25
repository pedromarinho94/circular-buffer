/*
 * circular_buffer.h
 *
 *  Created on: Apr 4, 2019
 *      Author: Marinho
 */

#ifndef CIRCULAR_BUFFER_H_
#define CIRCULAR_BUFFER_H_

#define BUFFER_MAX 1024

/**
 *  Initialization data structure for circular buffer
 */

typedef struct circular_buffer
{
	volatile uint8_t data[BUFFER_MAX];		//DATA ARRAY
	volatile uint32_t write;				//WRITE_POINTER
	volatile uint32_t read;					//READ_POINTER
	volatile uint32_t N_MAX;				//BUFFER SIZE
}circular_buffer_t;

void buffer_init(volatile circular_buffer_t* cb);
bool buffer_empty(volatile circular_buffer_t* cb);
uint32_t buffer_mask(volatile circular_buffer_t* cb, uint32_t val);
void buffer_write(volatile circular_buffer_t* cb, uint8_t newByte);
uint8_t buffer_read(volatile circular_buffer_t* cb);
bool buffer_full(volatile circular_buffer_t* cb);		//NOT BEING USED
uint32_t buffer_size(volatile circular_buffer_t* cb);	//NOT BEING USED

#endif /* CIRCULAR_BUFFER_H_ */
