#include <iostream>
#include "./headers/User.h"
#include "./headers/Basic.h"
#include "./headers/exception.h"
#include <time.h>
#include "./headers/Rank.h"
#include "./headers/ChooseOne.h"
#include "./headers/SameThingAttackWin.h"

#define FILE_PATH "Ranking.txt"

using namespace std;

int* bot_arr = new int[2];
int* user_arr = new int[2];

int main()
{
    srand((unsigned) time(NULL));
    unsigned int input;
    string username;

    User user(username);
    Basic basic(user);
    ChooseOne choose(user);
    SameThingAttackWin staw(user);

    cout << "���������� ���� ���� \n�������� �Է�: ";
    cin >> username;

    try{
        while(true){
            system("cls");
            cout << "\n� ������������ �Ͻðڽ��ϱ�? \n1: �Ϲ�, 2: �ϳ� ����, 3: ����� (0: ����) \n";
            cin >> input;
            if(!input) break;
            while(true){
                bool flag;
                if(input == 1){
                    flag = basic.start(user);
                    if(!flag) break;
                }
                else if(input == 2){
                    flag = choose.start(user, user_arr, bot_arr);
                    if(!flag) break;
                }
                else if(input == 3){
                    flag = staw.start(user);
                    if(!flag) break;
                }
            }
        }
    }catch(Exception e){
        e.errorLog();
    }

    delete[] user_arr;
    delete[] bot_arr;
    return 0;
}