#include "calculations.h"

// Calculate instantaneous power
void calculatePower(ChargerData &data) {

    data.power_W = data.voltage_V * data.current_A;

}

// Update accumulated energy
void updateEnergy(ChargerData &data, uint32_t currentTime_ms) {

    // Only accumulate energy when charging is active
    // and we have received charger data.
    if (!data.charging || !data.data_received) {
        data.energy_timer_started = false;
        return;
    }

    // Initialize the energy timer on the first update.
    if (!data.energy_timer_started) {
        data.last_energy_update_time_ms = currentTime_ms;
        data.energy_timer_started = true;
        return;
    }

    // Calculate time since the previous energy update.
    uint32_t elapsed_ms =
        currentTime_ms - data.last_energy_update_time_ms;

    // Convert milliseconds into hours.
    float elapsed_hours = elapsed_ms / 3600000.0f;

    // Calculate energy delivered during this interval.
    float energy_added = data.power_W * elapsed_hours;

    // Add energy to the accumulated total.
    data.energy_Wh += energy_added;

    // Save the current update time.
    data.last_energy_update_time_ms = currentTime_ms;
}

// Calculate elapsed charging time
uint32_t getChargingElapsedTime(const ChargerData &data, uint32_t currentTime_ms) {

    if (!data.charging) {
        return 0;
    }

    return (currentTime_ms - data.charging_start_time_ms) / 1000;

}