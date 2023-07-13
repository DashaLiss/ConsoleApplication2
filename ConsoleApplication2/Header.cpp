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

	if (!fin.is_open()) cout << "Ошибка открытия файла" << endl;
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
	cout << "сытость - " << hungry << "; бодрость -" << sleep << "; досуг  - " << play << "; гигиена - " << toilettes;
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
	if (!fin.is_open()) cout << "Ошибка открытия файла" << endl;
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
	cout << "Как вы назовёте питомца ? - ";
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
	printSprate(1, 7, " чувствует себя никак...");
}

void Pet::printHungryPet()
{
	printSprate(8, 18, " очень голодный , но в его коробке с едой ничего нет !\nОсторожно он уже смотрит голодными глазами на вас");
}

void Pet::printSatisfiedPet()
{
	printSprate(19, 24, " объелся и привратился в кото-шарик, осторожно он может улететь ");
}

void Pet::printDirtyPet()
{
	ifstream fin;
	fin.open(sprate);

	if (!fin.is_open()) cout << "Ошибка открытия файла" << endl;
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
			cout << " Фу.... " << name << " не хочет жить в такой грязной комнате ";
		}
		if (sleep < 50) {
			cout << endl;
			cout << name << " весь на нервах, он очень хочет спать ";
		}
		if (sleep < 50) {
			cout << endl;
			cout << name << " очень напряжённый, он хочет поиграть ! ";
		}
		cout << "\n\n-----------------------------------\n";
		print();
		cout << "\n-----------------------------------\n";
	}
	fin.close();
}

void Pet::printSleepPet()
{
	printSprate(37, 40, " видит радужные сны ");
}

void Pet::printHappyPet()
{
	printSprate(41, 52, " очень счастливый ");
}

void Pet::printDeadPet()
{
	printSprate(53, 67, " уже не в этом мире.Ты так давно его не навещал.... ");
}

void Inventory::ReadInventory() {
	ifstream fin;
	fin.open(saveInventory);
	if (!fin.is_open()) cout << "Ошибка открытия файла" << endl;
	else {
		while (fin.read((char*)this, sizeof(Inventory))) {}
	}
	fin.close();
}

void Inventory::SaveInventory()
{
	ofstream fout;
	fout.open("Inventory.txt", ofstream::trunc);
	if (!fout.is_open()) cout << "Ошибка открытия файла" << endl;
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
	if (!fin.is_open()) cout << "Ошибка открытия файла" << endl;
	else {
		fin.read((char*)&tiime, sizeof(time_t));
	}
	fin.close();
	return tiime;
}

int action()
{
	cout << "\n* Если вы хотите накормить питомца ,введите - 1\n* Если вы хотите уложить спать питомца, введите - 2\n* Если вы хотите поиграть с питомцем, введите - 3\n* Если вы хотите наверсти уборку ,введите - 4\n* Если вы хотите открыть инвентарь, введите - 5\n* Если вы хотите открыть магазин, введите - 6\n* Если вы хотите выйти, введите(осторожно выши данные не сохраняться при ином закрытие программы) - 7\n";
	int enter;
	cout << "\n Ваш выбор - ";
	cin >> enter;
	return enter;
}


