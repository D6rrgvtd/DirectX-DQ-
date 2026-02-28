#include "TownScene.h"
#include "SaveManager.h"
#include <iostream>

using namespace std;

TownScene::TownScene(Character* p)
{
    player = p;
}
void TownScene::Init()
{
    isFinished = false;
}

void TownScene::Update()
{
    cout << "\n--- 町 ---\n";
    cout << "1. 人に話しかける\n";
    cout << "2. 武器屋\n";
    cout << "3. 宿屋\n";
    cout << "4. 外へ出る\n";

    int input;
    cin >> input;

    switch (input)
    {
    case 1:
        cout << "村人: ここはビシャの村です。\n";
        break;

    case 2:
    {
        cout << "武器屋へようこそ！\n";
        cout << "1. つるぎ(100G)\n";
        cout << "2. やめる\n";

        int shopInput;
        cin >> shopInput;

        if (shopInput == 1)
        {
            if (player->GetGold() >= 100)
            {
                player->AddGold(-100);
                player->AddAttack(5);
                cout << "こうげき力があがった！\n";
            }
            else
            {
                cout << "お金が足りない！\n";
            }
        }
        break;
    }

    case 3:
    {
        cout << "1泊20Gです。泊まりますか？ (1:はい 2:いいえ)\n";

        int innInput;
        cin >> innInput;

        if (innInput == 1)
        {
            if (player->GetGold() >= 20)
            {
                player->AddGold(-20);
                player->FullHeal();
                SaveManager::Save(player);
                cout << "セーブしました。\n";
                cout << "HPが全回復した！\n";
            }
            else
            {
                cout << "お金が足りない！\n";
            }
        }
        break;
    }

    case 4:
        isFinished = true;
        break;
    }
}

void TownScene::Draw()
{
}

bool TownScene::IsFinished() const
{
    return isFinished;
}