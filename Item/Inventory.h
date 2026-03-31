#pragma once
#include <map>
#include <string>
#include <vector>

struct ItemInfo 
{
    std::string name;
    int count;
    std::string desc;
};

class Player; // 전방 선언

class Inventory
{
private:
    std::map<int, int> items;
    int equippedWeaponId;
    int equippedArmorId;
    
public:
    Inventory() : equippedWeaponId(0), equippedArmorId(0)
    {
        items[301] = 3; // 채력 포션 3개
    }
    
    void addItem(int id, int amount = 1);
    void removeItem(int id, int amount = 1);
    
    void useConsumable(int id, Player& player);
    void equipWeapon(int id, Player& player);
    void equipArmor(int id, Player& player);
    void unequipWeapon(Player& player);
    void unequipArmor(Player& player);

    bool hasItem(int id) const;
    int getEquippedWeaponId() const { return equippedWeaponId; }
    int getEquippedArmorId() const  { return equippedArmorId; }
    std::string getEquippedWeaponName() const;
    std::string getEquippedArmorName() const;
    
    const std::map<int, int>& getItems() const { return items; }
    std::vector<ItemInfo> getWeapons() const;
    std::vector<ItemInfo> getArmors() const;
    std::vector<ItemInfo> getConsumables() const;
};