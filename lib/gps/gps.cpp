#include "gps.h"
#include <Arduino.h>

void gps_init(){
    Serial.begin(115200);
}

uint32_t gps_get_lon(){
    Serial.write('1234');
    return 0;
}

uint32_t gps_get_lat(){
    
    return 0;
}