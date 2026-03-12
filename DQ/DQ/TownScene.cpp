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
        cout << "村人: ここはビシの村です。\n";
        break;

    case 2:
    {
        cout << "武器と防具の店へようこそ！\n"<<endl;
        cout << "1. 木のナイフ(70G)\n"<<endl;
        cout << "2. 石の斧(135G)\n" << endl;
        cout << "3. 銅のつるぎ(180G)\n" << endl;
        cout << "4. 木彫りの帽子(90G)\n" << endl;
        cout << "5. 布の服(80G)\n" << endl;
        cout << "6  石の盾(140G)\n" << endl;
        cout << "7. やめる\n";

        int shopInput;
        cin >> shopInput;

        


        if (shopInput == 1)
        {
            if (player->HaveGold() >= 70)
            {
                cout << "木のナイフを購入した\n";
                player->HaveGold()-70;
                player->AddAttack(5);
                cout << "木のナイフを装備した\n";
            }
            else
            {
                cout << "お金が足りない！\n";
            }
        }
        if (shopInput == 2)
        {
            if (player->HaveGold() >= 135)
            {
                cout << "石の斧を購入した\n";
                player->HaveGold() - 135;
                player->AddAttack(9);
                cout << "石の斧を装備した\n";
            }
            else
            {
                cout << "お金が足りない！\n";
            }
        }
        if (shopInput == 3)
        {
            if (player->HaveGold() >= 180)
            {
                cout << "銅のつるぎをを購入した\n";
                player->HaveGold() - 180;
                player->AddAttack(14);
                cout << "銅のつるぎを装備した\n";
            }
            else
            {
                cout << "お金が足りない！\n";
            } 
        }
        if (shopInput == 4)
        {
            if (player->HaveGold() >= 90)
            {
                cout << "木彫りの帽子を購入した\n";
                player->HaveGold() - 90;
                player->Adddefence(2);
                cout << "木彫りの帽子を装備した\n";
            }
            else
            {
                cout << "お金が足りない！\n";
            }
        }
        if (shopInput == 5)
        {
            if (player->HaveGold() >= 80)
            {
                cout << "布の服を購入した\n";
                player->HaveGold() - 80;
                player->Adddefence(3);
                cout << "布の服を装備した\n";
            }
            else
            {
                cout << "お金が足りない！\n";
            }
        }
        if (shopInput == 6)
        {
            if (player->HaveGold() >= 140)
            {
                cout << "石の盾を購入した\n";
                player->HaveGold() - 140;
                player->Adddefence(4);
                cout << "石の盾を装備した\n";
            }
            else
            {
                cout << "お金が足りない！\n";
            }
        }
        if (shopInput == 10000100)
        {
            cout <<"それを知っているとは...\n" << endl;
            cout <<"ならばこれを授けよう..!\n" << endl;
            cout << "切断虚幻OWD-000を手に入れた\n";
            player->AddAttack(30000);
            cout << "これはどうすることもできない...";
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
            if (player->HaveGold() >= 4)
            {
                player->HaveGold()-4;
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