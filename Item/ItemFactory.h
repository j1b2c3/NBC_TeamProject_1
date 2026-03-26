#pragma once                                                                                                                                                                                                                                                                                                      
#include <string>                                                                                                                                                                                                                                                                                                 
#include "itemDB.h"                                                                                                                                                                                                                                                                                               
                  
class ItemFactory 
{
public:
    // ID로 아이템 이름 반환
    static std::string getName(int id);

    // ID로 아이템 가격 반환
    static int getPrice(int id);

    // ID로 아이템 존재 여부 확인
    static bool exists(int id);

    // ID로 타입 반환
    static ItemType getType(int id);
};