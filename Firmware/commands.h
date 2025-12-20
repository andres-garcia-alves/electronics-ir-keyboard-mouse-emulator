#ifndef COMMANDS_H
#define COMMANDS_H

/* DEFINITIONS */
#define KEY_WAIT_TIME       50
#define MOUSE_SPEED_NORMAL  20
#define MOUSE_SPEED_SLOW    10

void initHID();
void keyPressDelay();

// keyboard commands
void cmdKeyLockUnlock();
void cmdKeyEsc();
void cmdKeyClose();

// mouse commands
void cmdMouseChangeSpeed();
void cmdMouseLeftClick();
void cmdMouseRightClick();
void cmdMouseMoveUp();
void cmdMouseMoveRight();
void cmdMouseMoveDown();
void cmdMouseMoveLeft();

// media commands
void cmdMediaPlayer();
void cmdMediaPlayPause();
void cmdMediaStop();
void cmdMediaForward();
void cmdMediaRewind();
void cmdMediaPrevious();
void cmdMediaNext();
void cmdMediaVolumeMute();
void cmdMediaVolumeUp();
void cmdMediaVolumeDown();

// miscellaneous commands
void cmdSystemMyPC();
void cmdSystemCalculator();

#endif
