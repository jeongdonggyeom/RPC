#ifndef __RANK_H__
#define __RANK_H__

#include <string>
#include <iostream>
#include <limits>
#include <fstream>
#include "exception.h"
using namespace std;
#define NUM_MVP 5

class PlayInfo{
private:
	string name;
	int nItem;
    friend class Rank;
public:
	PlayInfo(string name="XXX", int nItem=0): name(name), nItem(nItem) {}
    friend ostream& operator<<(ostream& os, const PlayInfo obj){
        os << obj.name << "\t" << obj.nItem << "\n";
        return os;
    }
    friend istream& operator>>(istream& is, PlayInfo obj){
        is >> obj.name >> obj.nItem;
        return is;
    }
};


class Rank{
private:
	PlayInfo MVP[NUM_MVP];
	int nMVP = NUM_MVP;
public:
	void print(string title="게임 랭킹") {
		system("cls");
		cout << title << "\n";
		for(int i=0;i<NUM_MVP;i++){
            cout << "[" << i+1 << "위] " << MVP[i].name << "\t" << MVP[i].nItem << "\n";
        }
		cout << "엔터를 입력하세요.";
		getchar();
		cout << "\n";

	}
	int add(int nItem) {
        if(nItem < MVP[nMVP-1].nItem) return 0;
        int rank = nMVP - 1;
        for( ; rank > 0 ; rank--){
            if(nItem < MVP[rank-1].nItem) break;
            MVP[rank] = MVP[rank-1];
        }
		MVP[rank].nItem = nItem;
		cout << "[" << rank+1 << "위] 이름을 입력하세요: ";
		cin >> MVP[rank].name;
		cout << endl;
		return rank+1;
	}
    void save(string filename){
        ofstream ofs;
        ofs.open(filename);
        if(!ofs.is_open()){
            throw Exception(2);
        }
        for(int i=0;i<NUM_MVP;i++){
            ofs << MVP[i];
        }
        ofs.close();
    }
    void load(string filename){
        ifstream ifs;
        ifs.open(filename);
        if(!ifs.is_open()){
            throw Exception(2);
        }
        for(int i=0;i<NUM_MVP;i++){
            ifs >> MVP[i];
        }
        ifs.close();
    }
};

#endif