#ifndef __BOT_H__
#define __BOT_H__

#include <random>

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<int> dis(1, 3);

class Bot{
private:
    bool attack;
public:
    Bot() {}
    int getRandomNum(){
        return (rand()%3)+1;
    }
    int getRandomIndex(){
        return rand()%2;
    }
    int* BotChooseOneOffer(int* bot_arr){
        bot_arr[0] = getRandomNum();
        bot_arr[1] = getRandomNum();

        return bot_arr;
    }
};

#endif