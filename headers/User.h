#ifndef __USER_H__
#define __USER_H__

#include <string>
#include "exception.h"
using namespace std;

class User{
private:
    string username;
    unsigned int stack, offer, offer2;
    bool attack;
public:
    User(string username): username(username), stack(0), offer(0), offer2(0) {}
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
    unsigned int getStack(){
        return stack;
    }
    void addStack(){
        stack++;
    }
};

#endif