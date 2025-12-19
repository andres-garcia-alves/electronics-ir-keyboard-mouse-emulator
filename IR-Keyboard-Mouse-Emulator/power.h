#ifndef POWER_H
#define POWER_H

#define AUTO_SLEEP_TIMEOUT (60UL * 1000UL) // 1 minuto

void initPower();

void markActivity();
void handleAutoSleep();

bool isLowPowerMode();
void setNormalPowerMode();
void setLowPowerMode();

#endif
