
#ifndef CHARGER_DATA_H
#define CHARGER_DATA_H

#include <stdint.h>

// Stores the latest information about the charger
struct ChargerData {

    // Measurements received from the charger
    float voltage_V = 0.0;
    float current_A = 0.0;

    // Measurements calculated by our ESP32
    float power_W = 0.0;
    float energy_Wh = 0.0;

    // Charger status information
    bool data_received = false;
    bool charging = false;

    // Time information
    uint32_t last_message_time_ms = 0;
    uint32_t last_energy_update_time_ms = 0;
    uint32_t charging_start_time_ms = 0;

    bool energy_timer_started = false;  

};

#endif