#ifndef DEBUG_H
#define DEBUG_H
#include "IRProtocol.h"

/* DEFINITIONS */
#define RECEIVER_PIN 9  // IR reciever (VS1838)
#define LED_PIN 14      // LED pin

#define DELAY_START 3000  // safety measure
#define DELAY_SERIAL 50   // little delay after a Serial.print()

// enable debug
// #define DEBUG


/* LOCKING */
bool isLocked();
void switchLockUnlock();

/* DEBUG */
void dump(decode_type_t protocol, uint32_t rawData);

#endif
