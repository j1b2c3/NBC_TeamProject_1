#include "Inventory_UI.h"
#include "ItemFactory.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;


void displayInventory(int playerGold, const Inventory& inventory,
                      const std::vector<ItemInfo>& weapons,
                      const std::vector<ItemInfo>& armors,
                      const std::vector<ItemInfo>& consumables)
{
    displayInventoryHeader();

    // 자산 정보
    string goldDisplay = to_string(playerGold) + " G";
    cout << "|  보유 금화: " << left << setw(65) << goldDisplay << "|" << '\n';

    string equippedWeapon = inventory.getEquippedWeaponId() != 0
                                ? weaponDB.at(inventory.getEquippedWeaponId()).base.name
                                : "없음";
    string equippedArmor = inventory.getEquippedArmorId() != 0
                               ? armorDB.at(inventory.getEquippedArmorId()).base.name
                               : "없음";
    string equippedDisplay = "무기: " + equippedWeapon + "    방어구: " + equippedArmor;
    cout << "|  [장착 중]  " << left << setw(65) << equippedDisplay << "|" << '\n';

    cout << "|  --------------------------------------------------------------------------  |" << '\n';

    // [1] 무기 목록
    cout << "|  [1] 무기                                                                    |" << '\n';
    if (weapons.empty()) cout << "|      - (비어 있음)                                                           |" << '\n';
    for (const auto& item : weapons)
    {
        string fullDesc = "(" + item.desc + ")";
        cout << "|      - " << left << setw(15) << item.name << " x" << setw(3) << item.count << " " << left << setw(49)
            << fullDesc << "|" << '\n';
    }
    cout << "|                                                                              |" << '\n';

    // [2] 방어구 목록
    cout << "|  [2] 방어구                                                                  |" << '\n';
    if (armors.empty()) cout << "|      - (비어 있음)                                                           |" << '\n';
    for (const auto& item : armors)
    {
        string fullDesc = "(" + item.desc + ")";
        cout << "|      - " << left << setw(15) << item.name << " x" << setw(3) << item.count << " " << left << setw(49)
            << fullDesc << "|" << '\n';
    }
    cout << "|                                                                              |" << '\n';

    // [3] 소모품 목록
    cout << "|  [3] 소모품                                                                  |" << '\n';
    if (consumables.empty()) cout << "|      - (비어 있음)                                                           |" <<
        '\n';
    for (const auto& item : consumables)
    {
        string fullDesc = "(" + item.desc + ")";
        cout << "|      - " << left << setw(15) << item.name << " x" << setw(3) << item.count << " " << left << setw(49)
            << fullDesc << "|" << '\n';
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

            if (type == ItemType::Weapon)
            {
                info.name = weaponDB.at(id).base.name;
                info.desc = "공격력 +" + std::to_string(weaponDB.at(id).attack);
                weapons.push_back(info);
            }
            else if (type == ItemType::Armor)
            {
                info.name = armorDB.at(id).base.name;
                info.desc = "방어력 +" + std::to_string(armorDB.at(id).defense);
                armors.push_back(info);
            }
            else if (type == ItemType::Consumable)
            {
                info.name = consumableDB.at(id).base.name;
                info.desc = "HP +" + std::to_string(consumableDB.at(id).hp);
                consumables.push_back(info);
            }
        }

        displayInventory(player.getGold(), inventory, weapons, armors, consumables);

        int choice;
        std::cin >> choice;
        if (choice == 0) break;

        switch (choice)
        {
        case 1: handleWeaponAction(inventory, player, weapons);
            break;
        case 2: handleArmorAction(inventory, player, armors);
            break;
        case 3: handleConsumableAction(inventory, player, consumables);
            break;
        default: break;
        }
    }
}

