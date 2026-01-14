#ifndef COMMANDS_H
#define COMMANDS_H

// #define LAYOUT_SPANISH   // LAYOUT_SPANISH, LAYOUT_US
#include <HID-Project.h>
#include <HID-Settings.h>

/* DEFINITIONS */
#define KEY_WAIT_TIME       50
#define MOUSE_SPEED_NORMAL  20
#define MOUSE_SPEED_SLOW    10

/* VARIABLES */
static byte currentSpeed = MOUSE_SPEED_NORMAL;


/* FUNCTIONS: MISCELLANEOUS */
void commandsInit() {
  Consumer.begin();
  Keyboard.begin();
  Mouse.begin();
}

void keyPressDelay()      { delay(KEY_WAIT_TIME); }


/* FUNCTIONS: KEYBOARD COMMANDS */
void cmdKeyLockUnlock()   { switchLockUnlock(); }
void cmdKeyEsc()          { Keyboard.write(KEY_ESC); }

void cmdKeyClose() {
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_F4);
  keyPressDelay();
  Keyboard.releaseAll();
}


/* FUNCTIONS: MOUSE COMMANDS */
void cmdMouseChangeSpeed() {
  currentSpeed = (currentSpeed == MOUSE_SPEED_NORMAL) ? MOUSE_SPEED_SLOW : MOUSE_SPEED_NORMAL;
}

void cmdMouseLeftClick()  { Mouse.click(MOUSE_LEFT); }
void cmdMouseRightClick() { Mouse.click(MOUSE_RIGHT); }
void cmdMouseMoveUp()     { Mouse.move(0, -currentSpeed); }
void cmdMouseMoveRight()  { Mouse.move(currentSpeed, 0); }
void cmdMouseMoveDown()   { Mouse.move(0, currentSpeed); }
void cmdMouseMoveLeft()   { Mouse.move(-currentSpeed, 0); }



/* FUNCTIONS: MEDIA COMMANDS */
void cmdMediaPlayer() {
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  keyPressDelay();
  Keyboard.releaseAll();
  keyPressDelay();
  Keyboard.print("vlc");
  Keyboard.write(KEY_RETURN);
}

void cmdMediaPlayPause()  { Consumer.write(MEDIA_PLAY_PAUSE); }
void cmdMediaStop()       { Consumer.write(MEDIA_STOP); }
void cmdMediaVolumeMute() { Consumer.write(MEDIA_VOLUME_MUTE); }
void cmdMediaVolumeUp()   { Consumer.write(MEDIA_VOLUME_UP);}
void cmdMediaVolumeDown() { Consumer.write(MEDIA_VOLUME_DOWN); }
// void cmdMediaForward()    { Consumer.write(MEDIA_FAST_FORWARD); }
// void cmdMediaRewind()     { Consumer.write(MEDIA_REWIND); }
// void cmdMediaNext()       { Consumer.write(MEDIA_NEXT); }
// void cmdMediaPrevious()   { Consumer.write(MEDIA_PREVIOUS); }

void cmdMediaForward()    { Keyboard.write(KEY_RIGHT_ARROW); }
void cmdMediaRewind()     { Keyboard.write(KEY_LEFT_ARROW); }

void cmdMediaNext() {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_RIGHT_ARROW);
  keyPressDelay();
  Keyboard.releaseAll();
}

void cmdMediaPrevious() {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ARROW);
  keyPressDelay();
  Keyboard.releaseAll();
}


/* FUNCTIONS: OTHER COMMANDS */
void cmdSystemMyPC() {
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  keyPressDelay();
  Keyboard.releaseAll();
  keyPressDelay();
  Keyboard.print("shell");
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press('.');  // Shift + '.' -> ':'
  keyPressDelay();
  Keyboard.releaseAll();
  keyPressDelay();
  Keyboard.print("MyComputerFolder");
  Keyboard.write(KEY_RETURN);
}

void cmdSystemCalculator() {
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  keyPressDelay();
  Keyboard.releaseAll();
  keyPressDelay();
  Keyboard.print("calc");
  Keyboard.write(KEY_RETURN);
}

#endif
