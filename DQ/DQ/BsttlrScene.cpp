#include "BattleScene.h"

using namespace std;

BattleScene::BattleScene()
{
    player = nullptr;
    enemy = nullptr;
    isFinished = false;
}
BattleScene::~BattleScene()
{
    delete player;
    delete enemy;

}


void BattleScene::Init()
{
	state = BattleState::start;
    isFinished = false;
	player = new Character("プレイヤー", 30, 5);
	enemy = new Character("スライム", 8, 3);
  

}

void BattleScene::Update()
{
    switch (state)
    {
    case BattleState::start:
        cout << enemy->GetName() << "が　あらわれた！\n";
        state = BattleState::commandSelect;
        break;

    case BattleState::commandSelect:
    {
        cout << "\n" << player->GetName() << " HP: " << player->GetHP() << endl;
        cout << enemy->GetName() << " HP: " << enemy->GetHP() << endl;

        cout << "1. たたかう\n";
        cout << "2. にげる\n";
        cout << "コマンド: ";

        int command;
        cin >> command;

        if (command == 1)
        {
            int damage = player->Attack();
            cout << enemy->GetName() << " に " << damage << " のダメージ！\n";
            enemy->TakeDamage(damage);
        }
        else if (command == 2)
        {
            cout << "にげだした！\n";
            state = BattleState::end;
            break;
        }

        if (enemy->GetHP() > 0)
        {
            int damage = enemy->Attack();
            cout << enemy->GetName() << "のこうげき！\n";
            cout << damage << "のダメージ!\n";
            player->TakeDamage(damage);
        }
        if (player->GetHP() <= 0 || enemy->GetHP() <= 0)
        {
            state = BattleState::end;
        }

        break;
    }
    case BattleState::end:
        if (player->GetHP() <= 0)
        {
            cout << "あなたは死んでしまった\n";
        }
        else if (enemy->GetHP() <= 0)
        {
            cout << enemy->GetName() << "を　たおした!\n";

           
          
        }
        
        isFinished = true;
        break;
    }
   
  
}
bool BattleScene::IsFinished() const
{
    return isFinished;
}