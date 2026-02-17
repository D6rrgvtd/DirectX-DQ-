#include "BattleScene.h"

using namespace std;

BattleScene::BattleScene()
{
    player = nullptr;
    isFinished = false;
}
BattleScene::~BattleScene()
{
    delete player;
    for (auto e : enemies)
    {
        delete e;
    }

}


void BattleScene::Init()
{
    for (auto e : enemies)
        delete e;
    enemies.clear();
	state = BattleState::start;
    isFinished = false;
	player = new Character("プレイヤー", 30, 5,7);
    enemies.push_back(new Character("スライムA", 8, 3, 2));
    enemies.push_back(new Character("スライムB", 8, 3, 3));
    
    srand((unsigned int)time(nullptr));


}

void BattleScene::Update()
{
    switch (state)
    {
    case BattleState::start:
        cout << "モンスターがあらわれた！\n";
        for (auto e : enemies)
        {
            cout << e->GetName() << "\n";
        }
        state = BattleState::commandSelect;
        break;

    case BattleState::commandSelect:
    {
        cout << "\n" << player->GetName() << " HP: " << player->GetHP() << endl;

        for (auto e : enemies)
        {
            cout << e->GetName()
                << " HP: " << e->GetHP() << endl;
        }

        cout << "1. たたかう\n";
        cout << "2. にげる\n";
        cout << "コマンド: ";

        int command;
        cin >> command;

        if (command == 1)
        {
            for (auto e : enemies)
            {
                if (e->GetHP() > 0)
                {
                    int damage = player->Attack() + rand() % 3;
                    cout << e->GetName()
                        << "に" << damage
                        << "のダメージ!\n";

                    e->TakeDamage(damage);
                    break;
                }
            }
        }
        else if (command == 2)
        {
            cout << "にげだした！\n";
            state = BattleState::end;
            break;
        }
        for (auto e : enemies)
        {
            if (e->GetHP() > 0)
            {
                int damage = e->Attack() + rand() % 3;
                cout << e->GetName() << "のこうげき！\n";
                cout << damage << "のダメージ!\n";
                player->TakeDamage(damage);
            }
        }
        bool allDead = true;
        for (auto e : enemies)
        {
            if (e->GetHP() > 0)
            {
                allDead = false;
            }
        }
        if (player->GetHP() <= 0 || allDead)
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
        else
        {
            cout << "敵はぜんめつした\n";
        }
        isFinished = true;
        break;
    }
   
  
}
bool BattleScene::IsFinished() const
{
    return isFinished;
}