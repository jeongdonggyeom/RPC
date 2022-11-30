#include <iostream>
#include "./headers/User.h"
#include "./headers/Basic.h"
#include "./headers/exception.h"
#include <time.h>
#include "./headers/Rank.h"
#include "./headers/ChooseOne.h"

#define FILE_PATH "Ranking.txt"

using namespace std;

int main()
{
    srand((unsigned) time(NULL));
    int input;
    string username;

    cout << "���������� ���� ���� \n�������� �Է�: ";
    cin >> username;

    User user(username);
    Basic basic(user);
    ChooseOne choose(user);

    try{
        while(true){
            system("cls");
            cout << "\n� ������������ �Ͻðڽ��ϱ�? \n1: �Ϲ�, 2: �ϳ� ����, 3: ����� (0: ����) \n";
            cin >> input;
            if(!input) break;
            while(true){
                bool flag;
                if(input == 1){
                    flag = basic.start();
                    if(!flag) break;
                }
                else if(input == 2){
                    flag = choose.start();
                    if(!flag) break;
                }
            }
        }
    }catch(Exception e){
        e.errorLog();
    }
    return 0;
}