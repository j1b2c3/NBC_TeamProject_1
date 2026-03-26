#pragma once
#include <map>
#include "itemDB.h"

class Player; // 전방 선언

class Inventory
{
private:
    std::map<int, int> items;
    int equippedWeaponId;
    int equippedArmorId;
    
public:
    Inventory() : equippedWeaponId(0), equippedArmorId(0) {}
    
    void addItem(int id, int amount = 1);
    void removeItem(int id, int amount = 1);
    
    void useConsumable(int id, Player& player);
    void equipWeapon(int id, Player& player);
    void equipArmor(int id, Player& player);
    void unequipWeapon(Player& player);
    void unequipArmor(Player& player);

    void displayItems() const;
    void displayEquipped() const;

    bool hasItem(int id) const;
    int getEquippedWeaponId() const { return equippedWeaponId; }
    int getEquippedArmorId() const  { return equippedArmorId; }
};