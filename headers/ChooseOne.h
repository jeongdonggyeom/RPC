#ifndef __CHOOSE_ONE_H__
#define __CHOOSE_ONE_H__

#include <string>
#include <iostream>
#include "User.h"
#include "Bot.h"
#include "Game.h"

using namespace std;

class ChooseOne{
private:
    Bot bot;
    Game game;
public:
    ChooseOne(User user): bot(), game(user) {}
    bool start(User user, int* user_arr, int* bot_arr){
        system("cls");
        game.title("�ϳ� ����", " (2���� ������ �������� �Է� ���ּ���.)");

        user.ChooseOneOffer();
        int* botOffer = bot.BotChooseOneOffer(bot_arr);
        int* userOffer = user.getMyChooseOffer(user_arr);

        cout << "��: ";
        for(int i=0;i<2;i++){
            cout << botOffer[i] << " ";
        }
        cout << "\n";
        cout << "��: ";
        for(int i=0;i<2;i++){
            cout << userOffer[i] << " ";
        }
        cout << "\n";
        cout << "�� �� �ϳ��� �������ּ���. (0 �Ǵ� 1) \n";
        unsigned int input;
        cin >> input;

        int result = game.WhoIsWin(userOffer[input], botOffer[bot.getRandomIndex()]);
        cout << result << "\n";
        return game.judgement(result);
    }
};

#endif