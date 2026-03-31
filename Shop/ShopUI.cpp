#include "ShopUI.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void displayShopHead()
{
    system("cls");
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
}


void displayShop(int playerGold)
{
    string goldDisplay = to_string(playerGold) + "G";

    displayShopHead();
    cout << "|    보유 금화: " << left << setw(62) << goldDisplay << " |" << '\n';
    cout << "|  --------------------------------------------------------------------------  |" << '\n';
    cout << "|                                                                              |" << '\n';
    cout << "|    [1] 무기                [2] 방어구                 [3] 소모품             |" << '\n';
    cout << "|                                                                              |" << '\n';
    cout << "|                            [0] 상점 나가기                                   |" << '\n';
    cout << "|                                                                              |" << '\n';
    cout << "+==============================================================================+" << '\n';
    cout << "|    선택 >>                                                                   | " << '\n';
    cout << "+==============================================================================+" << '\n';
    // Todo : 커서 위치
}

// 무기 방어구 통합 메뉴판 UI
void displayShopMenu(std::string title)
{
    string shopName = title + " 상점";
    displayShopHead();
    cout << "|    " << right << setw(35) << shopName << "                                      |" << '\n';
    cout << "|                                                                              |" << '\n';
    cout << "|         [1] 구매             [2] 판매             [0] 상점 나가기            |" << '\n';
    cout << "|                                                                              |" << '\n';
    cout << "+==============================================================================+" << '\n';
    cout << "|    선택 >>                                                                   | " << '\n';
    cout << "+==============================================================================+" << '\n';
    // Todo : 커서 위치
}

// 무기 방어구 통합 판매 시스템 UI
void displaySellDetail(const ItemBase& base, int statValue, std::string statName, int ownedCount)
{
    std::cout << "\n--- [ " << base.name << " 판매 ] ---\n";
    std::cout << statName << " : " << statValue << "\n"; // "공격력" 혹은 "방어력" 출력
    std::cout << "판매가 : " << base.sellprice << "G\n";
    std::cout << "현재 보유량: " << ownedCount << "개\n";
    std::cout << "------------------------\n";
    std::cout << "정말 판매하시겠습니까? (1.예 / 2.아니오) >> ";
}

// 무기 방어구 통합 구매 시스템 UI
void displayBuyDetail(const ItemBase& base, int statValue, std::string statName)
{
    std::cout << "\n--- [ " << base.name << " 구매 ] ---\n";
    std::cout << " 가격    : " << base.price << "G\n";
    std::cout << " " << statName << "  : " << statValue << "\n"; // 전달받은 이름과 수치 출력
    std::cout << " ------------------------\n";
    std::cout << " 구매하시겠습니까? (1.예 / 2.아니오) >> ";
}

// 통합 골드 부족 UI
void displayNoGold()
{
    std::cout << "\n[X] 금화가 부족합니다.\n";
}

// 통합 구매 취소 UI
void displayBuyCancel()
{
    std::cout << "\n[X] 구매를 취소했습니다.\n";
}

// 통합 판매 취소 UI
void displaySellCancel()
{
    std::cout << "\n[X] 판매를 취소했습니다.\n";
}

// 통합 번호 선택 실수 UI
void displayNoNumber()
{
    std::cout << "\n[X] 잘못된 번호입니다.\n";
}
