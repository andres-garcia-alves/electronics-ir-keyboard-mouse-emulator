#ifndef POWER_HW_H
#define POWER_HW_H

#include <avr/power.h>
#include <IRremote.hpp>

/* DEFINITIONS */
#define TIMEOUT_LATCH_DISCH   10000   // 10 seconds from start
#define TIMEOUT_INACTIVITY    30000   // 30 seconds from last activity
#define DELAY_STANDARD        100

/* VARIABLES */
static bool latchDischarged = false;
static unsigned long lastActivity = 0;


void powerInit() {

  // set some power-save settings
  power_adc_disable();                // turn off ADC
  power_spi_disable();                // turn off SPI
  power_twi_disable();                // turn off I2C

  lastActivity = millis();
}

/* FUNCTIONS */
void markActivity()           { lastActivity = millis(); }
bool checkLatchDischTimeOut() { return millis() >= TIMEOUT_LATCH_DISCH; }
bool checkInactivityTimeOut() { return millis() - lastActivity >= TIMEOUT_INACTIVITY; }

void handlePower() {

  if (!latchDischarged && checkLatchDischTimeOut()) {
    debugMessage("Power: discharging capacitor (C1) power latch");
    delay(DELAY_STANDARD);
    
    digitalWrite(PIN_LATCH_CAP_DISCH, HIGH);  // discharge capacitor (C1) power latch
    latchDischarged = true;
  }

  if (checkInactivityTimeOut()) {
    debugMessage("Power: auto turn-off by inactivity");
    delay(DELAY_STANDARD);

    digitalWrite(PIN_LATCH_ON_OFF, LOW);      // release arduino power latch (turn off)
    delay(DELAY_STANDARD);
  }
}

#endif
