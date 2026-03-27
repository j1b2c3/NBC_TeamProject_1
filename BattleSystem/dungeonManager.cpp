#include "dungeonManager.h"

void dungeonManager::Initialize()
{
	BattleCount = 0; // Stage 시작은 0 으로 초기화
	b_LifeCheck = true; // 시작할떈 살아있어야지?.
	Reward = Stage_Category::None; // 첫 시작시 보상은 없는걸로 
}

// monster Data를 vector 값으로 묶어서 가져와야하네?.. 망했네?..
void dungeonManager::StartDungeon(Player* ply, vector<Monster*> mons) // player 데이터와 monster 데이터 받아서 실행 ( 몬스터 여러마리 넣을려먼 vector로 입력 받기 >
{
	Initialize();
	// 시작전 데이터 입장 입력
	Player_ = ply;
	Monster_ = mons;
	int Select = 0; // 상점 스킵 또는 던전 입장 선택

	// Battle Logic
	while (b_LifeCheck)// 반복 player 가 살아있는지 확인
	{

		for (Select = 1; Select <= Last_Stage; Select++) // 선택지가 아닌 자동으로 입장하는 형식
		{
			if (Select % Shop_Stage == 0) // 5로 나눴을 때 0이면 5State 5번째 , 10번 째니 조절 가능
				EnterShop();

			if (Select == Last_Stage) // 10번째 스테이지 
				; // 보스 던전 입장 bool값으로 하는
			else if (HiddenRand()) // 히든 던전 입장 히든은 만들어 두는게 좋을듯?.
				;//b_LifeCheck = BattleSystem::getInstance().Battle(ply,mons); // battle을 bool 값으로 
			else
				; // 노말 던전 입장

			if (b_LifeCheck) // 생존 유무확인 
				DugenClear_Root(); // 루팅
		}
		// 수정 되어야 함
		/*
		cout << " ---------------- 던 --------------"
			cout << " 1. 던전 입장 / 2. 상점 / 0. 나가기 ( 상점 까지 입장 턴 : " << BattleCount << " ) " << endl;
		cin >> Select;
		*/
		// 던전 입장 조건 부터 ?

/*		switch (Select) //
		{
<<<<<<< HEAD
		case DungenMenu::Dungen_Enter: // Dungen 입장  보스 입장은 따로 만들지 않음.일단은.
			if (BattleCount == Last_Stage) // 보스 몬스터 체크 확인
=======
		case DungeonMenu::Dungeon_Enter: // Dungeon 입장  보스 입장은 따로 만들지 않음.일단은.
			if (BattleCount == Last_Stage) // 보스 몬스터 체크 확인 
>>>>>>> main
			{
				cout << " 보스던전에 입장합니다, 파이팅 " << endl;
				; // 보스 스테이지 Open
			}
			else
			{
				if (HiddenRand())//  hidden 던전 용으로 설정  일단 5퍼센트 확률로 입장되게 설정해 놓았음
				{
					cout << "  ------------  히든 입장 ! ------------" << endl;

				}
				else
					StartBattle(); // 일반 던전
			}
			battleResult(); // 보상 확인
			break;
		case DungenMenu::Store_Enter: // 상점 입장
			// 상점 입장 singleton 이 따로 들어왕함.
			break;
		case DungenMenu::Dungen_Exit: // 던전 out
			PlayChecking = false;
			cout << " 던전 에서 탈출합니다 ." << endl;
			//return 도 가능
			break;
		case default:
			cout << "잘못 입력된 방식입니다 다시 입력해주세요  :" << endl;
			break;
		}*/ // 횟수에 따른 입장 ( 1~ 4 일반 입장 5 상점 6 ~ 9  일반입장 10 상점 + 보스 입장 
	}
}

void dungeonManager::EnterShop()
{
	while (true) //상점 입장 확인
	{
		cout << " ------------ 상점 ---------" << endl << "입장 하시겠습니까? 1. 입장 / 2 스킵 ";
		int Shop_Select;
		cin >> Shop_Select;// 상점 입장 여부 

		if (Shop_Select == 1)
		{
			; // 상점 입장 
			cout << " ------ 상점 탈출 ----- " << endl;
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
// reslut 는 보상 확인 ??이거 한번더 확인해야할듯?. Battle System에서 확인하기 떄문에 제거 
void dungeonManager::DugenClear_Root() // 클리어 보상
{
	// 클리어 보상을 itemDb에서 singletoon에서 
	if (Reward == Stage_Category::Normal) // 노말 클리서이 보상
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
void dungeonManager::Rooting()
{
	tempData.amount = 1;
}
