#include <Windows.h>

#include "Windows.h"
void Windows::CursorView(bool show) //커서 깜빡임
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

Vector2D Windows::GetCursorPos()
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	return { info.dwCursorPosition.X, info.dwCursorPosition.Y };
}

void Windows::SetCursorPos(Vector2D pos)
{
	SetCursorPos(pos.x, pos.y);
}

void Windows::SetCursorPos(short x, short y)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
}
