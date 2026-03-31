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

    // 엔터 키를 받기전까지 대기
    static void PressEnterKey()
    {
        while (true)
        {
            int ch = _getch();
            if (ch == 13) break; // Enter

            // 1바이트를 넘어서는 경우(전각 문자일 확률이 높음)
            if (ch < 0 || ch > 127) {
                // 전각은 보통 2바이트이므로 다음 바이트를 읽어버림
                ch = _getch();
            }
            // 그 외에는 반각
        }
    }
};

// 숫자값만 입력받음, 입력 실패 시 out참조변수에 -1을 넘기고 false반환
static bool InputDigit(int& out)
{
    std::string str;
    if (!(std::cin >> std::ws))
    {
        out = -1;
        return false;
    }

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
