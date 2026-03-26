#pragma once                                                                                                                                                                                                                                                                                                      
#include <string>                                                                                                                                                                                                                                                                                                 
// Todo : DB 추가 필요
// #include "itemDB.h"                                                                                                                                                                                                                                                                                               
                  
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
    // Todo : 임시 사용 중지
    // static ItemType getType(int id);
};