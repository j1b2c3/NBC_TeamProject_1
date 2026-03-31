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

    void sellItem(int id, ItemType type, int amount, Player * player)
    {
        // 플레이어나 인벤토리가 없으면 중단
        if (player == nullptr || player->getInventory() == nullptr) return;

        int qty = 0;
        int sellGold = 0;
        Inventory* inv = player->getInventory();

        auto& items = inv->getItems();

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

        // 2. 판매가 되면 아이템을 가방에서 제거
        inv->removeItem(id, qty);

        // 3. 판매하고 판매한 돈 추가 
        player->addGold(sellGold);

        cout << "판매 완료! " << qty << "개를 팔아 +" << sellGold << "G를 획득했습니다.\n";
        cout << "현재 잔액: " << player->getGold() << "G\n";
    }