/**
  ******************************************************************************
  * @file    moving_average.h
  * @author  Mohammad Hussein Tavakoli Bina, Sepehr Hashtroudi.
  * @brief   This file contains function prototype of moving average filter.
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

#ifndef MOVING_AVERAGE_H
#define MOVING_AVERAGE_H

#include <stdint.h>

typedef struct{
	int32_t*	buffer;
	int32_t		sum;
	uint32_t	window_size;
	uint32_t	current_idx;
} moving_average_filter_i32_t;

typedef struct{
	int16_t*	buffer;
	int32_t		sum;
	uint32_t	window_size;
	uint32_t	current_idx;
} moving_average_filter_i16_t;

typedef struct{
	int8_t*		buffer;
	int32_t		sum;
	uint32_t	window_size;
	uint32_t	current_idx;
} moving_average_filter_i8_t;

typedef struct{
	uint32_t*	buffer;
	uint32_t	sum;
	uint32_t	window_size;
	uint32_t	current_idx;
} moving_average_filter_u32_t;

typedef struct{
	uint16_t*	buffer;
	uint32_t	sum;
	uint32_t	window_size;
	uint32_t	current_idx;
} moving_average_filter_u16_t;

typedef struct{
	uint8_t*	buffer;
	uint32_t	sum;
	uint32_t	window_size;
	uint32_t	current_idx;
} moving_average_filter_u8_t;

typedef struct{
	float*	    buffer;
	float	    sum;
	uint32_t	window_size;
	uint32_t	current_idx;
} moving_average_filter_f_t;

typedef enum{
	MOVING_AVERAGE_STATE_OK,
	MOVING_AVERAGE_STATE_ERROR
} moving_average_state_t;

/**
  * @brief  This function initializes filter's data structure
	* @param  filter : Data structure
  * @retval State of initialization
  */
moving_average_state_t moving_average_init_i32( moving_average_filter_i32_t* filter, int32_t*  buffer, uint32_t window_size );
moving_average_state_t moving_average_init_i16( moving_average_filter_i16_t* filter, int16_t*  buffer, uint32_t window_size );
moving_average_state_t moving_average_init_i8 ( moving_average_filter_i8_t*  filter, int8_t*   buffer, uint32_t window_size );
moving_average_state_t moving_average_init_u32( moving_average_filter_u32_t* filter, uint32_t* buffer, uint32_t window_size );
moving_average_state_t moving_average_init_u16( moving_average_filter_u16_t* filter, uint16_t* buffer, uint32_t window_size );
moving_average_state_t moving_average_init_u8 ( moving_average_filter_u8_t*  filter, uint8_t*  buffer, uint32_t window_size );
moving_average_state_t moving_average_init_f  ( moving_average_filter_f_t*   filter, float*    buffer, uint32_t window_size );

/**
  * @brief  This function filters data with moving average filter
	* @param  filter : Data structure
	* @param  value : value for insert to buffer
  * @retval None
  */
void moving_average_insert_i32( moving_average_filter_i32_t* filter, int32_t  value );
void moving_average_insert_i16( moving_average_filter_i16_t* filter, int16_t  value );
void moving_average_insert_i8 ( moving_average_filter_i8_t*  filter, int8_t   value );
void moving_average_insert_u32( moving_average_filter_u32_t* filter, uint32_t value );
void moving_average_insert_u16( moving_average_filter_u16_t* filter, uint16_t value );
void moving_average_insert_u8 ( moving_average_filter_u8_t*  filter, uint8_t  value );
void moving_average_insert_f  ( moving_average_filter_f_t*   filter, float    value );

/**
  * @brief  This function return filtered value
  * @param  filter : Data structure
  * @retval Filtered value
  */
int32_t  moving_average_get_i32( moving_average_filter_i32_t* filter );
int16_t  moving_average_get_i16( moving_average_filter_i16_t* filter );
int8_t   moving_average_get_i8 ( moving_average_filter_i8_t*  filter );
uint32_t moving_average_get_u32( moving_average_filter_u32_t* filter );
uint16_t moving_average_get_u16( moving_average_filter_u16_t* filter );
uint8_t  moving_average_get_u8 ( moving_average_filter_u8_t*  filter );
float    moving_average_get_f  ( moving_average_filter_f_t*   filter );

#endif
