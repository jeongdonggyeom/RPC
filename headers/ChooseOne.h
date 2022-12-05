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
    ChooseOne(User user): bot() {}
    void title(){
        system("cls");
        game.title("�ϳ� ����", " (2���� ������ �������� �Է� ���ּ���.)");
    }
    bool start(User user, int* user_arr, int* bot_arr){
        title();
        
        user.ChooseOneOffer();
        int* botOffer = bot.BotChooseOneOffer(bot_arr);
        int* userOffer = user.getMyChooseOffer(user_arr);

        bot.print();
        user.print();

        cout << "�� �� �ϳ��� �������ּ���. (0 �Ǵ� 1) \n";
        unsigned int input;
        cin >> input;

        int result = game.WhoIsWin(userOffer[input], botOffer[bot.getRandomIndex()]);
        return game.judgement(result, user);
    }
};

#endif