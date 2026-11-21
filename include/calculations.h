#ifndef CALCULATIONS_H
#define CALCULATIONS_H

#include "charger_data.h"

// Calculate instantaneous charger power
void calculatePower(ChargerData &data);

// Update accumulated charging energy
void updateEnergy(ChargerData &data, uint32_t currentTime_ms);

// Calculate elapsed charging time
uint32_t getChargingElapsedTime(const ChargerData &data, uint32_t currentTime_ms);

#endif