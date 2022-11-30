#ifndef __USER_H__
#define __USER_H__

#include <string>
#include "exception.h"
using namespace std;

class User{
private:
    string username;
    int stack = 0, offer=0, offer2=0;
    bool attack;
    int* arr = new int[2];
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
    int* getMyChooseOffer(){
        arr[0] = offer;
        arr[1] = offer2;

        return arr;
    }
    int getMyOffer(){
        return offer;
    }
    int getStack(){
        return stack;
    }
    void addStack(){
        stack++;
    }
    ~User(){
        delete[] arr;
    }
};

#endif