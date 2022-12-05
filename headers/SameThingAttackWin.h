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
    SameThingAttackWin(User user): basic(user) {}
    void title(){
        system("cls");
        game.title("�����");
    }

    int start(User user){
        title();
        int firstNum = getFirstNum(user);
        attacker(firstNum, user);
        int rs = afterFirstOffer(user);
        return result(rs);
    }

    int result(int rs){
        if(rs){
            cout << "����� �̰���ϴ�!\n";
            Sleep(1000);
            return 1;
        }
        else if(!rs){
            cout << "����� �����ϴ�... \n";
            Sleep(1000);
            return 0;
        }
    }

    int getFirstNum(User user){
        while(true){
            int num = basic.rpc(user);
            if(num != 2) return num;
            else if(num == 2) cout << "������ ���� �� ���� �Ȱ����ϴ�. �ٽ� ���ּ���.\n";
        }
    }
    
    void attacker(int att, User user){
        if(att == 1){
            user.setAttack(1);
            bot.setAttack(0);
        }
        else if(att == 0){
            user.setAttack(0);
            bot.setAttack(1);
        }
    }

    int afterFirstOffer(User user){
        while(1){
            cout << "������ ���ðڽ��ϱ�? 1: ����, 2: ����, 3: ��\n";
            int afof = basic.rpc(user);
            if(afof == 2) break;
            else attacker(afof, user);
        }
        if(bot.getAttack() == 1) return 0;
        return 1;
    }
};

#endif