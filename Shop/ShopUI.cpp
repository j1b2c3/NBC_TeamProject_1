#include "ShopUI.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void displayshop(int playerGold) {
    string goldDisplay = to_string(playerGold) + "G";

    cout << "+==============================================================================+" << '\n';
    cout << "|                                                                              |" << '\n';
    cout << "|     ######     ##     ##      #######      ########                          |" << '\n';
    cout << "|    ##    ##    ##     ##     ##     ##     ##     ##                         |" << '\n';
    cout << "|    ##          ##     ##     ##     ##     ##     ##                         |" << '\n';
    cout << "|     ######     #########     ##     ##     ########                          |" << '\n';
    cout << "|          ##    ##     ##     ##     ##     ##                                |" << '\n';
    cout << "|    ##    ##    ##     ##     ##     ##     ##       [ MERCHANT'S SHOP ]      |" << '\n';
    cout << "|     ######     ##     ##      #######      ##                                |" << '\n';
    cout << "|                                                                              |" << '\n';
    cout << "+==============================================================================+" << '\n';
    cout << "|    보유 금화: " << left << setw(62) << goldDisplay << " |" << '\n';
    cout << "|  --------------------------------------------------------------------------  |" << '\n';
    cout << "|                                                                              |" << '\n';
    cout << "|    [1] 무기                [2] 방어구                 [3] 소모품             |" << '\n';
    cout << "|                                                                              |" << '\n';
    cout << "|    [4] 전리품 판매                                    [0] 상점 나가기        |" << '\n';
    cout << "|                                                                              |" << '\n';
    cout << "+==============================================================================+" << '\n';
}

void displayWeaponMenu() {
    std::cout << "\n=== 무기 메뉴 ===\n";
    std::cout << "1. 구매\n";
    std::cout << "2. 판매\n";
    std::cout << "선택 >> ";
}

void displayWeaponDetail(const Weapon& weapon) {
    cout << "\n--- [ " << weapon.base.name << " ] ---\n";
    cout << " 가격    : " << weapon.base.price << "G\n";
    cout << " 공격력  : " << weapon.attack << "\n";
    cout << " ------------------------\n";
    cout << " 구매하시겠습니까? (1.예 / 2.아니오) >> ";
}

void displayWeaponSellDetail(const Weapon& weapon, int ownedCount) {
    std::cout << "\n--- [ " << weapon.base.name << " 판매 ] ---\n";
    std::cout << "공격력 : " << weapon.attack << "\n";
    std::cout << "판매가 : " << weapon.base.sellprice << "G\n";
    std::cout << "현재 보유량: " << ownedCount << "개\n"; 
    std::cout << "------------------------\n";
    std::cout << "정말 판매하시겠습니까? (1.예 / 2.아니오) >> ";
}

void displayArmorMenu() {
    std::cout << "\n=== 방어구 메뉴 ===\n";
    std::cout << "1. 구매\n";
    std::cout << "2. 판매\n";
    std::cout << "선택 >> ";
}

void displayArmorDetail(const Armor& armor) {
    std::cout << "\n--- [ " << armor.base.name << " ] ---\n";
    std::cout << "가격   : " << armor.base.price << "G\n";
    std::cout << "방어력 : " << armor.defense << "\n"; // 방어구 특성 출력
    std::cout << "------------------------\n";
    std::cout << "구매하시겠습니까? (1.예 / 2.아니오) >> ";
}
