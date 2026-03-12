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
    isDefending = false;
	player = new Character("プレイヤー", 30, 5,7,0,0,5);
    enemies.push_back(new Character("スライム1", 8,3,3,2,1,2));
    enemies.push_back(new Character("スライム2", 8,3,3,2,1,2));
    
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
        cout << "\n" << player->GetName() << " HP: " << player->GetHP() <<" MP: "<<
            player->GetMP()<<endl;

        for (auto e : enemies)
        {
            if (e->GetHP() > 0)
            {
                cout << e->GetName()
                    << " HP: " << e->GetHP() << endl;
           }
        }

        cout << "1. たたかう\n";
        cout << "2. じゅもん\n";
        cout << "3. ぼうぎょ\n";
        cout << "4. にげる\n";
        cout << "コマンド: ";

        int command;
        cin >> command;

        if (command == 1)
        {
            for (int i = 0; i < enemies.size(); i++)
            {
                if (enemies[i]->GetHP() > 0)
                {
                    cout << i + 1 << ":" << enemies[i]->GetName() << endl;
                }
            }

            cout << "どの敵を攻撃?:";
            int target;
            cin >> target;
            target--;

            if (target >= 0 && target < enemies.size())
            {
                Character* e = enemies[target];
                if (e->GetHP() > 0)
                {
                    int damage = player->Attack() + rand() % 3;
                    if (rand() % 100 < 7)
                    {
                        damage *= 2;
                        cout << "かいしんのいちげき\n";
                    }
                    damage -= e->Getdefence() / 4;
                    if (damage <= 0)
                    {
                        damage = 1;
                    }
                    cout << e->GetName()
                        << "に" << damage
                        << "のダメージ!\n";

                    e->TakeDamage(damage);
                    if (e->GetHP() <= 0)
                    {
                        cout << e->GetName() << "をたおした！\n";
                    }
                }
            }
        }
        else if (command == 2)
        {
            cout << "1. 　ボル\n";
            cout << "2. 　ヒール\n";
            cout << "3.   ザル\n";

            int spellnput;
            cin >> spellnput;

            if (spellnput == 1)
            {
                if (player->GetMP() >= 2)
                {
                    player->UseMP(2);

                    int damage = 10 + rand() % 3;
                    for (auto e : enemies)
                    {
                        if (e->GetHP() > 0)
                        {
                            e->TakeDamage(damage);
                            cout << "ボル!" << endl;
                            cout<<e->GetName()<<"に" << damage << "ダメージ!\n";
                            if (e->GetHP() <= 0)
                            {
                                cout << e->GetName() << "をたおした！\n";
                            }
                            break;
                        }
                    }
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
                    int rhp = 10 + rand() % 3;
                    player->RecoverHP(rhp);

                    cout << "ヒール!" << rhp<< " HP回復！\n";
                }
                else
                {
                    cout << "MPが足りない！\n";
                }
            }
            else if (spellnput == 3)
            {
                if (player->GetMP() >= 4)
                {
                    player->UseMP(4);

                    cout << "ザル!\n";
                    for (auto e : enemies)
                    {
                        if (e->GetHP() > 0)
                        {
                            int damage = 6 + rand() % 2;

                            damage -= e->Getdefence() / 3;

                            if (damage <= 0)
                            {
                                damage = 0;
                            }
                            cout << e->GetName() << "に" << damage << "のダメージ\n";
                            e->TakeDamage(damage);

                            if (e->GetHP() <= 0)
                            {
                                cout << e->GetName() << "をたおした！\n";
                            }
                        }
                    }
                }
                else
                {
                    cout << "MPが足りない!\n";
                }
            }
        }
        else if (command == 3)
        {
            cout << player->GetName() << "はぼうぎょしている\n";
            isDefending = true;
        }
        else if (command == 4)
        {
            cout << "にげだした！\n";
            if (rand() % 100 < 30)
            {
                cout << "しかし、まわりこまれてしまった！\n";
            }
            else
            {
                state = BattleState::end;
                break;
            }
        }
        for (auto e : enemies)
        {
            if (e->GetHP() > 0)
            {
                int damage = e->Attack() + rand() % 3;
                if (rand() % 100 < 7)
                {
                    damage *= 2;
                    cout << "きゅうしょのいちげき\n";
                }
                if (isDefending)
                {
                    damage /= 2;
                }
                damage -= player->Getdefence() / 4;
                if (damage <= 0)
                {
                    damage = 1;
                }
                cout << e->GetName() << "のこうげき！\n";
                cout << damage << "のダメージ!\n";
                player->TakeDamage(damage);
               
            }
        }
        isDefending = false;
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
                if (e->GetHP() <= 0)
                {
                    cout << e->GetName() << "を倒した！\n";
                    player->AddExp(e->GetExp());
                    cout << e->GetExp() << "のけいけんちを獲得!\n";
                    player->AddGold(e->GetGold());
                    cout << e->GetGold() << "ゴールドを獲得!\n";
                }
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