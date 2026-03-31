#include "MonsterDB.h"
using namespace std;

int FinalBoss::attack(Player& player, bool is_defence, string& action_str)
{
    if (isCharging)
    {
        float critical = is_defence ? 0.25f : 10.0f;
        action_str.assign("불길한 일격!");
        int heavyDamage = calculateDamage(static_cast<int>((float)atk * critical), player.getDef(), is_defence);

        isCharging = false;
        return  player.TakeDamage(heavyDamage, false);
    }

    // 2. 20% 확률로 기 모으기
    if (rand() % 100 < 20)
    {
        specialMessage.assign(name + "로부터 불길한 기운이 엄습한다...\n방어를 하지 않으면 끔찍한 일이 벌어질 것 같다!");
        isCharging = true;
        return 0;
    }

    // 3. 일반 공격
    return Monster::attack(player, is_defence, action_str);
}