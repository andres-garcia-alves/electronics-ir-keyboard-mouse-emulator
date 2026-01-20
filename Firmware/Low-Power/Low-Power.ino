#include <Arduino.h>
#include <IRremote.hpp>
#include "hardware.h"
#include "debug.h"
#include "locking.h"
#include "commands.h"
#include "input.h"
#include "power_hw.h"

void setup() {

  delay(100);               // safety measure
  hardwareInit();           // hardware pin modes

  debugInit();              // debuging
  irRemoteInit(IrReceiver); // full reset of IRremote
  commandsInit();           // HID: media keys, keyboard & mouse
  powerInit();              // disable unnecessary hardware

  delay(100);
  debugMessage("System ready");
  delay(100);
}

void loop() {

  if (IrReceiver.decode()) {

    markActivity();
    debugIrReceiverData(IrReceiver.decodedIRData.protocol, IrReceiver.decodedIRData.decodedRawData);

    // NEC protocol uses codes in format 0x1036/0x1836 alternatively, ignore bit 0x0800
    uint16_t code = NEC_NORMALIZE(IrReceiver.decodedIRData.decodedRawData);

    // wake-up all arduino features
    // handleLowPowerMode();

    // process pressed key
    handleInput(isLocked(), code);

    IrReceiver.resume();
  }

  handlePower();
  // handleAutoSleep();
}
