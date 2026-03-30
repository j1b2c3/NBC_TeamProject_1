#include "MonsterDB.h"
using namespace std;

int FinalBoss::attack(Player& player)
{
    if (isCharging)
    {
        cout << "📢 [BOSS] 보스가 준비했던 강력한 일격을 가합니다! (데미지 2배)" << endl;
        int heavyDamage = calculateDamage(atk * 2, player.getDef());
        player.TakeDamage(heavyDamage);

        isCharging = false; 
        return heavyDamage;
    }

    // 2. 20% 확률로 기 모으기
    if (rand() % 100 < 20)
    {
        cout << "[BOSS] 보스가 강력한 공격을 위해 기를 모으기 시작합니다!" << endl;
        isCharging = true;
        return 0; 
    }

    // 3. 일반 공격
    return Monster::attack(player);
}