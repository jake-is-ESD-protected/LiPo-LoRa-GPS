#include "gps.h"
#include <Arduino.h>
#include <TinyGPS++.h>

TinyGPSPlus gps;

void gps_init(){
    Serial.begin(115200);
    Serial1.begin(9600);
}

uint32_t gps_get_lon(){
    uint32_t lon;
    uint32_t lat;
    uint32_t in;
    while(Serial1.available() > 0){
        in = Serial1.read();
        gps.encode(in);
        
        lon = gps.location.lng();
        lat = gps.location.lat();
        // Serial.print("Lon=");
        // Serial.print(lon, 6);
        // Serial.print("Lat=");
        // Serial.print(lat, 6);
        Serial.write(in);
    }
    return lon;
}

uint32_t gps_get_lat(){
    return 0;
}