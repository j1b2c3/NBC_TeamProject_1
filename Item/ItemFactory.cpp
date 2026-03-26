#include "ItemFactory.h"

ItemType ItemFactory::getType(int id) 
{
    if (id >= 100 && id < 200) return ItemType::Weapon;
    if (id >= 200 && id < 300) return ItemType::Armor;
    if (id >= 300 && id < 400) return ItemType::Consumable;
    if (id >= 400 && id < 500) return ItemType::Loot;
    return ItemType::Money;
}

bool ItemFactory::exists(int id) 
{
    switch (getType(id)) {
    case ItemType::Weapon:     return weaponDB.count(id) > 0;
    case ItemType::Armor:      return armorDB.count(id) > 0;
    case ItemType::Consumable: return consumableDB.count(id) > 0;
    case ItemType::Loot:       return LootDB.count(id) > 0;
    case ItemType::Money:      return moneyDB.count(id) > 0;
    }
    return false;
}

std::string ItemFactory::getName(int id) 
{
    switch (getType(id)) {
    case ItemType::Weapon:     return weaponDB[id].base.name;
    case ItemType::Armor:      return armorDB[id].base.name;
    case ItemType::Consumable: return consumableDB[id].base.name;
    case ItemType::Loot:       return LootDB[id].base.name;
    case ItemType::Money:      return moneyDB[id].base.name;
    }
    return "알 수 없는 아이템";
}

int ItemFactory::getPrice(int id) 
{
    switch (getType(id)) 
    {
    case ItemType::Weapon:     return weaponDB[id].base.price;
    case ItemType::Armor:      return armorDB[id].base.price;
    case ItemType::Consumable: return consumableDB[id].base.price;
    case ItemType::Loot:       return LootDB[id].base.price;
    case ItemType::Money:      return moneyDB[id].base.price;
    }
    return 0;
}