#include "dungeonManager.h"

#include "dungeonUI.h"
#include "../player/Player/Player.h"

void dungeonManager::Initialize()
{
    BattleCount = 0; // Stage 시작은 0 으로 초기화
    b_LifeCheck = true; // 시작할떈 살아있어야지?.
    b_Wincheck = true;
}

bool dungeonManager::setMonster(vector<Monster*> mons) // 몬스터 값이 있는지 없는지 확인 이후 반환
{
    if (!mons.empty()) // 없는지 있는지 확인 비어있지 않으면 treu 비었으면 false
    {
        // Monster Monster_ = mons; // vector 값이 있으면 
        return true;
    }
    cout << " 망했어요 몬스터가 없어요 " << '\n'; // 예외 확인 
    return false;
}

// monster Data를 vector 값으로 묶어서 가져와야하네?.. 망했네?..
void dungeonManager::StartDungeon(Player* Player_) // player 데이터와 monster 데이터 받아서 실행 ( 몬스터 여러마리 넣을려먼 vector로 입력 받기 >
{
    if (Player_ == nullptr)
        return;

<<<<<<< HEAD
	// Battle Logic
	for (Select = 1; Select <= Last_Stage; Select++) // 선택지가 아닌 자동으로 입장하는 형식
	{
		if (Select % Shop_Stage == 0 && Select != 0 ) // 5로 나눴을 때 0이면 5State 5번째 , 10번 째니 조절 가능
			EnterShop(Player_);


		// TODO : 몬스터 연동
		if (Select == Last_Stage)
		{
			Monster_ = Mons_g.Create(Last_Stage);
			b_Wincheck = BattleSystem::getInstance().Battle(*Player_, *Monster_); // 일반 던전
			playerLifeCheck(Player_);// 생존 유무확인 
			if (b_Wincheck)  // 승리 유무 확인 져서 나오면 죽은거지 
				Monster_->giveLoot(*Player_);
			// Todo : 보스전
		}
		else if (HiddenRand()) // 히든 던전 입장 히든은 만들어 두는게 좋을듯?.
		{
			Select--; //히든은 적용 안함
			Monster_ = Mons_g.Create(0);
			BattleSystem::getInstance().Battle(*Player_, *Monster_);
			Monster_->giveLoot(*Player_);

		}
		//b_Wincheck = BattleSystem::getInstance().Battle(ply,mons); // battle을 bool 값으로
		else
		{
			Monster_ = Mons_g.Create(Select);
			b_Wincheck = BattleSystem::getInstance().Battle(*Player_, *Monster_); // 일반 던전
			playerLifeCheck(Player_);// 생존 유무확인 
			if (b_Wincheck)  // 승리 유무 확인 져서 나오면 죽은거지 
				Monster_->giveLoot(*Player_);
		}

		if (Monster_ != nullptr) //  몬스터 존제 하면 삭제 상점만 했다면 캇!
			delete Monster_;

		if (!b_LifeCheck)
			break;

	}
=======
    Initialize(); // 기초 데이터 초기화 
    // 시작전 데이터 복붙
    int Select = 0; // 상점 스킵 또는 던전 입장 선택
    // 초기값
    string area_Name = "시작의 땅";
    string dungeon_Log = "던전에 진입했습니다.";

    // Battle Logic
    while (b_LifeCheck) // 반복 player 가 살아있는지 확인
    {
        displayDungeon(area_Name, dungeon_Log);
        // Todo : 입력을 받아 진행 / 아이템 / 휴식 / 종료하기 기능 구현
        
        for (Select = 1; Select <= Last_Stage; Select++) // 선택지가 아닌 자동으로 입장하는 형식
        {
            if (Select % Shop_Stage == 0 && Select != 0) // 5로 나눴을 때 0이면 5State 5번째 , 10번 째니 조절 가능
                EnterShop(Player_);
            
            // TODO : 던전 관련 올려놓긴했는데 몬스터는 한마리씩 들어오는건 battle system 에서 고치는대로 수정하겠습니다.
            // TODO : 그리고 몬스터 DB 가 필요 해.... 우어어어ㅓ어..
            if (Select == Last_Stage) // 10번째 스테이지 
                ; // 보스 던전 입장 bool값으로 하는 던전 보스 DB는????? 
            else if (HiddenRand()) // 히든 던전 입장 히든은 만들어 두는게 좋을듯?.
            {
                EnterShop(Player_);

                // TODO : 몬스터 연동
                if (Select == Last_Stage)
                {
                    // Todo : 보스전
                }
                else if (HiddenRand()) // 히든 던전 입장 히든은 만들어 두는게 좋을듯?.
                {
                    // Todo: 히든
                }
                //b_Wincheck = BattleSystem::getInstance().Battle(ply,mons); // battle을 bool 값으로 
                else
                {
                    //b_Wincheck = BattleSystem::getInstance().Battle(*Player_, ); // 일반 던전
                    playerLifeCheck(Player_); // 생존 유무확인 
                    if (b_Wincheck) // 승리 유무 확인 져서 나오면 죽은거지 
                        ;
                }

                if (!b_LifeCheck)
                    break;
            }
        }
    }
>>>>>>> 1c5e2b0dfa455a6eca2e87a9dec5978980d961e0
}

Monster* dungeonManager::getrandmonster(vector<Monster*> mons)
{
    return mons[rand() % mons.size()]; // vector< 몬스터 > 크기만큼 랜덤으로 ( 동일한 몬스터 나올 수 있음 ) 
}

void dungeonManager::EnterShop(Player* player_)
{
    while (true) //상점 입장 확인
    {
        cout << " ------------ 상점 ---------" << '\n' << "입장 하시겠습니까? 1. 입장 / 2 스킵 ";
        int Shop_Select;
        cin >> Shop_Select; // 상점 입장 여부 

        if (Shop_Select == 1)
        {
            // TODO : 상점 연결
            //Shop_.showShopMenu; 매개변수 너무 많아서 일단 킵 
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
