#include "Header.h"

//Pet null = { 70,70,70,70 };
//Pet os;
//Inventory inventory;

time_t tiime;

//bool sleep;
//bool sleepOff = false;

string savePet = "save.txt";
string saveInventory = "Inventory.txt";
string sprate = "sprate.txt";
string saveSleep = "sleep.txt";
string Savetime = "time.txt";
string saveName = "name.txt";
//string name;

void Pet::printSprate(int start, int end, string str)
{
	ifstream fin;
	fin.open(sprate);

	if (!fin.is_open()) cout << "������ �������� �����" << endl;
	else {
		cout << "-----------------------------------\n\n";
		ifstream in("sprate.txt");
		string s;
		for (int c = 1; getline(in, s) && c <= end; ++c) {
			if (c >= start)
				cout << s << std::endl;
		}
		cout << endl;
		cout << name << str;
		cout << "\n\n-----------------------------------\n";
		print();
		cout << "\n-----------------------------------\n";
	}
	fin.close();
}

void Pet::print() {
	cout << "������� - " << hungry << "; �������� -" << sleep << "; �����  - " << play << "; ������� - " << toilettes;
}

void Pet::SavePet() {
	ofstream fout;
	fout.write((char*)&hungry, sizeof(int));
	fout.write((char*)&sleep, sizeof(int));
	fout.write((char*)&play, sizeof(int));
	fout.write((char*)&toilettes, sizeof(int));
	fout.write((char*)&ifsleep, sizeof(bool));
	fout.write((char*)&name, sizeof(string));
	fout.close();
}

void Pet::ReadSave() {
	ifstream fin;
	fin.open(savePet);
	if (!fin.is_open()) cout << "������ �������� �����" << endl;
	else {
		fin.read((char*)&hungry, sizeof(int));
		fin.read((char*)&sleep, sizeof(int));
		fin.read((char*)&play, sizeof(int));
		fin.read((char*)&toilettes, sizeof(int));
		fin.read((char*)&ifsleep, sizeof(bool));
		fin.read((char*)&name, sizeof(string));
	}
	fin.close();
}

void Pet::setName()
{
	cout << "��� �� ������� ������� ? - ";
	cin >> name;
}

void Pet::sethungry(int a)
{
	hungry = a;
}

void Pet::setIFsleep(bool a)
{
	ifsleep = a;
}

void Pet::setplay(int a)
{
	play = a;
}

void Pet::settoilettes(int a)
{
	toilettes = a;
}

void Pet::setsleep(int a)
{
	sleep = a;
}

Pet Pet::operator-(int a)
{
	Pet b;
	b.hungry = hungry - a;
	b.sleep = sleep - a;
	b.play = play - a;
	b.toilettes = toilettes - a;
	return b;
}


void Pet::printNormPet()
{
	printSprate(1, 7, " ��������� ���� �����...");
}

void Pet::printHungryPet()
{
	printSprate(8, 18, " ����� �������� , �� � ��� ������� � ���� ������ ��� !\n��������� �� ��� ������� ��������� ������� �� ���");
}

void Pet::printSatisfiedPet()
{
	printSprate(19, 24, " ������� � ����������� � ����-�����, ��������� �� ����� ������� ");
}

void Pet::printDirtyPet()
{
	ifstream fin;
	fin.open(sprate);

	if (!fin.is_open()) cout << "������ �������� �����" << endl;
	else {
		cout << "-----------------------------------\n\n";
		ifstream in("sprate.txt");
		string s;
		for (int c = 1; getline(in, s) && c <= 36; ++c) {
			if (c >= 25)
				cout << s << std::endl;
		}
		if (toilettes < 50) {
			cout << endl;
			cout << " ��.... " << name << " �� ����� ���� � ����� ������� ������� ";
		}
		if (sleep < 50) {
			cout << endl;
			cout << name << " ���� �� ������, �� ����� ����� ����� ";
		}
		if (sleep < 50) {
			cout << endl;
			cout << name << " ����� ����������, �� ����� �������� ! ";
		}
		cout << "\n\n-----------------------------------\n";
		print();
		cout << "\n-----------------------------------\n";
	}
	fin.close();
}

void Pet::printSleepPet()
{
	printSprate(37, 40, " ����� �������� ��� ");
}

void Pet::printHappyPet()
{
	printSprate(41, 52, " ����� ���������� ");
}

void Pet::printDeadPet()
{
	printSprate(53, 67, " ��� �� � ���� ����.�� ��� ����� ��� �� �������.... ");
}

void Inventory::ReadInventory() {
	ifstream fin;
	fin.open(saveInventory);
	if (!fin.is_open()) cout << "������ �������� �����" << endl;
	else {
		while (fin.read((char*)this, sizeof(Inventory))) {}
	}
	fin.close();
}

void Inventory::SaveInventory()
{
	ofstream fout;
	fout.open("Inventory.txt", ofstream::trunc);
	if (!fout.is_open()) cout << "������ �������� �����" << endl;
	else {
		fout.write((char*)this, sizeof(Inventory));
	}
	fout.close();
}

void Inventory::seteat(int a)
{
	eat = a;
}

void Inventory::setmoney(int a)
{
	money = a;
}


time_t ReadSaveTime()
{
	ifstream fin;
	fin.open(Savetime);
	if (!fin.is_open()) cout << "������ �������� �����" << endl;
	else {
		fin.read((char*)&tiime, sizeof(time_t));
	}
	fin.close();
	return tiime;
}

int action()
{
	cout << "\n* ���� �� ������ ��������� ������� ,������� - 1\n* ���� �� ������ ������� ����� �������, ������� - 2\n* ���� �� ������ �������� � ��������, ������� - 3\n* ���� �� ������ �������� ������ ,������� - 4\n* ���� �� ������ ������� ���������, ������� - 5\n* ���� �� ������ ������� �������, ������� - 6\n* ���� �� ������ �����, �������(��������� ���� ������ �� ����������� ��� ���� �������� ���������) - 7\n";
	int enter;
	cout << "\n ��� ����� - ";
	cin >> enter;
	return enter;
}


