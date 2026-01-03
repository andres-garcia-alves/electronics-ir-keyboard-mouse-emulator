#ifndef POWER_SLEEP_H
#define POWER_SLEEP_H

// #include <avr/sleep.h>

/* DEFINITIONS */
// #define USB_TIMEOUT      10000   // 10 seconds

/* VARIABLES */
// static bool lowPowerMode = false;

/* FUNCTION DEFINITIOS */
// void setLowPowerMode();
// void setNormalPowerMode();
// void powerSaveIdle();
// void powerSavePowerDown();


/*void sleepInit() {
  // power_usart0_disable();          // turn off UART/Serial
  // power_timer0_disable();          // turn off Timer0
}*/


/* FUNCTIONS */
// bool isLowPowerMode() { return lowPowerMode; }

/*void handleLowPowerMode() {

  if (lowPowerMode) {
    setNormalPowerMode();
    irRemoteInit();
  } 
}*/

/*void handleAutoSleep() {

  if (!isLowPowerMode() && checkInactivityTimeOut()) {
    debugMessage("Power: auto sleep by inactivity");
    
    // setLowPowerMode();
    // powerSaveIdle();
    // powerSavePowerDown();
  }
}*/


/* POWER-SAVE MODES (currently not workng) */
/* void setLowPowerMode() {

  // detach USB
  Serial.flush();
  USBDevice.detach();

  // set CPU @2 MHz
  clock_prescale_set(clock_div_8);

  // turn off LED
  digitalWrite(PIN_LED, LOW);

  lowPowerMode = true;
}*/

/* void setNormalPowerMode() {

  // set CPU @16 MHz
  clock_prescale_set(clock_div_1);

  // attach USB
  USBDevice.attach();
  unsigned long timeout_start = millis();

  while (!USBDevice.configured()) {
    if (millis() - timeout_start > USB_TIMEOUT) { break; }
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
