#ifndef _GPS_H_
#define _GPS_H_

#include <stdint.h>

void gps_init();

uint32_t gps_get_lon();

uint32_t gps_get_lat();

#endif // _GPS_H_