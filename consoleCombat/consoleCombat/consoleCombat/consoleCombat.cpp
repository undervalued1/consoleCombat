#include <iostream>
#include <conio.h>
using namespace std;
class Hero {
	float hp;
	float dmg;
	float armor;
	int perk;
	int evasion;
};
int main(){
    setlocale(LC_ALL, "russian");
    char name[256];
    char select;
    cout << "name: ";
    cin >> name;
    system("cls");
    
    while (true) {
        cout << "выберите класс героя:" << endl;
        cout << "1 - Танк" << endl;
        cout << "2 - Мечник" << endl;
        cout << "3 - Копейщик" << endl;
        cout << "4 - Информация" << endl;
        cout << "5 - Выход из программы" << endl;
        
        cout << "=== ";
        cin >> select;
        
        switch (select)
        {
        case '1':
            cout << "Выбран класс: Танк" << endl;
            break;
        case '2':
            cout << "Выбран класс: Мечник" << endl;
            break;
        case '3':
            cout << "Выбран класс: Копейщик" << endl;
            break;
        case '4':
            system("cls");
            cout << "Герой\t\tHP\tARM\tDMG\tPERK\t\t\t\t\t\t\t\tEVASION\n\n";
            cout << "Танк\t\t150\t20\t15\tУвеличение брони до 50 на 1 ход (каждые 3 хода, шанс 10%)\t5%" << endl;
            cout << "Мечник\t\t100\t10\t20\tКрит 9% (каждые 3 хода, шанс 10%)\t\t\t\t10%" << endl;
            cout << "Копейщик\t50\t6\t25\tХилка (каждые 3 хода, шанс 10%)\t\t\t\t\t20%" << endl;
            break;
        case '5':
            cout << "выход..." << endl;
            return 0;
        default:
            cout << "Ошибка: неверный выбор. Попробуйте снова." << endl;
            break;
        }
        system("pause");
        system("cls");
    }
    
    return 0;
}
