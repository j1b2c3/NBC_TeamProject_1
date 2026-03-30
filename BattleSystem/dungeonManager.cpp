#include "dungeonManager.h"
#include "../player/Player/Player.h"

void dungeonManager::Initialize()
{
	BattleCount = 0; // Stage 시작은 0 으로 초기화
	b_LifeCheck = true; // 시작할떈 살아있어야지?.
	Reward = Stage_Category::None; // 첫 시작시 보상은 없는걸로 
	b_Wincheck = true;
}
bool dungeonManager::setMonster(vector<Monster*> mons) // 몬스터 값이 있는지 없는지 확인 이후 반환
{
	if (!mons.empty()) // 없는지 있는지 확인 비어있지 않으면 treu 비었으면 false
<<<<<<< HEAD
=======
	{
		// Monster Monster_ = mons; // vector 값이 있으면 
>>>>>>> Dev
		return true;
	else
	{
		cout << " 망했어요 몬스터가 없어요 " << endl; // 예외 확인 
		return false;
	}
}

// monster Data를 vector 값으로 묶어서 가져와야하네?.. 망했네?..
void dungeonManager::StartDungeon(Player* Player_ ,vector<Monster*> Mons) // player 데이터와 monster 데이터 받아서 실행 ( 몬스터 여러마리 넣을려먼 vector로 입력 받기 >
{
	if (ply == nullptr)
		return;
	
	Initialize(); // 기초 데이터 초기화 
<<<<<<< HEAD
	// 시작전 데이터 복붙
=======
>>>>>>> Dev
	int Select = 0; // 상점 스킵 또는 던전 입장 선택

	// Battle Logic
	while (b_LifeCheck)// 반복 player 가 살아있는지 확인
	{

		for (Select = 1; Select <= Last_Stage; Select++) // 선택지가 아닌 자동으로 입장하는 형식
		{
			if (Select % Shop_Stage == 0) // 5로 나눴을 때 0이면 5State 5번째 , 10번 째니 조절 가능
<<<<<<< HEAD
				EnterShop(Player_);


			// TODO : 던전 관련 올려놓긴했는데 몬스터는 한마리씩 들어오는건 battle system 에서 고치는대로 수정하겠습니다.
			// TODO : 그리고 몬스터 DB 가 필요 해.... 우어어어ㅓ어..
			if (Select == Last_Stage) // 10번째 스테이지 
				; // 보스 던전 입장 bool값으로 하는 던전 보스 DB는????? 
			else if (HiddenRand()) // 히든 던전 입장 히든은 만들어 두는게 좋을듯?.
			{
				//BattleSystem::getInstance()
				;
=======
				EnterShop();
			
			// TODO : 몬스터 연동
			if (Select == Last_Stage)
			{
				// Todo : 보스전
			}
			else if (HiddenRand()) // 히든 던전 입장 히든은 만들어 두는게 좋을듯?.
			{
				// Todo: 히든
>>>>>>> Dev
			}
				//b_Wincheck = BattleSystem::getInstance().Battle(ply,mons); // battle을 bool 값으로 
			else
				b_Wincheck = BattleSystem::getInstance().Battle(*Player_, *getrandmonster(Mons)); // 일반 던전

<<<<<<< HEAD
			playerLifeCheck(Player_);// 생존 유무확인 
			if (b_Wincheck)  // 승리 유무 확인 져서 나오면 죽은거지 
				DugeonClear_Root(Player_); // 루팅
=======
			playerLifeCheck(ply);// 생존 유무확인 
			if (b_Wincheck)  // 승리 유무 확인 져서 나오면 죽은거지 
				DugeonClear_Root(); // 루팅
			if (!b_LifeCheck)
				break;
>>>>>>> Dev
		}
		
	}
}
Monster* dungeonManager::getrandmonster(vector<Monster*> mons)
{
	return mons[rand() % mons.size()]; // 크기 만큼 랜덤으로
}

void dungeonManager::EnterShop(Player* player_)
{
	while (true) //상점 입장 확인
	{
		cout << " ------------ 상점 ---------" << endl << "입장 하시겠습니까? 1. 입장 / 2 스킵 ";
		int Shop_Select;
		cin >> Shop_Select;// 상점 입장 여부 

		if (Shop_Select == 1)
		{
<<<<<<< HEAD

			// TODO : 상점 직접적으로 불러올려면 singletoon으로 되어 있어야겠쥬?
			// 상점  호출
			; // 상점 입장 
			cout << " ------ 상점 탈출 ----- " << endl;
=======
			// TODO : 상점 연결
			cout << " ------ 상점에서 나갑니다 ----- " << endl;
>>>>>>> Dev
			break;// 끝나면 break해서 함수 탈출
		}
		else if (Shop_Select == 2)
		{
			cout << " ------------상점을 지나쳤습니다.. " << endl;
			break;// 반복문만 제거 
		}
		else
			cout << "잘못된 입력입니다 다시 확인해주세요 " << endl;
	}
}
// ToDo result 는 보상 확인 ??이거 한번더 확인해야할듯?. Battle System에서 확인하기 떄문에 제거 
void dungeonManager::DugeonClear_Root(Player* player_) // 클리어 보상
{
	// 클리어 보상을 itemDb에서 singletoon에서 
	if (Reward == Stage_Category::Normal) // 노말 클리서이 보상 // Rooting 함수 호출하면 됩니다.
		; // inventory 호출해와서 item 분배 
	else if (Reward == Stage_Category::Hidden) // hidden 클리어시 보상
		;
	else if (Reward == Stage_Category::Boss) // Boss 클리어시 보상
		;
	Reward = Stage_Category::None; // 현제 보상 NOde으로 
}
bool dungeonManager::HiddenRand() // 히든던전 등장 확률
{
	int roll = rand() % 100;
	return roll < 5; // 5% 확률
}
<<<<<<< HEAD
void dungeonManager::playerLifeCheck(Player* Player_) // 플레이어 생존 책크 
{
	if (Player_->getCurHP() <= 0) 
=======
void dungeonManager::playerLifeCheck(Player* ply) // 플레이어 생존 책크 
{
	if (ply->getCurHP() <= 0) 
>>>>>>> Dev
		b_LifeCheck = false; // 플레이어 뒈짐 게임 끝
	// 살이 있는데 뭘 true합니까 그냥 비워둡니다.

}

