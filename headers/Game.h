#ifndef __GAME_H__
#define __GAME_H__

#include <iostream>
#include "User.h"
#include <Windows.h>
using namespace std;

class Game{
private:
public:
    void title(string title, User user, string end=""){
        cout << title << " 가위바위보 시작 (현재 연승 횟수: " << user.getStack() << ")\n";
        cout << "무엇을 내시겠습니까? 1: 가위, 2: 바위, 3: 보" << end << "\n";
    }
    int WhoIsWin(int userOffer, int botOffer){
        cout << "BOT: " << botOffer << "\n";
        if(userOffer == 1){
            if(botOffer == 1) return 2;
            else if(botOffer == 2) return 0;
            else if(botOffer == 3) return 1;
        }
        else if(userOffer == 2){
            if(botOffer == 1) return 1;
            else if(botOffer == 2) return 2;
            else if(botOffer == 3) return 0;
        }
        else if(userOffer == 3){
            if(botOffer == 1) return 0;
            else if(botOffer == 2) return 1;
            else if(botOffer == 3) return 2;
        }
    }

    bool judgement(int result, User user){
        if(result == 0){
            cout << "당신이 졌습니다... \n";
            Sleep(1000);
            return false;
        }
        else if(result == 1){
            cout << "당신이 이겼습니다!\n";
            user.addStack();
            Sleep(1000);
            return true;
        }
        else if(result == 2){
            cout << "무승부 입니다.\n";
            Sleep(1000);
            return false;
        }
    }
};

#endif