#ifndef DEBUG_H
#define DEBUG_H

/* DEFINITIONS */
#define DEBUG         true    // enable/disable debuging
#define DELAY_SERIAL  50      // little delay after a Serial.print()


/* FUNCTIONS */
void debugInit()
{
  #if DEBUG
  Serial.begin(9600);
  while (!Serial) { delay(1); }
  #endif  
}

// print a message in serial monitor
void debugMessage(String msg)
{
  #if DEBUG
  Serial.println(msg);
  delay(DELAY_SERIAL);
  #endif
}

// print IR Receiver data in serial monitor
void debugIrReceiverData(decode_type_t protocol, uint32_t rawData) {

  #if DEBUG
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
  #endif
}

#endif
