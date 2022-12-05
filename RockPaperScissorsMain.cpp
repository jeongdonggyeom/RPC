#include <iostream>
#include "./headers/User.h"
#include "./headers/Basic.h"
#include "./headers/exception.h"
#include "./headers/ChooseOne.h"
#include "./headers/SameThingAttackWin.h"

#define FILE_PATH "Ranking.txt"

using namespace std;

int* bot_arr = new int[2];
int* user_arr = new int[2];

int main()
{
    unsigned int input;

    User user;
    Basic basic(user);
    ChooseOne choose(user);
    SameThingAttackWin staw(user);

    cout << "���������� ���� ����\n";

    try{
        while(true){
            system("cls");
            cout << "� ������������ �Ͻðڽ��ϱ�? \n1: �Ϲ�, 2: �ϳ� ����, 3: ����� (0: ����) \n";
            cin >> input;
            if(input >= 4 || input <= 0) throw Exception(1);
            if(!input) {
                cout << "������������ �����մϴ�...\n";
                break;
            }
            while(true){
                bool flag;
                if(input == 1){
                    flag = basic.start(user);
                    break;
                }
                else if(input == 2){
                    flag = choose.start(user, user_arr, bot_arr);
                    break;
                }
                else if(input == 3){
                    flag = staw.start(user);
                    break;
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