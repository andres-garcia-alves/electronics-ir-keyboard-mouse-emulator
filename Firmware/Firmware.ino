#include <Arduino.h>
#include <IRremote.hpp>
#include "miscellaneous.h"
#include "commands.h"
#include "ir_codes.h"
#include "power.h"

void handleInput(uint16_t);

void setup() {

  delay(DELAY_START);

  #ifdef DEBUG
  Serial.begin(9600);
  delay(DELAY_SERIAL);
  #endif

  initIRremote(); // full stop init cicle of IRremote
  initPower();  // disable unnecessary hardware
  initHID();    // HID: media keys, keyboard & mouse

  pinMode(RECEIVER_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);

  #ifdef DEBUG
  Serial.println("System ready");
  delay(DELAY_SERIAL);
  #endif
}

void loop() {

  if (IrReceiver.decode()) {

    #ifdef DEBUG
    dump(IrReceiver.decodedIRData.protocol, IrReceiver.decodedIRData.decodedRawData);
    #endif

    // NEC protocol uses codes in format 0x1036/0x1836 alternatively, ignore bit 0x0800
    uint16_t code = NEC_NORMALIZE(IrReceiver.decodedIRData.decodedRawData);

    // wake-up all arduino features
    // if (isLowPowerMode()) {
    //  setNormalPowerMode();
    //  initIRremote();
    // }

    // process pressed key
    handleInput(isLocked(), code);
    markActivity();

    IrReceiver.resume();
  }

  // handleAutoSleep();
  delay(20);
}


void initIRremote() {

  IrReceiver.stop();
  delay(100);
  IrReceiver.end();
  delay(100);
  IrReceiver.begin(RECEIVER_PIN, ENABLE_LED_FEEDBACK);
  delay(100);
}
