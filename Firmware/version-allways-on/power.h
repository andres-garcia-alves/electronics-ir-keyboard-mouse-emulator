#ifndef POWER_H
#define POWER_H

#include <avr/power.h>
#include <avr/sleep.h>

/* DEFINITIONS */
#define TIMEOUT_INACTIVITY  (60UL * 1000UL) // 1 minute
#define TIMEOUT_USB         10000           // 10 seconds

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
  power_adc_disable();        // turn off ADC
  power_spi_disable();        // turn off SPI
  power_twi_disable();        // turn off I2C
  // power_usart0_disable();  // turn off UART/Serial
  // power_timer0_disable();  // turn off Timer0
}


/* FUNCTIONS: MISCELLANEOUS */
void markActivity()   { lastActivity = millis(); }
bool isLowPowerMode() { return lowPowerMode; }
bool checkTimeOut()   { return millis() - lastActivity >= TIMEOUT_INACTIVITY; }


/* FUNCTIONS: AUTO-SLEEP */
/*void handleLowPowerMode() {

  if (lowPowerMode) {
    setNormalPowerMode();
    irRemoteInit();
  } 
}*/

/*void handleAutoSleep() {

  if (!isLowPowerMode() && checkTimeOut()) {
    debugMessage("Power: auto-sleep by inactivity");
    
    // setLowPowerMode();
    // powerSaveIdle();
    // powerSavePowerDown();
  }
}*/


/* POWER-SAVE MODES (currently not workng) */
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

/*void setNormalPowerMode() {

  // set CPU @16 MHz
  clock_prescale_set(clock_div_1);

  // attach USB
  USBDevice.attach();
  timeout_start = millis();

  while (!USBDevice.configured()) {
    if (millis() - timeout_start > TIMEOUT_USB { break; }
  }

  // turn on LED
  digitalWrite(PIN_LED, HIGH);

  lowPowerMode = false;
}*/

/*void powerSaveIdle() {
  debugMessage("Power: entering idle-sleep...");

  set_sleep_mode(SLEEP_MODE_IDLE);
  sleep_enable();
  sleep_cpu();

  sleep_disable();
  markActivity();

  debugMessage("Power: woke up.");
}*/

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
