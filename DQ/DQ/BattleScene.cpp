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
	player = new Character("プレイヤー", 30, 5,7,0,0);
    enemies.push_back(new Character("スライム1", 8,3,3,2,1));
    enemies.push_back(new Character("スライム2", 8,3,3,2,1));
    
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
        cout << "2. じゅもん\n";
        cout << "3. にげる\n";
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
            cout << "1. 　ボル\n";
            cout << "2. 　ヒール\n";

            int spellnput;
            cin >> spellnput;

            if (spellnput == 1)
            {
                if (player->GetMP() >= 3)
                {
                    player->UseMP(3);

                    int damage = 10;
                    enemies[0]->TakeDamage(damage);
                    cout << "ボル!" << damage << "ダメージ\n";
                }
                else
                {
                    cout << "MPが足りない!\n";
                }
            }
            else if (spellnput == 2)
            {
                if (player->GetMP() >= 2)
                {
                    player->UseMP(2);
                    player->RecoverHP(10);

                    cout << "ヒール!" << endl << " HP回復！\n";
                }
                else
                {
                    cout << "MPが足りない！\n";
                }
            }
        }
        else if (command == 3)
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
            for (auto e : enemies)
            {
                cout << e->GetName() << "を倒した！\n";
                player->AddExp(e->GetExp());
                player->AddGold(e->GetGold());
            }

        }
        isFinished = true;
        break;
    }
   
  
}
bool BattleScene::IsFinished() const
{
    return isFinished;
}