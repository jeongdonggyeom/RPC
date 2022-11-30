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
    User user;
    Bot bot;
    Game game;
public:
    ChooseOne(User user): user(user), bot(), game() {}
    bool start(){
        game.title("�ϳ� ����", user, " (2���� ������ �������� �Է� ���ּ���.)");

        user.ChooseOneOffer();
        int* botOffer = bot.BotChooseOneOffer();
        int* userOffer = user.getMyChooseOffer();

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
        int input;
        cin >> input;

        int result = game.WhoIsWin(userOffer[input], botOffer[0]);
        return game.judgement(result, user);
    }
};

#endif