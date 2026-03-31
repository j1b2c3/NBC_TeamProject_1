#include "Inventory.h"
#include "ItemFactory.h"
#include "../Player/Player/player.h"
#include <iostream>

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

std::string Inventory::getEquippedWeaponName() const
{
    if (equippedWeaponId == 0) return "없음";
    return weaponDB.at(equippedWeaponId).base.name;
}


std::string Inventory::getEquippedArmorName() const
{
    if (equippedArmorId == 0) return "없음";
    return armorDB.at(equippedArmorId).base.name;
}

std::vector<ItemInfo> Inventory::getWeapons() const
{
    std::vector<ItemInfo> result;
    for (const auto& [id, count] : items)
        if (ItemFactory::getType(id) == ItemType::Weapon)
            result.push_back({ id, weaponDB.at(id).base.name, count,
                               "공격력 +" + std::to_string(weaponDB.at(id).attack) });
    return result;
}

std::vector<ItemInfo> Inventory::getArmors() const
{
    std::vector<ItemInfo> result;
    for (const auto& [id, count] : items)
        if (ItemFactory::getType(id) == ItemType::Armor)
            result.push_back({ id, armorDB.at(id).base.name, count,
                               "방어력 +" + std::to_string(armorDB.at(id).defense) });
    return result;
}

std::vector<ItemInfo> Inventory::getConsumables() const
{
    std::vector<ItemInfo> result;
    for (const auto& [id, count] : items)
        if (ItemFactory::getType(id) == ItemType::Consumable)
            result.push_back({ id, consumableDB.at(id).base.name, count,
                               "HP +" + std::to_string(consumableDB.at(id).hp) });
    return result;
}

// 소모품 사용
std::string Inventory::useConsumable(int id, Player& player) 
{                                                                                                                                                                                                                                                           
    // 소모품인지 확인                                                                                                                                                                                                                                                                                            
    if (ItemFactory::getType(id) != ItemType::Consumable) 
    {
        return "[오류] 소모품이 아닙니다.";
    }

    // 보유 확인
    if (!hasItem(id)) 
    {
        return "[오류] 해당 아이템이 없습니다.";
    }

    Consumable& item = consumableDB[id];

    // 체력 회복
    int healed = std::min(item.hp, player.getMaxHP() - player.getCurHP());
    player.setCurHP(player.getCurHP() + healed);

    std::string str;
    str.assign("HP +" + to_string(healed)
        + " (현재 HP: " + to_string(player.getCurHP()) + "/" + to_string(player.getMaxHP()) + ")");

    // 사용 후 제거
    removeItem(id);
    return str;
}

// 무기 장착
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
      player.setAtk(player.getAtk() + weaponDB[id].attack);
      removeItem(id);

      std::cout << "[장착] " << weaponDB[id].base.name
                << " → 공격력 +" << weaponDB[id].attack
                << " (현재 공격력: " << player.getAtk() << ")\n";
}

// 방어구 장착
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
    player.setDef(player.getDef() + armorDB[id].defense);
    removeItem(id);

    std::cout << "[장착] " << armorDB[id].base.name
              << " → 방어력 +" << armorDB[id].defense
              << " (현재 방어력: " << player.getDef() << ")\n";
}

// 무기 장착 해제
void Inventory::unequipWeapon(Player& player) 
{                                                                                                                                                                                                                                                                   
    if (equippedWeaponId == 0) 
    {                                                                                                                                                                                                                                                                                  
        std::cout << "[오류] 장착된 무기가 없습니다.\n";                                                                                                                                                                                                                                                          
        return; 
    }

    player.setAtk(player.getAtk() - weaponDB[equippedWeaponId].attack);
    items[equippedWeaponId] += 1;

    std::cout << "[해제] " << weaponDB[equippedWeaponId].base.name
              << " → 공격력 -" << weaponDB[equippedWeaponId].attack
              << " (현재 공격력: " << player.getAtk() << ")\n";

    equippedWeaponId = 0;
}

// 방어구 장착 해제
void Inventory::unequipArmor(Player& player) 
{
    if (equippedArmorId == 0) 
    {
        std::cout << "[오류] 장착된 방어구가 없습니다.\n";
        return;
    }

    player.setDef(player.getDef() - armorDB[equippedArmorId].defense);
    items[equippedArmorId] += 1;

    std::cout << "[해제] " << armorDB[equippedArmorId].base.name
              << " → 방어력 -" << armorDB[equippedArmorId].defense
              << " (현재 방어력: " << player.getDef() << ")\n";

    equippedArmorId = 0;
}