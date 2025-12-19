#include <Arduino.h>
#include "ir_codes.h"
#include "commands.h"

void handleInput(bool isLocked, uint16_t code) {

  if (isLocked && code != KEY_GREEN) { return; }

  switch (code) {
    case KEY_GREEN:       cmdKeyLockUnlock();     debounceLong();   break;
    case KEY_YELLOW:      cmdSystemMyPC();        debounceLong();   break;
    case KEY_BLUE:        cmdMouseRightClick();   debounceLong();   break;
    case KEY_BACK:        cmdKeyEsc();            debounceLong();   break;
    case KEY_EXIT:        cmdKeyClose();          debounceLong();   break;

    case KEY_OK:          cmdMouseLeftClick();    debounceLong();   break;
    case KEY_UP:          cmdMouseMoveUp();       debounceShort();  break;
    case KEY_RIGHT:       cmdMouseMoveRight();    debounceShort();  break;
    case KEY_DOWN:        cmdMouseMoveDown();     debounceShort();  break;
    case KEY_LEFT:        cmdMouseMoveLeft();     debounceShort();  break;

    case KEY_PLAY_PAUSE:  cmdMediaPlayPause();    debounceLong();   break;
    case KEY_STOP:        cmdMediaStop();         debounceLong();   break;
    case KEY_REC:         cmdMediaPlayer();       debounceLong();   break;
    case KEY_T_SHIFT:     cmdMouseChangeSpeed();  debounceLong();   break;

    case KEY_REWIND:      cmdMediaRewind();       debounceLong();   break;
    case KEY_FORWARD:     cmdMediaForward();      debounceLong();   break;
    case KEY_PREV:        cmdMediaPrevious();     debounceLong();   break;
    case KEY_NEXT:        cmdMediaNext();         debounceLong();   break;
  }
}

void debounceShort()  { delay(DEBOUNCE_SHORT); }
void debounceLong()   { delay(DEBOUNCE_LONG); }
