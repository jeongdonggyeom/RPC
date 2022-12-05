#ifndef __GAME_H__
#define __GAME_H__

#include <iostream>
#include "User.h"
#include <Windows.h>
using namespace std;

class Game{
private:
public:
    void title(string title, string end=""){
        cout << title << " ���������� ����\n";
        cout << "������ ���ðڽ��ϱ�? 1: ����, 2: ����, 3: ��" << end << "\n";
    }
    
    int WhoIsWin(const int userOffer, const int botOffer){
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

    int judgement(int result){
        if(result == 0){
            cout << "����� �����ϴ�... \n";
            Sleep(1000);
            return 0;
        }
        else if(result == 1){
            cout << "����� �̰���ϴ�!\n";
            Sleep(1000);
            return 1;
        }
        else if(result == 2){
            cout << "���º� �Դϴ�.\n";
            Sleep(1000);
            return 0;
        }
    }
};

#endif