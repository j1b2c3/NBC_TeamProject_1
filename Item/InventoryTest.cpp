/*#include <iostream>                                                                                                                                                                                                                                                                                               
#include "itemDB.h"                                                                                                                                                                                                                                                                                               
#include "Player_Temp.h"                                                                                                                                                                                                                                                                                          
#include "Inventory.h"
#include "ItemFactory.h"

int main_test() {
    // DB 초기화
    initItemDB();

    // 플레이어 생성
    Player player("테스트");

    // 인벤토리 생성
    Inventory inventory;

    std::cout << "===== 테스트 시작 =====\n\n";

    // 1. 아이템 추가 테스트
    std::cout << "--- 아이템 추가 ---\n";
    inventory.addItem(101);       // 낡은 검
    inventory.addItem(201);       // 가죽 갑옷
    inventory.addItem(301, 3);    // 체력 포션 3개
    inventory.addItem(401);       // 슬라임의 점액

    // 2. 인벤토리 출력
    inventory.displayItems();

    // 3. 장착 테스트
    std::cout << "\n--- 장착 테스트 ---\n";
    inventory.equipWeapon(101, player);
    inventory.equipArmor(201, player);
    inventory.displayEquipped();

    // 4. 소모품 사용 테스트
    std::cout << "\n--- 소모품 사용 테스트 ---\n";
    player.hp = 100;  // HP 강제로 낮춤
    std::cout << "현재 HP: " << player.hp << "/" << player.maxHP << "\n";
    inventory.useConsumable(301, player);

    // 5. 장비 교체 테스트
    std::cout << "\n--- 장비 교체 테스트 ---\n";
    inventory.addItem(102);       // 강철 검 추가
    inventory.equipWeapon(102, player);
    inventory.displayEquipped();

    // 6. 해제 테스트
    std::cout << "\n--- 해제 테스트 ---\n";
    inventory.unequipWeapon(player);
    inventory.unequipArmor(player);
    inventory.displayEquipped();

    // 7. 최종 인벤토리
    inventory.displayItems();

    std::cout << "\n===== 테스트 종료 =====\n";
    return 0;
}*/