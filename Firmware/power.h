#ifndef POWER_H
#define POWER_H

#include <avr/power.h>
#include <avr/sleep.h>

/* DEFINITIONS */
#define AUTO_SLEEP_TIMEOUT (60UL * 1000UL)  // 1 minute
#define USB_TIMEOUT 10000                   // 10 seconds

/* VARIABLES */
unsigned long lastActivity = 0;
unsigned long timeout_start = 0;
bool lowPowerMode = false;

/* FUNCTION DEFINITIOS */
// void setLowPowerMode();
// void powerSaveIdle();
// void powerSavePowerDown();


void powerInit() {
  // set some power-save settings
  power_adc_disable();
  power_spi_disable();
  power_twi_disable();
}


/* FUNCTIONS: MISCELLANEOUS */
void markActivity()   { lastActivity = millis(); }
bool isLowPowerMode() { return lowPowerMode; }
bool checkTimeOut()   { return millis() - lastActivity >= AUTO_SLEEP_TIMEOUT; }


/* FUNCTIONS: AUTO-SLEEP */
/*void handleAutoSleep() {

  if (!isLowPowerMode() && checkTimeOut()) {
    debugMessage("Power: auto-sleep by inactivity");
    
    // setLowPowerMode();
    // powerSaveIdle();
    // powerSavePowerDown();
  }
}*/


/* FUNCTIONS: POWER-SAVE MODES */

// not working
/*void setLowPowerMode() {

  // detach USB
  Serial.flush();
  USBDevice.detach();

  // set CPU @2 MHz
  clock_prescale_set(clock_div_8);

  // turn off LED
  digitalWrite(PIN_LED, LOW);

  lowPowerMode = true;
}*/

// not working
/*void setNormalPowerMode() {

  // set CPU @16 MHz
  clock_prescale_set(clock_div_1);

  // attach USB
  USBDevice.attach();
  timeout_start = millis();

  while (!USBDevice.configured()) {
    if (millis() - timeout_start > USB_TIMEOUT) { break; }
  }

  // turn on LED
  digitalWrite(PIN_LED, HIGH);

  lowPowerMode = false;
}*/

// not working
/*void powerSaveIdle() {
  debugMessage("Power: entering idle-sleep...");

  set_sleep_mode(SLEEP_MODE_IDLE);
  sleep_enable();
  sleep_cpu();

  sleep_disable();
  markActivity();

  debugMessage("Power: woke up.");
}*/

// not working
/*void powerSavePowerDown() {
  debugMessage("Power: entering deep-sleep...");

  // IrReceiver.stop();
  digitalWrite(LED_PIN, LOW);
  delay(DELAY_SERIAL);

  USBDevice.detach();
  delay(DELAY_SERIAL);

  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable();
  sleep_cpu(); // deep-sleep
}*/

#endif
