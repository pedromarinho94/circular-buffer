/*
 * circular_buffer.c
 *
 *  Created on: Apr 4, 2019
 *      Author: Marinho
 */

#include "circular_buffer.h"

void buffer_init(volatile circular_buffer_t* cb){


	cb->N_MAX = BUFFER_MAX;
	cb->read=0;
	cb->write=0;

	for(uint32_t i=0; i < cb->N_MAX; i++)
	{
		cb->data[i] = 0;
	}
}

bool buffer_empty(volatile circular_buffer_t* cb){

	return cb->read == cb->write;
}

uint32_t buffer_mask(volatile circular_buffer_t* cb, uint32_t val){

	return val & (cb->N_MAX - 1);
}

void buffer_write(volatile circular_buffer_t* cb, uint8_t newByte){

	cb->data[buffer_mask(cb, cb->write++)] = newByte;

	if( buffer_full(cb) )
		buffer_read(cb);
}

uint8_t buffer_read(volatile circular_buffer_t* cb){

	if( !buffer_empty(cb) )
		return cb->data[buffer_mask(cb, cb->read++)];
}

bool buffer_full(volatile circular_buffer_t* cb){

	return buffer_size(cb) == cb->N_MAX;
}

uint32_t buffer_size(volatile circular_buffer_t* cb){

	return cb->write - cb->read;
}
