#ifdef APP_LORA_SEND

#include "gps.h"

GPS::GPS(int buffer_length) : buffer_length(buffer_length), buffer_index(0), buffer_count(0) {
    lat_buffer = new double[buffer_length];
    lng_buffer = new double[buffer_length];
    for (int i = 0; i < buffer_length; i++) {
        lat_buffer[i] = 0.0;
        lng_buffer[i] = 0.0;
    }
}

GPS::~GPS() {
    delete[] lat_buffer;
    delete[] lng_buffer;
}

void GPS::init() {
    Serial.begin(115200);
    Serial1.begin(9600);
}

void GPS::add_to_buffer(double* buffer, double value) {
    buffer[buffer_index] = value;
    buffer_index = (buffer_index + 1) % buffer_length;
    if (buffer_count < buffer_length) {
        buffer_count++;
    }
}

double GPS::get_average(double* buffer, int count) {
    double sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += buffer[i];
    }
    return sum / count;
}

uint32_t GPS::get_lng() {
    double dlng;
    uint32_t lng = 0;
    while (Serial1.available() > 0) {
        gps.encode(Serial1.read());
        dlng = gps.location.lng();
        if (gps.location.isValid()) {
            add_to_buffer(lng_buffer, dlng);
            double avg_lng = get_average(lng_buffer, buffer_count);
            lng = (uint32_t)(avg_lng * FAC_1_000_000);

        }
    }
    Serial.print("Filtered Lng=");
    Serial.print(lng, 6);
    Serial.print("\n");
    return lng;
}

uint32_t GPS::get_lat() {
    double dlat;
    uint32_t lat = 0;
    while (Serial1.available() > 0) {
        gps.encode(Serial1.read());
        dlat = gps.location.lat();
        if (gps.location.isValid()) {
            add_to_buffer(lat_buffer, dlat);
            double avg_lat = get_average(lat_buffer, buffer_count);
            lat = (uint32_t)(avg_lat * FAC_1_000_000);
        }
    }
    Serial.print("Filtered Lat=");
    Serial.print(lat, 6);
    Serial.print("\n");
    return lat;
}

#endif