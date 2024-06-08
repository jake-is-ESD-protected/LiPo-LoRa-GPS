#include <Arduino.h>
#ifdef ARDUINO_AVR_LEONARDO
#include "gps.h"
#endif
#ifdef WIFI_LORA_32_V3
#include "gateway.h"
#endif

#ifdef ARDUINO_AVR_LEONARDO
GPS gps(10);
#endif

void setup(){
  #ifdef ARDUINO_AVR_LEONARDO
  gps.init();
  #endif
  #ifdef WIFI_LORA_32_V3
  gateway_init();
  #endif
}

void loop(){
  #ifdef ARDUINO_AVR_LEONARDO
  uint32_t lat = gps.get_lat();
  uint32_t lng = gps.get_lng();
  delay(500);
  #endif
  #ifdef WIFI_LORA_32_V3
  gateway_run();
  #endif
  #ifdef WIFI_LORA_32_V3
  gateway_run();
  #endif
}
