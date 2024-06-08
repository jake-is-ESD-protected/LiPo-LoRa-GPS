#include <Arduino.h>
#ifdef APP_LORA_SEND
#include "gps.h"
GPS gps(10);
#endif
#ifdef APP_LORA_RECEIVE
#include "gateway.h"
#endif

void setup(){
  #ifdef APP_LORA_SEND
  gps.init();
  #endif
  #ifdef APP_LORA_RECEIVE
  gateway_init();
  #endif
}

void loop(){
  #ifdef APP_LORA_SEND
  uint32_t lat = gps.get_lat();
  uint32_t lng = gps.get_lng();
  delay(500);
  #endif
  #ifdef APP_LORA_RECEIVE
  gateway_run();
  #endif
}
