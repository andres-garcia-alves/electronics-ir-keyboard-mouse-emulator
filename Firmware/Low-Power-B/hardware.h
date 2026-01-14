#ifndef HARDWARE_H
#define HARDWARE_H

/* DEFINITIONS */
#define PIN_IR_RECEIVER       8   // IR reciever pin (VS1838)
#define PIN_LED               9   // LED pin

#define PIN_LATCH_ON_OFF      16  // Arduino Power Latch pin
#define PIN_LATCH_CAP_DISCH   10  // Capacitor (C1) Power Latch pin

#define DELAY_IR_RECEIVER     100


void hardwareInit() {

  // setup arduino power latch
  pinMode(PIN_LATCH_ON_OFF, OUTPUT);
  digitalWrite(PIN_LATCH_ON_OFF, HIGH);

  // hold C1 power latch for a while
  pinMode(PIN_LATCH_CAP_DISCH, OUTPUT);
  digitalWrite(PIN_LATCH_CAP_DISCH, LOW);

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
