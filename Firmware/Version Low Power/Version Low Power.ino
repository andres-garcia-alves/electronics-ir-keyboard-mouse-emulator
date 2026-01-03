#include <Arduino.h>
#include <IRremote.hpp>
#include "definitions.h"
#include "debug.h"
#include "locking.h"
#include "commands.h"
#include "input.h"
#include "power.h"

void handleInput(uint16_t);

void setup() {

  delay(DELAY_START);

  debugInit();
  irRemoteInit();   // full stop init cicle of IRremote
  commandsInit();   // HID: media keys, keyboard & mouse
  inputInit();      // pin modes for receiver & feedback led
  powerInit();      // disable unnecessary hardware
  
  debugMessage("System ready");
}

void loop() {

  if (IrReceiver.decode()) {

    debugIrReceiverData(IrReceiver.decodedIRData.protocol, IrReceiver.decodedIRData.decodedRawData);

    // NEC protocol uses codes in format 0x1036/0x1836 alternatively, ignore bit 0x0800
    uint16_t code = NEC_NORMALIZE(IrReceiver.decodedIRData.decodedRawData);

    // wake-up all arduino features
    /*if (isLowPowerMode()) {
      setNormalPowerMode();
      irRemoteInit();
    }*/

    // process pressed key
    handleInput(isLocked(), code);
    markActivity();

    IrReceiver.resume();
  }

  // handleAutoSleep();
  delay(DELAY_LOOP);
}


void irRemoteInit() {

  IrReceiver.stop();
  delay(DELAY_STANDARD);
  IrReceiver.end();
  delay(DELAY_STANDARD);
  IrReceiver.begin(PIN_RECEIVER, ENABLE_LED_FEEDBACK);
  delay(DELAY_STANDARD);
}
