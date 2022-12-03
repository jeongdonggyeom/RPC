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
    void title(){
        system("cls");
        game.title("¿œπ›");
    }
    bool start(User user){
        title();
        int result = rpc(user);
        return game.judgement(result);
    }
    bool rpc(User user){
        user.myOffer();

        const int userOffer = user.getMyOffer();
        const int botOffer = bot.getRandomNum();

        return game.WhoIsWin(userOffer, botOffer);
    }
};

#endif