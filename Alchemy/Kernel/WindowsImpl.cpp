#include "PreComp.h"

BOOL IsShiftDown (void) { return (GetAsyncKeyState(VK_SHIFT) & 0x8000) ? TRUE : FALSE; }
BOOL IsControlDown (void) { return (GetAsyncKeyState(VK_CONTROL) & 0x8000) ? TRUE : FALSE; }
