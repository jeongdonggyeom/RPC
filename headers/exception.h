#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

#include <string>
#include <iostream>
using namespace std;

class Exception
{
private:
    int code;
public:
    Exception(int code): code(code) {}
    void errorLog(){
        if(code == 1){
            cout << "���ǿ� ���� �ʴ� �Է�\n";
        }
    }
};



#endif