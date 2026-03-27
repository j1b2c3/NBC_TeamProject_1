#include "Inventory_UI.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

// 테스트 구조체
struct ItemInfo {
    string name;
    int count;
    string desc;
};

void displayInventory(int playerGold, const vector<ItemInfo>& weapons, const vector<ItemInfo>& armors, const vector<ItemInfo>& consumables) {
    cout << "+==============================================================================+" << '\n';
    cout << "|                                                                              |" << '\n';
    cout << "|     ####      ########      ########      ##     ##        ######            |" << '\n';
    cout << "|      ##          ##         ##            ###   ###       ##    ##           |" << '\n';
    cout << "|      ##          ##         ######        #### ####        ######            |" << '\n';
    cout << "|      ##          ##         ##            ## ### ##             ##           |" << '\n';
    cout << "|      ##          ##         ##            ##     ##       ##    ##           |" << '\n';
    cout << "|     ####         ##         ########      ##     ##        ######            |" << '\n';
    cout << "|                                                                              |" << '\n';
    cout << "+==============================================================================+" << '\n';

    // 자산 정보
    string goldDisplay = to_string(playerGold) + " G";
    cout << "|  보유 금화: " << left << setw(65) << goldDisplay << "|" << '\n';
    cout << "|  --------------------------------------------------------------------------  |" << '\n';

    // [1] 무기 목록
    cout << "|  [1] 무기                                                                    |" << '\n';
    if (weapons.empty()) cout << "|      - (비어 있음)                                                           |" << '\n';
    for (const auto& item : weapons) {
        cout << "|      - " << left << setw(15) << item.name << " x" << setw(3) << item.count << " (" << setw(35) << item.desc << ") |" << '\n';
    }
    cout << "|                                                                              |" << '\n';

    // [2] 방어구 목록
    cout << "|  [2] 방어구                                                                  |" << '\n';
    if (armors.empty()) cout << "|      - (비어 있음)                                                           |" << '\n';
   for (const auto& item : armors) {
       cout << "|      - " << left << setw(15) << item.name << " x" << setw(3) << item.count << " (" << setw(35) << item.desc << ") |" << '\n';
   }
    cout << "|                                                                              |" << '\n';

    // [3] 소모품 목록
    cout << "|  [3] 소모품                                                                  |" << '\n';
    if (consumables.empty()) cout << "|      - (비어 있음)                                                           |" << '\n';
    for (const auto& item : consumables) {
        cout << "|      - " << left << setw(15) << item.name << " x" << setw(3) << item.count << " (" << setw(35) << item.desc << ") |" << '\n';
    }

    cout << "|                                                                              |" << '\n';
    cout << "+==============================================================================+" << '\n';
    cout << "|                                                                              |" << '\n';
    // 수정 필요
    cout << "|    [1~3] 아이템 사용/장착       [0] 가방 닫기                                |" << '\n';
    cout << "|                                                                              |" << '\n';
    cout << "+==============================================================================+" << '\n';
    cout << "  선택 >> ";
}