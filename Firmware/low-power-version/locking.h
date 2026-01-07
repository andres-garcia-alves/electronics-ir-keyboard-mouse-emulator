#ifndef LOCKING_H
#define LOCKING_H

static bool locked = false;


/* FUNCTIONS */
bool isLocked() { return locked; }

void switchLockUnlock() {
  locked = !locked;
  locked ? debugMessage("Locking: lock ON") : debugMessage("Locking: lock OFF");
}

#endif
