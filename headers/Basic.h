#ifndef __BASIC_H__
#define __BASIC_H__

#include <string>
#include <iostream>
#include "User.h"
#include "Bot.h"
#include "Game.h"
using namespace std;

class Basic{
private: 
    Bot bot;
    Game game;
public:
    Basic(User user): bot(), game(user) {}
    bool start(User user){
        system("cls");
        game.title("¿œπ›");
        user.myOffer();

        const int userOffer = user.getMyOffer();
        const int botOffer = bot.getRandomNum();

        int result = game.WhoIsWin(userOffer, botOffer);
        return game.judgement(result);
    }
};

#endif