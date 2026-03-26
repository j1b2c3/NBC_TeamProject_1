#include "Inventory.h"
#include "Player_Temp.h"
#include <iostream>

#include "ItemFactory.h"

void Inventory::addItem(int id, int amount) 
{
    if (!ItemFactory::exists(id)) 
    {
        std::cout << "[오류] 존재하지 않는 아이템 ID: " << id << "\n";
        return;
    }
    items[id] += amount;
    std::cout << "[아이템 획득] " << ItemFactory::getName(id) << " x" << amount << "\n";
}

void Inventory::removeItem(int id, int amount) 
{
    if (!hasItem(id)) return;

    items[id] -= amount;
    if (items[id] <= 0)
    {
        items.erase(id);
    }
}

bool Inventory::hasItem(int id) const 
{
    return items.count(id) > 0 && items.at(id) > 0;
}

void Inventory::useConsumable(int id, Player& player) {                                                                                                                                                                                                                                                           
    // 소모품인지 확인                                                                                                                                                                                                                                                                                            
    if (ItemFactory::getType(id) != ItemType::Consumable) {                                                                                                                                                                                                                                                       
        std::cout << "[오류] 소모품이 아닙니다.\n";
        return;
    }

    // 보유 확인
    if (!hasItem(id)) {
        std::cout << "[오류] 해당 아이템이 없습니다.\n";
        return;
    }

    Consumable& item = consumableDB[id];

    // 효과 적용
    int healed = std::min(item.hp, player.maxHP - player.hp);
    player.hp += healed;

    std::cout << "[아이템 사용] " << item.base.name
              << " → HP +" << healed
              << " (현재 HP: " << player.hp << "/" << player.maxHP << ")\n";

    // 사용 후 제거
    removeItem(id);
}

void Inventory::equipWeapon(int id, Player& player) 
{                                                                                                                                                                                                                                                             
      if (ItemFactory::getType(id) != ItemType::Weapon) 
      {                                                                                                                                                                                                                                                           
          std::cout << "[오류] 무기가 아닙니다.\n";                                                                                                                                                                                                                                                                 
          return; 
      }
      if (!hasItem(id)) 
      {
          std::cout << "[오류] 해당 아이템이 없습니다.\n";
          return;
      }

      // 이미 장착 중인 무기 해제
      if (equippedWeaponId != 0)
      {
          unequipWeapon(player);
      }

      // 장착
      equippedWeaponId = id;
      player.attack += weaponDB[id].attack;

      std::cout << "[장착] " << weaponDB[id].base.name
                << " → 공격력 +" << weaponDB[id].attack
                << " (현재 공격력: " << player.attack << ")\n";
}

void Inventory::equipArmor(int id, Player& player) 
{
    if (ItemFactory::getType(id) != ItemType::Armor) 
    {
        std::cout << "[오류] 방어구가 아닙니다.\n";
        return;
    }
    if (!hasItem(id)) 
    {
        std::cout << "[오류] 해당 아이템이 없습니다.\n";
        return;
    }

    // 이미 장착 중인 방어구 해제
    if (equippedArmorId != 0)
    {
        unequipArmor(player);
    }

    // 장착
    equippedArmorId = id;
    player.defense += armorDB[id].defense;

    std::cout << "[장착] " << armorDB[id].base.name
              << " → 방어력 +" << armorDB[id].defense
              << " (현재 방어력: " << player.defense << ")\n";
}

void Inventory::unequipWeapon(Player& player) 
{                                                                                                                                                                                                                                                                   
    if (equippedWeaponId == 0) 
    {                                                                                                                                                                                                                                                                                  
        std::cout << "[오류] 장착된 무기가 없습니다.\n";                                                                                                                                                                                                                                                          
        return; 
    }

    player.attack -= weaponDB[equippedWeaponId].attack;

    std::cout << "[해제] " << weaponDB[equippedWeaponId].base.name
              << " → 공격력 -" << weaponDB[equippedWeaponId].attack
              << " (현재 공격력: " << player.attack << ")\n";

    equippedWeaponId = 0;
}

void Inventory::unequipArmor(Player& player) 
{
    if (equippedArmorId == 0) 
    {
        std::cout << "[오류] 장착된 방어구가 없습니다.\n";
        return;
    }

    player.defense -= armorDB[equippedArmorId].defense;

    std::cout << "[해제] " << armorDB[equippedArmorId].base.name
              << " → 방어력 -" << armorDB[equippedArmorId].defense
              << " (현재 방어력: " << player.defense << ")\n";

    equippedArmorId = 0;
}

void Inventory::displayItems() const 
{                                                                                                                                                                                                                                                                            
    std::cout << "\n===== 인벤토리 =====\n";                                                                                                                                                                                                                                                                      
                                                                                                                                                                                                                                                                                                                    
    if (items.empty()) 
    {
        std::cout << "보유 중인 아이템이 없습니다.\n";
        return;
    }

    for (const auto& pair : items)
    {
        std::cout << "[" << pair.first << "] "
                  << ItemFactory::getName(pair.first)
                  << " x" << pair.second
                  << " (가격: " << ItemFactory::getPrice(pair.first) << "골드)\n";
    }

    std::cout << "====================\n";
}

void Inventory::displayEquipped() const 
{
    std::cout << "\n===== 장착 장비 =====\n";

    if (equippedWeaponId != 0)
        std::cout << "[무기] " << weaponDB[equippedWeaponId].base.name
                  << " (공격력 +" << weaponDB[equippedWeaponId].attack << ")\n";
    else
        std::cout << "[무기] 없음\n";

    if (equippedArmorId != 0)
        std::cout << "[방어구] " << armorDB[equippedArmorId].base.name
                  << " (방어력 +" << armorDB[equippedArmorId].defense << ")\n";
    else
        std::cout << "[방어구] 없음\n";

    std::cout << "=====================\n";
}