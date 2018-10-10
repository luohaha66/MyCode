#ifndef __COLLECT_DATA_H
#define __COLLECT_DATA_H
#include "data_type.h"

void collect_data(tem_t *tem,hum_t *hum,light_t *light);
void send_data(uint8_t *data, uint8_t len) ;
void send_data_uart(uint8_t *data, uint8_t len) ;
uint32_t adc_ret(adc_t *adc_c);
void acc_ret(acc_t *acc_r);
void get_state(state_t *state_c);

#endif
