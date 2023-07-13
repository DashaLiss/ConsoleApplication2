#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <ctime> 
#include <Windows.h>
using namespace std;


class Pet {
	int hungry;
	int sleep;
	int play;
	int toilettes;
	bool ifsleep;
	string name;
	
	void printSprate(int start, int end, string str);
public:
	Pet(int hungryP, int sleepP, int playP, int toilettesP) : hungry{ hungryP }, sleep{ sleepP }, play{ playP }, toilettes{ toilettesP } {}
	Pet() : Pet(70, 70, 70, 70) { ifsleep = false; }
	void print();
	void SavePet();
	void ReadSave();

	void setName();
	void sethungry(int a);
	void setIFsleep(bool a);
	void setplay(int a);
	void settoilettes(int a);
	void setsleep(int a);
	Pet operator-(int a);

	bool getSleep() { return ifsleep; }
	int gethungry() { return hungry; }
	int getsleep() { return sleep; }
	int getplay() { return play; }
	int gettoilettes() { return toilettes; }
	string getname() { return name; }

	void printNormPet();
	void printHungryPet();
	void printSatisfiedPet();
	void printDirtyPet();
	void printSleepPet();
	void printHappyPet();
	void printDeadPet();
};

class Inventory {
	int eat;
	int money;
public:
	Inventory(int eatP, int moneyP) : eat{ eatP }, money{ moneyP } {}
	Inventory() : Inventory(3, 10) {}

	void ReadInventory();
	void SaveInventory();

	void seteat(int a);
	void setmoney(int a);

	int geteat() { return eat; }
	int getmoney() { return money; }
};


//void saveNull();
//void saveSleepOff();

//Pet ReadSave();
//string ReadName();
//Inventory ReadInventory();
//bool ReadSaveSleep();
//void printPet();
time_t ReadSaveTime();

//void printNormPet(Pet a, string name);
//void printHungryPet(Pet a, string name);
//void printSatisfiedPet(Pet a, string name);
//void printDirtyPet(Pet a, string name);
//void printSleepPet(Pet a, string name);
//void printHappyPet(Pet a, string name);
//void printDeadPet(Pet a, string name);

int action();
