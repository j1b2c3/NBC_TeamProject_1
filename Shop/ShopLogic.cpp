#include "ShopLogic.h"
#include "../Player/Player/Player.h"
#include <iostream>

// 구매
void buyItem(int id, ItemType type, int amount, Player* player)
{
    int cost = 0;
    bool canBuy = true;

    switch (type) {
    case ItemType::Weapon:
        cost = weaponDB[id].base.price * amount;
        canBuy = weaponDB[id].base.canBuy;
        break;
    case ItemType::Armor:
        cost = armorDB[id].base.price * amount;
        canBuy = armorDB[id].base.canBuy;
        break;
    case ItemType::Consumable:
        cost = consumableDB[id].base.price * amount;
        canBuy = consumableDB[id].base.canBuy;
        break;
    }

    if (!canBuy) {
        std::cout << "이 아이템은 구매할 수 없습니다.\n";
        return;
    }

    if (player->getGold() < cost) {
        std::cout << "금화 부족\n";
        return;
    }

    player->subGold(cost);

    switch (type) {
        if (player->getInventory() != nullptr) {
            player->getInventory()->addItem(id, amount);
        }

        std::cout << "[O] 구매 완료! 가방을 확인하세요\n";
    }
}

    // 1. 함수의 '머리(선언부)'를 반드시 써주어야 합니다!
    void sellItem(int id, ItemType type, int amount, Player * player)
    {
        // 0. 안전장치: 플레이어나 인벤토리가 없으면 중단
        if (player == nullptr || player->getInventory() == nullptr) return;

        int qty = 0;
        int sellGold = 0;
        Inventory* inv = player->getInventory();

        // 1. 수량 파악 및 판매금 계산
        // 인벤토리의 getItems()를 통해 현재 가지고 있는 아이템 맵을 가져옵니다.
        auto& items = inv->getItems();

        // 아이템이 가방에 없으면 판매 불가
        if (items.find(id) == items.end()) {
            cout << "팔 수 있는 아이템이 없습니다.\n";
            return;
        }

        qty = items.at(id); // 현재 보유 수량

        switch (type) {
        case ItemType::Weapon:
            sellGold = qty * weaponDB[id].base.sellprice;
            break;
        case ItemType::Armor:
            sellGold = qty * armorDB[id].base.sellprice;
            break;
        case ItemType::Consumable:
            sellGold = qty * consumableDB[id].base.sellprice;
            break;
        }

        // 2. 가방에서 제거
        inv->removeItem(id, qty);

        // 3. [수정] 돈 추가 (getGold는 확인만 하는 함수, 더할 때는 addGold!)
        player->addGold(sellGold);

        cout << "판매 완료! " << qty << "개를 팔아 +" << sellGold << "G를 획득했습니다.\n";
        cout << "현재 잔액: " << player->getGold() << "G\n";
    }