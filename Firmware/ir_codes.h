#ifndef IR_CODES_H
#define IR_CODES_H

/* DEFINITIONS */
#define DEBOUNCE_SHORT 25
#define DEBOUNCE_LONG 200

// mask to normalize IR codes (NEC protocol)
#define NEC_MASK 0xF7FF	// ignores bit 0x0800

// macro helper: normalize a raw code
#define NEC_NORMALIZE(code) ((uint16_t)(code) & NEC_MASK)

// colors keys
#define KEY_GREEN       0x1036
#define KEY_YELLOW      0x1032
#define KEY_BLUE        0x1034

// navegation
#define KEY_UP          0x102F
#define KEY_RIGHT       0x1033
#define KEY_DOWN        0x1030
#define KEY_LEFT        0x1031
#define KEY_OK          0x101B
#define KEY_BACK        0x101C
#define KEY_EXIT        0x101F

// media keys
#define KEY_PLAY_PAUSE  0x1012
#define KEY_STOP        0x1018
#define KEY_REC         0x101D
#define KEY_T_SHIFT     0x1039
#define KEY_FORWARD     0x102A
#define KEY_REWIND      0x102B
#define KEY_PREV        0x102C
#define KEY_NEXT        0x102D

/* FUNCTIONS */
void handleInput(bool isLocked, uint16_t code);
void debounceShort();
void debounceLong();

#endif
