# Moving Average
This is an efficient implementation of moving average, optimise for 32 bit calculations, implement uint8/16/32, int 8/16/32 and float types. No dynamic memory usage

# Example code
This is a pseudo-code showing how one can use this library
```c
#define FILTER_WIDTH 8
moving_average_filter_f_t filter;
uint16_t filter_buff[FILTER_WIDTH];

uint16_t ADC_value;
uint16_t ADC_value_filtered;

int main(void){
    moving_average_init_u16(&filter, filter_buff, FILTER_WIDTH);

    while(1){
        ADC_value = ADC_Get_Value();
        moving_average_insert_u16(&filter, h);
        ADC_value_filtered = moving_average_get_u16(&filter);
        printf("%hu", ADC_value_filtered);
    }

    return 0;
}
```
You can change width of filter window by initialize filter with another parameters. Buffer must be equal, or greater, than filter width

# Acknowledgement
I fork and modify this library: https://github.com/mhtb32
