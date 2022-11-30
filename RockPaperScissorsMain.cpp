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

    cout << "가위바위보 게임 시작 \n유저네임 입력: ";
    cin >> username;

    User user(username);
    Basic basic(user);
    ChooseOne choose(user);

    try{
        while(true){
            system("cls");
            cout << "\n어떤 가위바위보를 하시겠습니까? \n1: 일반, 2: 하나 빼기, 3: 묵찌빠 (0: 종료) \n";
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