#ifndef HARDWARE_H
#define HARDWARE_H

/* DEFINITIONS */
#define DELAY_IR_RECEIVER     100


/* LOW POWER VERSION SELECTION */
#define LOW_POWER_VERSION       'B'   // 'A' or 'B' (see README.md)


/* HARDWARE DEFINITIONS */
#if LOW_POWER_VERSION == 'A'          // LOW-POWER-A
  #define PIN_IR_RECEIVER       6     // IR Reciever (VS1838) pin
  #define PIN_LED               2     // LED pin
  #define PIN_LATCH_ON_OFF      15    // Arduino Power Latch pin
  #define PIN_LATCH_CAP_DISCH   14    // Capacitor (C1) Power Latch pin

#elif LOW_POWER_VERSION == 'B'        // LOW-POWER-B
  #define PIN_IR_RECEIVER       8     // IR Reciever (VS1838) pin
  #define PIN_LED               9     // LED pin
  #define PIN_LATCH_ON_OFF      16    // Arduino Power Latch pin
  #define PIN_LATCH_CAP_DISCH   10    // Capacitor (C1) Power Latch pin

#else
  #error "Invalid LOW_POWER_VERSION: use 'A' or 'B'"
#endif


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
