#include "Inventory_UI.h"
#include "ItemFactory.h"
#include "Inventory.h"
#include "../Player/Player/player.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;


void displayInventory(Player& player)
{
    Inventory& inventory = *player.getInventory();

    auto weapons = inventory.getWeapons();
    auto armors = inventory.getArmors();
    auto consumables = inventory.getConsumables();
    displayInventoryHeader();

    // 자산 정보
    string goldDisplay = to_string(player.getGold()) + " G";
    cout << "|  보유 금화: " << left << setw(65) << goldDisplay << "|" << '\n';

    string equippedWeapon = inventory.getEquippedWeaponName();
    string equippedArmor = inventory.getEquippedArmorName();

    string equippedDisplay = "무기: " + equippedWeapon + "    방어구: " + equippedArmor;
    cout << "|  [장착 중]  " << left << setw(65) << equippedDisplay << "|" << '\n';

    cout << "|  --------------------------------------------------------------------------  |" << '\n';

    // [1] 무기 목록
    cout << "|  [1] 무기                                                                    |" << '\n';
    if (weapons.empty()) cout << "|      - (비어 있음)                                                           |" << '\n';
    for (const auto& item : weapons)
    {
        string fullDesc = "(" + item.desc + ")";
        cout << "|      - " << left << setw(30) << item.name << " x" << setw(3) << item.count << " " << left << setw(34)
            << fullDesc << "|" << '\n';
    }
    cout << "|                                                                              |" << '\n';

    // [2] 방어구 목록
    cout << "|  [2] 방어구                                                                  |" << '\n';
    if (armors.empty()) cout << "|      - (비어 있음)                                                           |" << '\n';
    for (const auto& item : armors)
    {
        string fullDesc = "(" + item.desc + ")";
        cout << "|      - " << left << setw(30) << item.name << " x" << setw(3) << item.count << " " << left << setw(34)
            << fullDesc << "|" << '\n';
    }
    cout << "|                                                                              |" << '\n';

    // [3] 소모품 목록
    cout << "|  [3] 소모품                                                                  |" << '\n';
    if (consumables.empty())
        cout << "|      - (비어 있음)                                                           |" <<
            '\n';
    for (const auto& item : consumables)
    {
        string fullDesc = "(" + item.desc + ")";
        cout << "|      - " << left << setw(30) << item.name << " x" << setw(3) << item.count << " " << left << setw(34)
            << fullDesc << "|" << '\n';
    }

    cout << "|                                                                              |" << '\n';
    cout << "+==============================================================================+" << '\n';
    cout << "|                                                                              |" << '\n';
    cout << "|      [1] 무기        [2] 방어구          [3] 소모품         [0] 가방 닫기    |" << '\n';
    cout << "|                                                                              |" << '\n';
    cout << "+==============================================================================+" << '\n';
    cout << "|    선택 >>                                                                   | " << '\n';
    cout << "+==============================================================================+" << '\n';
    // Todo: 커서 위치
}

void showInventoryUI(Player& player)
{
    Inventory& inventory = *player.getInventory();

    while (true)
    {
        displayInventory(player);

        int choice;
        std::cin >> choice;
        if (choice == 0) break;

        switch (choice)
        {
        case 1: handleWeaponAction(player);
            break;
        case 2: handleArmorAction(player);
            break;
        case 3: handleConsumableAction(player);
            break;
        default: break;
        }
    }
}

void showConsumableListUI(Player& player)
{
    Inventory& inventory = *player.getInventory();
    const auto& consumables = inventory.getItems();

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
        if (ItemFactory::getType(id) != ItemType::Consumable) continue;
        if (const Consumable* c = ItemManager::GetInstance().GetConsumable(id))
        {
            string desc = "HP +" + to_string(c->hp);
            string fullDesc = "(" + desc + ")";

            cout << "|      - " << left << setw(30) << c->base.name
                << " x" << setw(3) << count << setw(25) << fullDesc << "   |" << '\n';
        }
    }

    cout << "|                                                                              |" << '\n';
    cout << "+==============================================================================+" << '\n';
}

void displayInventoryHeader()
{
    system("cls");
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

void handleWeaponAction(Player& player)
{
    Inventory& inventory = *player.getInventory();
    auto weapons = inventory.getWeapons();

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
        string fullDesc = "(" + weapons[i].desc + ")";

        cout << "|      " << left << setw(3) << num << setw(30) << weapons[i].name
            << " x" << setw(3) << weapons[i].count << setw(25) << fullDesc << "         |" << '\n';
    }
    cout << "|                                                                              |" << '\n';
    cout << "+==============================================================================+" << '\n';
    cout << "|  [무기 장착]  번호를 선택하세요                   [0] 뒤로가기               |" << '\n';
    cout << "+==============================================================================+" << '\n';
    cout << "|    선택 >>                                                                   | " << '\n';
    cout << "+==============================================================================+" << '\n';
    // Todo : 커서 위치

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

void handleArmorAction(Player& player)
{
    Inventory& inventory = *player.getInventory();
    auto armors = inventory.getArmors();

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
        string fullDesc = "(" + armors[i].desc + ")";

        cout << "|      " << left << setw(3) << num << setw(30) << armors[i].name
            << " x" << setw(3) << armors[i].count << setw(25) << fullDesc << "         |" << '\n';
    }
    cout << "|                                                                              |" << '\n';
    cout << "+==============================================================================+" << '\n';
    cout << "|  [방어구 장착]  번호를 선택하세요                 [0] 뒤로가기               |" << '\n';
    cout << "+==============================================================================+" << '\n';
    cout << "|    선택 >>                                                                   | " << '\n';
    cout << "+==============================================================================+" << '\n';
    // Todo : 커서 위치

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

void handleConsumableAction(Player& player)
{
    Inventory& inventory = *player.getInventory();
    auto consumables = inventory.getConsumables();

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
        string fullDesc = "(" + consumables[i].desc + ")";

        cout << "|      " << left << setw(3) << num << setw(30) << consumables[i].name
            << " x" << setw(3) << consumables[i].count << setw(25) << fullDesc << "         |" << '\n';
    }
    cout << "|                                                                              |" << '\n';
    cout << "+==============================================================================+" << '\n';
    cout << "|  [소모품 사용]  번호를 선택하세요                 [0] 뒤로가기               |" << '\n';
    cout << "+==============================================================================+" << '\n';
    cout << "|    선택 >>                                                                   | " << '\n';
    cout << "+==============================================================================+" << '\n';
    // Todo : 커서 위치

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
