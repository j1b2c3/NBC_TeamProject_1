#include "Inventory_UI.h"
#include "ItemFactory.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

void displayInventory(int playerGold, 
                        const vector<ItemInfo>& weapons, 
                        const vector<ItemInfo>& armors, 
                        const vector<ItemInfo>& consumables) 
{
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

void showInventoryUI(Inventory& inventory, Player& player) 
{
    while (true) 
    {
        std::vector<ItemInfo> weapons, armors, consumables;

        for (const auto& [id, count] : inventory.getItems()) 
        {
            ItemType type = ItemFactory::getType(id);
            ItemInfo info;
            info.count = count;

            if (type == ItemType::Weapon) {
                info.name = weaponDB.at(id).base.name;
                info.desc = "공격력 +" + std::to_string(weaponDB.at(id).attack);
                weapons.push_back(info);
            } else if (type == ItemType::Armor) {
                info.name = armorDB.at(id).base.name;
                info.desc = "방어력 +" + std::to_string(armorDB.at(id).defense);
                armors.push_back(info);
            } else if (type == ItemType::Consumable) {
                info.name = consumableDB.at(id).base.name;
                info.desc = "HP +" + std::to_string(consumableDB.at(id).hp);
                consumables.push_back(info);
            }
        }

        displayInventory(player.getGold(), weapons, armors, consumables);

        int choice;
        std::cin >> choice;
        if (choice == 0) break;

        // 이후 선택 처리 (장착/사용 등)
    }
}

void showConsumableListUI(const std::map<int, int>& consumables)
{
    cout << "+==============================================================================+" << '\n';
    cout << "|                          [ 소모품 목록 ]                                    |" << '\n';
    cout << "+==============================================================================+" << '\n';
    cout << "|                                                                              |" << '\n';

    if (consumables.empty()) 
    {
        cout << "|      - (비어 있음)                                                           |" << '\n';
    }
    
    for (const auto& [id, count] : consumables) 
    {
        const Consumable* c = ItemManager::GetInstance().GetConsumable(id);
        if (c) 
        {
            string desc = "HP +" + to_string(c->hp);
            cout << "|      - " << left << setw(15) << c->base.name
                 << " x" << setw(3) << count
                 << " (" << setw(35) << desc << ") |" << '\n';
        }
    }

    cout << "|                                                                              |" << '\n';
    cout << "+==============================================================================+" << '\n';
}