void showConsumableListUI(const std::map<int, int>& consumables)
{
    cout << "+==============================================================================+" << '\n';
    cout << "|                          [ 소모품 목록 ]                                         |" << '\n';
    cout << "+==============================================================================+" << '\n';
    cout << "|                                                                              |" << '\n';

    if (consumables.empty())
    {
        cout << "|      - (비어 있음)                                                         |" << '\n';
    }

    for (const auto& [id, count] : consumables)
    {
        if (const Consumable* c = ItemManager::GetInstance().GetConsumable(id))
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

void displayInventoryHeader()
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
}

void handleWeaponAction(Inventory& inventory, Player& player, const std::vector<ItemInfo>& weapons)
{
    displayInventoryHeader();

    string goldDisplay = to_string(player.getGold()) + " G";
    cout << "|  보유 금화: " << left << setw(65) << goldDisplay << "|" << '\n';
    cout << "|  --------------------------------------------------------------------------  |" << '\n';

    cout << "|  무기                                                                        |" << '\n';
    if (weapons.empty())
    {
        cout << "|      - (비어 있음)                                                           |" << '\n';
    }
    for (int i = 0; i < static_cast<int>(weapons.size()); i++)
    {
        string num = to_string(i + 1) + ".";
        cout << "|      " << left << setw(3) << num << setw(15) << weapons[i].name
            << " x" << setw(3) << weapons[i].count
            << " (" << setw(35) << weapons[i].desc << ") |" << '\n';
    }
    cout << "|                                                                              |" << '\n';
    cout << "+==============================================================================+" << '\n';
    cout << "|  [무기 장착]  번호를 선택하세요                   [0] 뒤로가기               |" << '\n';
    cout << "+==============================================================================+" << '\n';
    cout << "  선택 >> ";

    int choice;
    cin >> choice;
    if (choice == 0) return;
    if (choice < 1 || choice > static_cast<int>(weapons.size()))
    {
        cout << "잘못된 입력입니다.\n";
        return;
    }
    int idx = 0;
    for (const auto& [id, count] : inventory.getItems())
    {
        if (ItemFactory::getType(id) == ItemType::Weapon)
        {
            if (++idx == choice)
            {
                inventory.equipWeapon(id, player);
                return;
            }
        }
    }
}

void handleArmorAction(Inventory& inventory, Player& player, const std::vector<ItemInfo>& armors)
{
    displayInventoryHeader();

    string goldDisplay = to_string(player.getGold()) + " G";
    cout << "|  보유 금화: " << left << setw(65) << goldDisplay << "|" << '\n';
    cout << "|  --------------------------------------------------------------------------  |" << '\n';

    cout << "|  방어구                                                                      |" << '\n';
    if (armors.empty())
    {
        cout << "|      - (비어 있음)                                                           |" << '\n';
    }
    for (int i = 0; i < static_cast<int>(armors.size()); i++)
    {
        string num = to_string(i + 1) + ".";
        cout << "|      " << left << setw(3) << num << setw(15) << armors[i].name
            << " x" << setw(3) << armors[i].count
            << " (" << setw(35) << armors[i].desc << ") |" << '\n';
    }
    cout << "|                                                                              |" << '\n';
    cout << "+==============================================================================+" << '\n';
    cout << "|  [방어구 장착]  번호를 선택하세요                 [0] 뒤로가기               |" << '\n';
    cout << "+==============================================================================+" << '\n';
    cout << "  선택 >> ";

    int choice;
    cin >> choice;
    if (choice == 0) return;
    if (choice < 1 || choice > static_cast<int>(armors.size()))
    {
        cout << "잘못된 입력입니다.\n";
        return;
    }
    int idx = 0;
    for (const auto& [id, count] : inventory.getItems())
    {
        if (ItemFactory::getType(id) == ItemType::Armor)
        {
            if (++idx == choice)
            {
                inventory.equipArmor(id, player);
                return;
            }
        }
    }
}

void handleConsumableAction(Inventory& inventory, Player& player, const std::vector<ItemInfo>& consumables)
{
    displayInventoryHeader();

    string goldDisplay = to_string(player.getGold()) + " G";
    cout << "|  보유 금화: " << left << setw(65) << goldDisplay << "|" << '\n';
    cout << "|  --------------------------------------------------------------------------  |" << '\n';

    cout << "|  소모품                                                                      |" << '\n';
    if (consumables.empty())
    {
        cout << "|      - (비어 있음)                                                           |" << '\n';
    }
    for (int i = 0; i < static_cast<int>(consumables.size()); i++)
    {
        string num = to_string(i + 1) + ".";
        cout << "|      " << left << setw(3) << num << setw(15) << consumables[i].name
            << " x" << setw(3) << consumables[i].count
            << " (" << setw(35) << consumables[i].desc << ") |" << '\n';
    }
    cout << "|                                                                              |" << '\n';
    cout << "+==============================================================================+" << '\n';
    cout << "|  [소모품 사용]  번호를 선택하세요                 [0] 뒤로가기               |" << '\n';
    cout << "+==============================================================================+" << '\n';
    cout << "  선택 >> ";

    int choice;
    cin >> choice;
    if (choice == 0) return;
    if (choice < 1 || choice > static_cast<int>(consumables.size()))
    {
        cout << "잘못된 입력입니다.\n";
        return;
    }
    int idx = 0;
    for (const auto& [id, count] : inventory.getItems())
    {
        if (ItemFactory::getType(id) == ItemType::Consumable)
        {
            if (++idx == choice)
            {
                inventory.useConsumable(id, player);
                return;
            }
        }
    }
}
