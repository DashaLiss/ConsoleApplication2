#include "Header.h"


int main()
{
	bool end = false;


	Pet pet;
	Inventory inventory;

	int choose;
	int igra1;
	int igra2;
	int igra3;

	time_t TimeEnd = time(NULL);
	time_t TimeStart;


	string close;

	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	cout << "Если Вы хотите создать нового питомца - введите '1'\nЕсли Вы хотите продолжить - введите '2'\n";
	cin >> choose;
	if (choose == 1) {
		pet = Pet();
		TimeStart = time(NULL);
		pet.setName();
		ofstream fout;
	}
	else if (choose == 2) {
		inventory.ReadInventory();
		TimeStart = ReadSaveTime();
		pet.ReadSave();
		if (!pet.getSleep())
			pet = pet - (TimeEnd - TimeStart) / 20;
	}


	while (!end) {
		if (choose != 3)
			system("cls");
		if (!pet.getSleep()) {
			if (pet.gethungry() <= 1 || pet.gettoilettes() <= 1 || pet.getplay() <= 1 || pet.getsleep() <= 1) {
				pet.printDeadPet();
				break;
			}
			else if ((pet.gethungry() >= 50 && pet.gethungry() <= 80) && (pet.gettoilettes() >= 50 && pet.gettoilettes() <= 80)
				&& (pet.getsleep() >= 50 && pet.getsleep() <= 80) && (pet.getplay() >= 50 && pet.getplay() <= 80)) {
				pet.printNormPet();
			}
			// низкие параметры 
			else if (pet.gettoilettes() < 50 || pet.getsleep() < 50 || pet.getplay() < 50) {
				pet.printDirtyPet();
			}
			else if (pet.gethungry() < 50) {
				pet.printHungryPet();
			}
			// высокие параметры 
			else if (pet.gethungry() > 80) {
				pet.printSatisfiedPet();

			}
			else if (pet.getsleep() > 80 || pet.gettoilettes() > 80 || pet.getplay() > 80) {
				pet.printHappyPet();
			}


			choose = action();

			// разница времени 

			TimeEnd = time(NULL);

			if (TimeEnd - TimeStart > 20) {
				pet = pet - (TimeEnd - TimeStart) / 20;
				TimeStart = time(NULL);
			}
			// выборы 
			if (choose == 1) {
				if (inventory.geteat() > 0) {
					inventory.seteat(inventory.geteat() - 1);
					pet.sethungry(pet.gethungry() + 5);
					if (pet.gethungry() > 100) pet.sethungry(100);
				}
				else {
					cout << "У вас нет еды";
					Sleep(3500);
				}
			}

			if (choose == 2) {
				pet.setIFsleep(true);
				TimeStart = time(NULL);

			}
			if (choose == 3) {
				system("cls");
				srand(time(NULL));
				igra1 = (rand() + 100) % 1000;
				igra2 = (rand() + 100) % 1000;
				cout << "-----------------------------------\n\n";
				cout << "Посчитайте сколько будет " << igra1 << " + " << igra2 << " = ";
				cin >> igra3;
				if (igra3 == igra1 + igra2) {
					cout << "Ура, это правильный ответ! " << pet.getname() << " обрадовался!\n";
					pet.setplay(pet.getplay() + 5);
					if (igra3 % 3 == 0) {
						inventory.setmoney(inventory.getmoney() + 3);
						cout << "Вы заработали 3 монетки !!!\n";
					}
					else if (igra3 % 3 == 1) {
						inventory.setmoney(inventory.getmoney() + 4);
						cout << "Вы заработали 4 монетки !!!\n";
					}
					else if (igra3 % 3 == 2) {
						inventory.setmoney(inventory.getmoney() + 5);
						cout << "Вы заработали 5 монеток !!!\n";
					}
					Sleep(5000);
				}
				else {
					cout << "О нет, это неправильный ответ! " << pet.getname() << " растроился\n";
					pet.setplay(pet.getplay() - 5);
				}
			}
			else if (choose == 4) {
				pet.settoilettes(pet.gettoilettes() + 5);
				if (pet.gettoilettes() > 100) pet.settoilettes(100);
			}

			else if (choose == 5) {
				system("cls");
				cout << "ммммммммммммммммммммммммммммммммммм\n-----------------------------------\n\n еда - " << inventory.geteat() << "\n монетки - " << inventory.getmoney() << "\n---------------------------------- -\n введите любой символ чтобы выйти - ";
				cin >> close;
			}
			else if (choose == 6) {
				while (choose != 2) {
					system("cls");
					if (close == "dasha") { cout << "*В вашем инвентаре +1 еда*\n"; }
					else if (close == "dafsha") { cout << "У вас недостаточно денег((\n"; }
					cout << "ммммммммммммммммммммммммммммммммммм\n-----------------------------------\n\n еда - 5 монеток\n---------------------------------- -\n Чтобы купить еду  введите - '1'\n Чтобы выйти введите - '2'";
					cin >> choose;
					if (choose == 1) {
						if (inventory.getmoney() >= 5) {
							close = "dasha";
							inventory.seteat(inventory.geteat() + 1);
							inventory.setmoney(inventory.getmoney() - 5);
						}
						else close = "dafsha";
					}
				}
			}
			else if (choose == 7)
				end = true;
		}
		while (pet.getSleep() && !end) {
			system("cls");
			pet.printSleepPet();
			cout << "Если вы хотите разбудить питомца нажмите '1'";
			cout << endl << "Если вы хотите выйти нажмите '2'" << endl;
			cin >> choose;
			if (choose == 1) {
				pet.setIFsleep(false);
				TimeEnd = time(NULL);
				pet.setsleep(pet.getsleep() + (TimeEnd - TimeStart) / 20);
				if (pet.getsleep() > 100) pet.setsleep(100);
				pet.sethungry(pet.gethungry() - (TimeEnd - TimeStart) / 20);
				pet.settoilettes(pet.gettoilettes() - (TimeEnd - TimeStart) / 20);
				pet.setplay(pet.getplay() - (TimeEnd - TimeStart) / 20);
			}
			else if (choose == 2)
				end = true;
		}
	}

	//сохранение(статус - работает)
	pet.SavePet();
	ofstream fout;

	fout.open("time.txt", ofstream::trunc);
	if (!fout.is_open()) cout << "Ошибка открытия файла" << endl;
	else {
		fout.write((char*)&TimeStart, sizeof(time_t));
	}
	fout.close();

	inventory.SaveInventory();
}