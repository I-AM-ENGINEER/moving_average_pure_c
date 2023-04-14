/**
  ******************************************************************************
  * @file	 moving_average.c
  * @author	 Mohammad Hussein Tavakoli Bina, Sepehr Hashtroudi
  * @brief	 This file contains an efficient implementation of
	*					 moving average filter.
  ******************************************************************************
	*MIT License
	*
	*Copyright (c) 2018 Mohammad Hussein Tavakoli Bina
	*
	*Permission is hereby granted, free of charge, to any person obtaining a copy
	*of this software and associated documentation files (the "Software"), to deal
	*in the Software without restriction, including without limitation the rights
	*to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	*copies of the Software, and to permit persons to whom the Software is
	*furnished to do so, subject to the following conditions:
	*
	*The above copyright notice and this permission notice shall be included in all
	*copies or substantial portions of the Software.
	*
	*THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	*IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	*FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	*AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	*LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	*OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	*SOFTWARE.
  */

#include "moving_average.h"
#include <string.h>

/******************************* int32 *******************************************/

moving_average_state_t moving_average_init_i32( moving_average_filter_i32_t* filter,\
											int32_t* buffer, uint32_t window_size ){
	if(filter == NULL){
		return MOVING_AVERAGE_STATE_ERROR;
	}
	if(buffer == NULL){
		return MOVING_AVERAGE_STATE_ERROR;
	}
	if(window_size == 0){
		return MOVING_AVERAGE_STATE_ERROR;
	}
	filter->sum = 0;
	filter->current_idx = 0;
	filter->window_size = window_size;
	filter->buffer = buffer;
	memset(filter->buffer, 0, filter->window_size*sizeof(int32_t));
	return MOVING_AVERAGE_STATE_OK;
}

void moving_average_insert_i32( moving_average_filter_i32_t* filter, int32_t value ){
	if(filter == NULL){
		return;
	}
	filter->sum += value - filter->buffer[filter->current_idx];
	filter->buffer[filter->current_idx] = value;
	filter->current_idx++;
	if(filter->current_idx >= filter->window_size){
		filter->current_idx = 0;
	}
}

int32_t moving_average_get_i32( moving_average_filter_i32_t* filter ){
	if(filter == NULL){
		return 0;
	}
	return filter->sum/((int32_t)filter->window_size);
}

/******************************* int16 *******************************************/

moving_average_state_t moving_average_init_i16( moving_average_filter_i16_t* filter,\
											int16_t* buffer, uint32_t window_size ){
	if(filter == NULL){
		return MOVING_AVERAGE_STATE_ERROR;
	}
	if(buffer == NULL){
		return MOVING_AVERAGE_STATE_ERROR;
	}
	if(window_size == 0){
		return MOVING_AVERAGE_STATE_ERROR;
	}
	filter->sum = 0;
	filter->current_idx = 0;
	filter->window_size = window_size;
	filter->buffer = buffer;
	memset(filter->buffer, 0, filter->window_size*sizeof(int16_t));
	return MOVING_AVERAGE_STATE_OK;
}

void moving_average_insert_i16( moving_average_filter_i16_t* filter, int16_t value ){
	if(filter == NULL){
		return;
	}
	filter->sum += (int32_t)value - (int32_t)filter->buffer[filter->current_idx];
	filter->buffer[filter->current_idx] = value;
	filter->current_idx++;
	if(filter->current_idx >= filter->window_size){
		filter->current_idx = 0;
	}
}

int16_t moving_average_get_i16( moving_average_filter_i16_t* filter ){
	if(filter == NULL){
		return 0;
	}
	return filter->sum/((int32_t)filter->window_size);
}

/******************************* int8  *******************************************/

moving_average_state_t moving_average_init_i8( moving_average_filter_i8_t* filter,\
											int8_t* buffer, uint32_t window_size ){
	if(filter == NULL){
		return MOVING_AVERAGE_STATE_ERROR;
	}
	if(buffer == NULL){
		return MOVING_AVERAGE_STATE_ERROR;
	}
	if(window_size == 0){
		return MOVING_AVERAGE_STATE_ERROR;
	}
	filter->sum = 0;
	filter->current_idx = 0;
	filter->window_size = window_size;
	filter->buffer = buffer;
	memset(filter->buffer, 0, filter->window_size*sizeof(int8_t));
	return MOVING_AVERAGE_STATE_OK;
}

void moving_average_insert_i8( moving_average_filter_i8_t* filter, int8_t value ){
	if(filter == NULL){
		return;
	}
	filter->sum += (int32_t)value - (int32_t)filter->buffer[filter->current_idx];
	filter->buffer[filter->current_idx] = value;
	filter->current_idx++;
	if(filter->current_idx >= filter->window_size){
		filter->current_idx = 0;
	}
}

int8_t moving_average_get_i8( moving_average_filter_i8_t* filter ){
	if(filter == NULL){
		return 0;
	}
	return filter->sum/((int32_t)filter->window_size);
}

/******************************* uint32 ******************************************/

