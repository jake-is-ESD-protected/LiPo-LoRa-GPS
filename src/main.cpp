#include <Arduino.h>
#ifdef ARDUINO_AVR_LEONARDO
#include "gps.h"
#endif
#ifdef ARDUINO_HELTEC_WIFI_LORA_32_V3
#include "gateway.h"
#endif


void setup(){
  #ifdef ARDUINO_AVR_LEONARDO
  gps_init();
  #endif
  #ifdef ARDUINO_HELTEC_WIFI_LORA_32_V3
  gateway_init();
  #endif
}

void loop(){
  #ifdef ARDUINO_AVR_LEONARDO
  uint32_t longitude = gps_get_lon();
  uint32_t latitude = gps_get_lat();
  #endif
}