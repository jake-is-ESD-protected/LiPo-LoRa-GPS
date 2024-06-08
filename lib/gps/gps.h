#ifndef GPS_H
#define GPS_H

#include <TinyGPS++.h>
#include <Arduino.h>

class GPS {
public:
    GPS(int buffer_length);
    ~GPS();
    void init();
    uint32_t get_lng();
    uint32_t get_lat();

private:
    TinyGPSPlus gps;
    const uint32_t FAC_1_000_000 = 1000000;
    int buffer_length;
    double* lat_buffer;
    double* lng_buffer;
    int buffer_index;
    int buffer_count;
    double get_average(double* buffer, int count);

    void add_to_buffer(double* buffer, double value);
};

#endif // GPS_H
