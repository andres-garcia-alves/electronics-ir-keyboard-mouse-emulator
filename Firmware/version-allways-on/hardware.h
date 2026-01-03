#ifndef HARDWARE_H
#define HARDWARE_H

/* DEFINITIONS */
#define PIN_IR_RECEIVER       9     // IR reciever pin (VS1838)
#define PIN_LED               14    // LED pin

#define DELAY_IR_RECEIVER     100


void hardwareInit() {

  // IR receiver
  pinMode(PIN_IR_RECEIVER, INPUT);

  // feedback LED
  pinMode(PIN_LED, OUTPUT);
  digitalWrite(PIN_LED, HIGH);
}

void irRemoteInit(IRrecv &receiver) {

  receiver.stop();
  delay(DELAY_IR_RECEIVER);
  receiver.end();
  delay(DELAY_IR_RECEIVER);
  receiver.begin(PIN_IR_RECEIVER, ENABLE_LED_FEEDBACK);
  delay(DELAY_IR_RECEIVER);
}

#endif
