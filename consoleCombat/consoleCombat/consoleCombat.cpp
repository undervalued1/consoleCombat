#include <iostream>
#include <conio.h>
#include <windows.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

char playerName[6] = "";
char enemyName[6] = "bot";

class Hero {
private:
    char playerNameClass[256];      // Имя игрока
    char name[256];                 // Имя героя
    double hp;                      // Здоровье
    double maxHp;                   // Макс. здоровье
    double dmg;                     // Урон
    double armor;                   // Броня
    int evasion;                    // Уклонение

public:
    Hero(const char* playerNickName, const char* heroName, double health, double maxHp, double damage, double armor, int evade) {
        strcpy_s(playerNameClass, playerNickName);
        strcpy_s(name, heroName);
        hp = health;
        this->maxHp = maxHp;
        dmg = damage;
        this->armor = armor;
        evasion = evade;
    } // инициализация класса

    bool isAlive() const { return hp > 0; } // проверка на жизнь

    void takeDamage(double enemyDmg) { // метод для регистрации урона
        if (rand() % 100 < evasion) {
            cout << name << " увернулся от атаки!\n";
            return;
        }

        double baseDamage = enemyDmg - (enemyDmg * (armor / 100)); // основной урон с учетом брони
        if (baseDamage < 0) baseDamage = 0;  // если меньше 0 — обнуляем

        double minDamage = enemyDmg * 0.1; // минимальный урон (10% от базового)
        double finalDamage = max(baseDamage, minDamage); // берём большее

        hp -= finalDamage;
        if (hp < 0) hp = 0; // не даём хп уйти в минус

        cout << name << " получил " << finalDamage << " урона! Осталось HP: " << hp << endl;
    }

    // вывод информации атаки и получении урона
    void attack(Hero& enemy) {
        cout << playerNameClass << " атакует " << enemy.getPlayerName() << "!\n";
        cout << "Урон: " << dmg << ", броня цели: " << enemy.getArmor() << "\n";
        enemy.takeDamage(dmg);
    }

    // получение данных о герое
    const char* getPlayerName() const { return playerNameClass; }
    const char* getName() const { return name; }
    double getHp() const { return hp; }
    double getArmor() const { return armor; }
    double getDmg() const { return dmg; }
    int getEvasion() const { return evasion; }

    // выбор класса
    static Hero chooseHero(const char* playerNick) {
        char select;
        while (true) {
            cout << "Выберите класс героя:\n"
                << "1 - Танк\n"
                << "2 - Мечник\n"
                << "3 - Лучник\n"
                << "4 - Информация\n"
                << "=== ";
            cin >> select;

            switch (select)
            {
            case '1':
                cout << "Выбран класс: Танк" << endl;
                return Hero(playerNick, "Танк", 150, 150, 20, 13, 5);
            case '2':
                cout << "Выбран класс: Мечник" << endl;
                return Hero(playerNick, "Мечник", 100, 100, 10, 20, 10);
            case '3':
                cout << "Выбран класс: Лучник" << endl;
                return Hero(playerNick, "Лучник", 50, 50, 6, 30, 40);
            case '4':
                system("cls");
                cout << "Герой\t\tHP\tARM\tDMG\t\t\tEVASION\n\n";
                cout << "Танк\t\t150\t20\t13\t5%\n";
                cout << "Мечник\t\t100\t10\t20\t10%\n";
                cout << "Лучник\t50\t6\t30\t40%\n";
                system("pause");
                system("cls");
                break;
            default:
                cout << "error: неверный выбор" << endl;
                break;
            }
            system("pause");
            system("cls");
        }
    }
};

// метод битвы
void battle(Hero& hero1, Hero& hero2) {
    int turn = 1;
    cout << "Нажмите ENTER, чтобы начать бой...\n";
    _getch();
    system("cls");
    while (hero1.isAlive() && hero2.isAlive()) {
        system("cls");
        Hero& attacker = (turn == 1) ? hero1 : hero2;
        Hero& defender = (turn == 1) ? hero2 : hero1;

        cout << "Name\t\tHP\tARM\tDMG\tEVSN\t\tVS\t\tName\t\tHP\tARM\tDMG\tEVSN\n";
        cout << hero1.getName() << "\t\t" << hero1.getHp() << "\t" << hero1.getArmor() << "\t"
            << hero1.getDmg() << "\t" << hero1.getEvasion() << "\t\t\t\t"
            << hero2.getName() << "\t\t" << hero2.getHp() << "\t" << hero2.getArmor() << "\t"
            << hero2.getDmg() << "\t" << hero2.getEvasion() << "\n";

        cout <<"\t\t\t\t\t\t  (o)\t\t (o)\n"
            << "\t\t\t\t\t\t  /|\\\t\t /|\\\n"
            << "\t\t\t\t\t\t   |\t\t  |\n"
            << "\t\t\t\t\t\t  /\\\t\t  /\\\n"
            << playerName << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t" << enemyName << "\n"
            << "\t\t\t\t\t\t" << "    Ходит " << attacker.getPlayerName() << "\t\t\t\t\t\t\n"
            << "\t\t\t\t\t\t  ENTER - атака\t\t\t\t\t\t\n";

        _getch();
        attacker.attack(defender);
        turn = (turn == 1) ? 2 : 1;
        Sleep(2000);
    }

    cout << "Бой завершён!\n";
    if (hero1.isAlive())
        cout << hero1.getPlayerName() << " победил!\n";
    else
        cout << hero2.getPlayerName() << " победил!\n";
}

int main() {
    srand(time(0));
    setlocale(LC_ALL, "russian");
    bool login = false;
    int warning = 0;
    while (!login) {
        if (warning == 1)
            cout << "последнее предупреждение..........." << endl;
        cout << "Введите имя (до 5 символов): ";
        cin >> playerName;
        if (strlen(playerName) > 5) {
            cout << "error: Максимальная длина имени 5 символов! Попробуйте снова.\n";
            system("cls");
            if (warning == 1) {
                cout << "end." << endl;
                return 1;
            }
            else
                warning++;
        }
        else
            login = true;
    }
    system("cls");
    cout << "Выбор героя для " << playerName << "!\n";
    Hero player = Hero::chooseHero(playerName);

    cout << "\nВыбор противника!\n";
    Hero enemy = Hero::chooseHero(enemyName);
    system("cls");
    battle(player, enemy);
    return 0;
}
