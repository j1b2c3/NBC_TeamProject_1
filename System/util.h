#pragma once
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <string>
#include <conio.h>

class util
{
public:
    // min~max의 랜덤값 반환
    static float RandFloat(float min, float max)
    {
        return ((max - min) * (static_cast<float>(rand()) / RAND_MAX)) + min;
    }

    // 아무 키를 받기전까지 대기
    static void PressAnyKey()
    {
        int temp;
        if (_getch() == 224)
            temp = _getch();
    }
};

// 숫자값만 입력받음, 입력 실패 시 out참조변수에 -1을 넘기고 false반환
static bool InputDigit(int& out)
{
    std::string str;
    getline(std::cin, str);

    // 입력은 숫자만
    if (str.length() > 0 && all_of(str.begin(), str.end(), [](char c) { return isdigit(c); }))
    {
        out = stoi(str);
        return true;
    }
    out = -1;
    return false;
}

struct Vector2D
{
    int x;
    int y;
};
