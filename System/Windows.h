#pragma once

#include "util.h"

class Windows
{
public:
    static void CursorView(bool show);
    static Vector2D GetCursorPos();
    static void SetCursorPos(Vector2D pos);
    static void SetCursorPos(short x, short y);
};