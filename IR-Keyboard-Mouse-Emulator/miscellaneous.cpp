#include <Arduino.h>
#include "miscellaneous.h"

static bool locked = false;

/* LOCKING */
bool isLocked() {
  return locked;
}

void switchLockUnlock() {
  locked = !locked;
  Serial.print("Locking: lock ");
  Serial.println(locked ? "ON": "OFF");
  delay(DELAY_SERIAL);
}

/* DEBUG */
void dump(decode_type_t protocol, uint32_t rawData) {

  Serial.print("Dump: ");

  switch (protocol) {
    case NEC:        Serial.print("protocol NEC");        break;
    case SONY:       Serial.print("protocol SONY");       break;
    case RC5:        Serial.print("protocol RC5");        break;
    case RC6:        Serial.print("protocol RC6");        break;
    case PANASONIC:  Serial.print("protocol PANASONIC");  break;
    case LG:         Serial.print("protocol LG");         break;
    case JVC:        Serial.print("protocol JVC");        break;
    case WHYNTER:    Serial.print("protocol WHYNTER");    break;
    default:         Serial.print("protocol UNKNOWN");    break;
  }

  Serial.print(", raw data ");
  Serial.println(rawData, HEX);
}
