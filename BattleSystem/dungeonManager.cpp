#include "dungeonManager.h"

#include "dungeonUI.h"
#include "../player/Player/Player.h"

void dungeonManager::Initialize()
{
    b_LifeCheck = true; // 시작할떈 살아있어야지?.
    b_Wincheck = true;
    b_isShopVisited = false;
}
string getAreaName(int stageLevel)
{
    switch (stageLevel)
    {
    case 1: return "버려진 초소";
    case 2: return "피의 황무지";
    case 3: return "잊혀진 묘지";
    case 4: return "그림자 숲";
    case 5: return "울부짖는 동굴";
    case 6: return "폭풍의 절벽";
    case 7: return "불타는 심연";
    case 8: return "용의 둥지";
    case 9: return "하늘의 제단";
    case 0: return "기만자의 방"; // 히든
    default: return "알 수 없는 구역";
    }
}

// monster Data를 vector 값으로 묶어서 가져와야하네?.. 망했네?..
void dungeonManager::StartDungeon(Player* Player_) // player 데이터와 monster 데이터 받아서 실행 ( 몬스터 여러마리 넣을려먼 vector로 입력 받기 >
{
    if (Player_ == nullptr) return;
    Initialize(); // 기초 데이터 초기화 

    int stage = 1;
    string area_Name = "시작의 땅";
    string dungeon_Log = "던전에 진입했습니다.";

    // Battle Logic
    while (b_LifeCheck)
    {
        area_Name = getAreaName(stage);
        displayDungeon(area_Name, dungeon_Log);

        int Select;
        InputDigit(Select);
        
        switch (Select)
        {
        case 1:
            {
                // 상점 체크
                if (stage % Shop_Stage == 0 && !b_isShopVisited)
                {
                    EnterShop(Player_);
                    b_isShopVisited = true;
                }
                bool isHidden = false;
                // 몬스터 생성 (보스 vs 히든 vs 일반)
                if (stage >= Last_Stage)
                {
                    Monster_ = new FinalBoss(); // 보스 생성
                    dungeon_Log = "최종 보스와의 결전!";
                }
                else if (HiddenRand())
                {
                    Monster_ = Mons_g.Create(0); // 히든 몬스터
                    dungeon_Log = "히든 던전에 진입했습니다!";
                    isHidden = true;
                }
                else
                {
                    Monster_ = Mons_g.Create(stage); // 일반 몬스터
                    dungeon_Log = to_string(stage) + "구역 전투 중...";
                }

                // 전투 실행
                if (Monster_ != nullptr)
                {
                    b_Wincheck = BattleSystem::getInstance().Battle(*Player_, *Monster_);
                    playerLifeCheck(Player_);

                    if (b_Wincheck)
                    {
                        Monster_->giveLoot(*Player_);
                        dungeon_Log = Monster_->getName() + "에게 승리했습니다!";
                        if (!isHidden)
                        {
                            stage++;
                        }
                        b_isShopVisited = false;
                    }
                    delete Monster_;
                    Monster_ = nullptr;
                }

                if (stage > Last_Stage && b_Wincheck)
                {
                    cout << "던전을 클리어했습니다!" << endl;
                    return;
                }
                if (!b_LifeCheck)
                {
                    dungeon_Log = "눈앞이 캄캄해집니다...";
                    return;
                }
            }
            break;
        case 2: // 아이템

            // Player_->getInventory()->displayEquipped(); // 장비 호출
            // Player_->getInventory()->displayItems(); // 아이템 호출
            // showInventoryUI();
            break;
        case 3: //휴식 
            Player_->setCurHP(Player_->getMaxHP()); // 체력 만땅 딴거 필요한게 있으면 호출 플리즈
            dungeon_Log = "체력을 회복했습니다.";
            break;
        case 4: // 게임 종료 
            return;
        default: // 예외 처리
            dungeon_Log = "잘못된 입력입니다.";
            break;
        }
    }
}

void dungeonManager::EnterShop(Player* player_)
{
    while (true) //상점 입장 확인
    {
        cout << " ------------ 상점 ---------" << '\n' << "입장 하시겠습니까? 1. 입장 / 2 스킵 ";
        int Shop_Select;
        cin >> Shop_Select; // 상점 입장 여부 
        cin.ignore(100, '\n');

        if (Shop_Select == 1)
        {
            // TODO : 상점 연결
            cout << " ------ 상점에서 나갑니다 ----- " << '\n';
            break; // 끝나면 break해서 함수 탈출
        }
        if (Shop_Select == 2)
        {
            cout << " ------------상점을 지나쳤습니다.. " << '\n';
            break; // 반복문만 제거 
        }
        cout << "잘못된 입력입니다 다시 확인해주세요 " << '\n';
    }
}

// ToDo result 는 보상 확인 ??이거 한번더 확인해야할듯?. Battle System에서 확인하기 떄문에 제거 
bool dungeonManager::HiddenRand() // 히든던전 등장 확률
{
    int roll = rand() % 100;
    return roll < 5; // 5% 확률
}

void dungeonManager::playerLifeCheck(Player* Player_) // 플레이어 생존 책크 
{
    if (Player_->getCurHP() <= 0)
        b_LifeCheck = false; // 플레이어 뒈짐 게임 끝
    // 살이 있는데 뭘 true합니까 그냥 비워둡니다.
}
