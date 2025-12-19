#include <Arduino.h>
#include <avr/power.h>
#include <avr/sleep.h>
#include "miscellaneous.h"
#include "power.h"

#define USB_TIMEOUT 10000

unsigned long lastActivity = 0;
unsigned long timeout_start = 0;
bool lowPowerMode = false;


// set power-save settings
void initPower() {
  power_adc_disable();
  power_spi_disable();
  power_twi_disable();
}

void markActivity()   { lastActivity = millis(); }
bool isLowPowerMode() { return lowPowerMode; }
bool checkTimeOut()   { return millis() - lastActivity >= AUTO_SLEEP_TIMEOUT; }

void handleAutoSleep() {

  if (!isLowPowerMode() && checkTimeOut()) {

    #ifdef DEBUG
    Serial.println("Power: auto-sleep by inactivity");
    delay(DELAY_SERIAL);
    #endif
    
    setLowPowerMode();
    // powerSaveIdle();
    // powerSavePowerDown();
  }
}

void setLowPowerMode() {

  // detach USB
  Serial.flush();
  USBDevice.detach();

  // set CPU @2 MHz
  clock_prescale_set(clock_div_8);

  // turn off LED
  digitalWrite(LED_PIN, LOW);

  lowPowerMode = true;
}

void setNormalPowerMode() {

  // set CPU @16 MHz
  clock_prescale_set(clock_div_1);

  // attach USB
  USBDevice.attach();
  timeout_start = millis();

  while (!USBDevice.configured()) {
    if (millis() - timeout_start > USB_TIMEOUT) { break; }
  }

  // turn on LED
  digitalWrite(LED_PIN, HIGH);

  lowPowerMode = false;
}

/* not working
void powerSaveIdle() {

  #ifdef DEBUG
  Serial.println("Power: entering idle-sleep...");
  delay(DELAY_SERIAL);
  #endif

  set_sleep_mode(SLEEP_MODE_IDLE);
  sleep_enable();
  sleep_cpu();

  sleep_disable();
  markActivity();

  #ifdef DEBUG
  Serial.println("Power: woke up.");
  delay(DELAY_SERIAL);
  #endif
}*/

/* not working
void powerSavePowerDown() {

  #ifdef DEBUG
  Serial.println("Power: entering deep-sleep...");
  delay(DELAY_SERIAL);
  #endif

  // IrReceiver.stop();
  digitalWrite(LED_PIN, LOW);
  delay(DELAY_SERIAL);

  USBDevice.detach();
  delay(DELAY_SERIAL);

  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable();
  sleep_cpu(); // deep-sleep
}*/
