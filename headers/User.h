#ifndef __USER_H__
#define __USER_H__

#include "exception.h"
using namespace std;

class User{
private:
    unsigned offer, offer2;
    int attack;
public:
    void myOffer(){
        cin >> offer;
        if(offer >= 4 || offer <= 0) throw Exception(1);
    }
    void ChooseOneOffer(){
        cin >> offer >> offer2;
        if(offer >= 4 || offer <= 0 || offer2 >= 4 || offer2 <= 0) throw Exception(1);
    }
    int* getMyChooseOffer(int* user_arr){
        user_arr[0] = offer;
        user_arr[1] = offer2;

        return user_arr;
    }
    unsigned int getMyOffer(){
        return offer;
    }
    void setAttack(bool flag){
        attack = flag;
    }
    bool getAttack(){
        return attack;
    }
    void print(){
        cout << "³ª: " << offer << " " << offer2 << "\n";
    }
};

#endif