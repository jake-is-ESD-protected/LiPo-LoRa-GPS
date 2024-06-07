#include <Arduino.h>
#include "gps.h"
#include "gateway.h"


void setup(){
  gps_init();
}

void loop(){
  uint32_t longitude = gps_get_lon();
  uint32_t latitude = gps_get_lat();
}