moving_average_state_t moving_average_init_u32( moving_average_filter_u32_t* filter,\
											uint32_t* buffer, uint32_t window_size ){
	if(filter == NULL){
		return MOVING_AVERAGE_STATE_ERROR;
	}
	if(buffer == NULL){
		return MOVING_AVERAGE_STATE_ERROR;
	}
	if(window_size == 0){
		return MOVING_AVERAGE_STATE_ERROR;
	}
	filter->sum = 0;
	filter->current_idx = 0;
	filter->window_size = window_size;
	filter->buffer = buffer;
	memset(filter->buffer, 0, filter->window_size*sizeof(uint32_t));
	return MOVING_AVERAGE_STATE_OK;
}

void moving_average_insert_u32( moving_average_filter_u32_t* filter, uint32_t value ){
	if(filter == NULL){
		return;
	}
	filter->sum += value - filter->buffer[filter->current_idx];
	filter->buffer[filter->current_idx] = value;
	filter->current_idx++;
	if(filter->current_idx >= filter->window_size){
		filter->current_idx = 0;
	}
}

uint32_t moving_average_get_u32( moving_average_filter_u32_t* filter ){
	if(filter == NULL){
		return 0;
	}
	return filter->sum/((int32_t)filter->window_size);
}

/******************************* uint16 ******************************************/

moving_average_state_t moving_average_init_u16( moving_average_filter_u16_t* filter,\
											uint16_t* buffer, uint32_t window_size ){
	if(filter == NULL){
		return MOVING_AVERAGE_STATE_ERROR;
	}
	if(buffer == NULL){
		return MOVING_AVERAGE_STATE_ERROR;
	}
	if(window_size == 0){
		return MOVING_AVERAGE_STATE_ERROR;
	}
	filter->sum = 0;
	filter->current_idx = 0;
	filter->window_size = window_size;
	filter->buffer = buffer;
	memset(filter->buffer, 0, filter->window_size*sizeof(uint16_t));
	return MOVING_AVERAGE_STATE_OK;
}

void moving_average_insert_u16( moving_average_filter_u16_t* filter, uint16_t value ){
	if(filter == NULL){
		return;
	}
	filter->sum += (int32_t)value - (int32_t)filter->buffer[filter->current_idx];
	filter->buffer[filter->current_idx] = value;
	filter->current_idx++;
	if(filter->current_idx >= filter->window_size){
		filter->current_idx = 0;
	}
}

uint16_t moving_average_get_u16( moving_average_filter_u16_t* filter ){
	if(filter == NULL){
		return 0;
	}
	return filter->sum/((int32_t)filter->window_size);
}

/******************************* uint8	******************************************/

moving_average_state_t moving_average_init_u8( moving_average_filter_u8_t* filter,\
											uint8_t* buffer, uint32_t window_size ){
	if(filter == NULL){
		return MOVING_AVERAGE_STATE_ERROR;
	}
	if(buffer == NULL){
		return MOVING_AVERAGE_STATE_ERROR;
	}
	if(window_size == 0){
		return MOVING_AVERAGE_STATE_ERROR;
	}
	filter->sum = 0;
	filter->current_idx = 0;
	filter->window_size = window_size;
	filter->buffer = buffer;
	memset(filter->buffer, 0, filter->window_size*sizeof(uint8_t));
	return MOVING_AVERAGE_STATE_OK;
}

void moving_average_insert_u8( moving_average_filter_u8_t* filter, uint8_t value ){
	if(filter == NULL){
		return;
	}
	filter->sum += (int32_t)value - (int32_t)filter->buffer[filter->current_idx];
	filter->buffer[filter->current_idx] = value;
	filter->current_idx++;
	if(filter->current_idx >= filter->window_size){
		filter->current_idx = 0;
	}
}

uint8_t moving_average_get_u8( moving_average_filter_u8_t* filter ){
	if(filter == NULL){
		return 0;
	}
	return filter->sum/((int32_t)filter->window_size);
}

/******************************* float	******************************************/

moving_average_state_t moving_average_init_f( moving_average_filter_f_t* filter,\
											float* buffer, uint32_t window_size ){
	if(filter == NULL){
		return MOVING_AVERAGE_STATE_ERROR;
	}
	if(buffer == NULL){
		return MOVING_AVERAGE_STATE_ERROR;
	}
	if(window_size == 0){
		return MOVING_AVERAGE_STATE_ERROR;
	}
	filter->sum = 0;
	filter->current_idx = 0;
	filter->window_size = window_size;
	filter->buffer = buffer;
	memset(filter->buffer, 0, filter->window_size*sizeof(float));
	return MOVING_AVERAGE_STATE_OK;
}

void moving_average_insert_f( moving_average_filter_f_t* filter, float value ){
	if(filter == NULL){
		return;
	}
	filter->sum += value - filter->buffer[filter->current_idx];
	filter->buffer[filter->current_idx] = value;
	filter->current_idx++;
	if(filter->current_idx >= filter->window_size){
		filter->current_idx = 0;
	}
}

float moving_average_get_f( moving_average_filter_f_t* filter ){
	if(filter == NULL){
		return 0;
	}
	return filter->sum/filter->window_size;
}
