📋 TextRPG Project
C++로 구현한 텍스트 기반 던전 탐험 RPG 게임입니다. 객체 지향 프로그래밍(OOP) 원칙을 활용하여 설계되었으며, 플레이어의 성장과 던전 공략을 핵심 재미 요소로 담고 있습니다.

🚀 시작하기
개발 환경
Language: C++

IDE: Visual Studio / JetBrains Rider

Version Control: Git

실행 방법
1. 
exe 파일을 다운로드 및 실행합니다.

2. 
저장소를 클론합니다.

Bash
git clone https://github.com/j1b2c3/NBC_TeamProject_1.git
C++ 컴파일러가 포함된 IDE에서 프로젝트 파일을 엽니다.

솔루션 빌드 후 실행 파일을 실행합니다.


🎮 주요 기능
1. 캐릭터 관리
직업 선택: 전사, 궁수, 도적, 마법사
각각 클래스별 서로 다른 특징 존재
능력치 시스템: 레벨, 공격력, 방어력, 체력의 세분화된 스탯

성장 시스템: 전투 승리를 통한 경험치 획득 및 레벨업

2. 인벤토리 및 상점
아이템 장착: 무기와 방어구를 장착하여 캐릭터 능력치 강화

상점 시스템: 골드를 사용하여 소모품 구매 및 장비 거래

데이터베이스: 안정적인 아이템 데이터 관리 시스템

3. 던전 및 전투
턴제 전투: 일반 공격과 확률적으로 발생하는 특수 공격, 회피를 활용한 전투 방식

다양한 몬스터: 층별로 강력해지는 몬스터 패턴 구현

보상 시스템: 던전 클리어 시 아이템 및 재화 획득

🛠 시스템 설계 (Architecture)
본 프로젝트는 유지보수와 확장성을 위해 다음과 같은 구조를 지향합니다.

Class Diagram 개념 구조

Character (Base Class): Player와 Monster의 부모 클래스

Item (Base Class): Weapon, Armor, Consumable 등의 아이템 계층 구조

Manager Classes: GameManager, ShopManager 등 기능을 분리하여 관리

📂 프로젝트 구조
Plaintext
src/
├── Main.cpp           # 게임 진입점
├── Player/            # 플레이어 관련 클래스 (Stat, Inventory)
├── Monster/           # 몬스터 데이터 및 AI 로직
├── Item/              # 아이템 클래스 및 데이터베이스
└── Utils/             # 공통 유틸리티 및 인터페이스
📝 팀 정보 및 기여자
팀 프로젝트 명: TextRPG
8조
김환, 신보원, 이길호, 최정빈, 홍성돈

주요 개발 내용: C++ 기반 객체 지향 설계 및 게임 로직 구현
