#ifndef __SAME_THING_ATTACK_WIN_H__
#define __SAME_THING_ATTACK_WIN_H__

#include "Game.h"
#include "Bot.h"
#include "User.h"
#include "Basic.h"
#include <iostream>
#include <Windows.h>
using namespace std;

class SameThingAttackWin{
private:
    Bot bot;
    Game game;
    Basic basic;
public:
    SameThingAttackWin(User user): game(user), basic(user) {}
    bool start(User user){
        system("cls");
        game.title("¹¬Âîºü");
        getFirstNum(user);
        return false;
    }

    void getFirstNum(User user){
        while(true){
            if(basic.rpc(user) != 2){
                cout << "°°Áö¾ÊÀ½\n";
                Sleep(500);
            }
            else{
                cout << "°°À½\n";
                Sleep(500);
            }
        }
    }
};

#endif