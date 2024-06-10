#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int crit(int x, int y) {
        int multiplier = (rand() % (y - x + x)) + x;
        return multiplier;
    }

int serang(int a, int b) {
    int damage = (rand() % (b - a + 1)) + a;
    return damage;
}

class pemilihan{
public:
    char option;
};

class Boss {
public:
    string nama = "Apex Dominator";
    float hp = 70000;

    int x = 700, y = 120;

    int attack() {
        int damage = serang(x, y);
        int penentu_crit = crit(1, 10);

        if (penentu_crit == 1 || penentu_crit == 2) {
            damage *= 2;
            cout << "Boss critical hit!" << endl;
        }
        return damage;
    }
};


class Player {
public:
    string nama;
    string senjata;
    int hp;

    int x, y;

    int attack() {
        int damage = serang(x, y);
        if (senjata == "sword") {
            int penentu_crit = crit(1, 5);

            if (penentu_crit == 1 || penentu_crit == 2) {
                damage *= 2;
                cout << "Player critical hit!" << endl;
            }
        }
        return damage;
    }
};

class bar{
public:
    int hp_ui = 100;
};

void hp_interface(int x){
    int n = 0;

    while (n < 2){
        for (int i = 0; i <= x; ++i){
            cout << "|";
        }
        cout << endl;
        ++n;
    }
}

void displayStatus(Player& player, Boss& boss) {
    cout << "Player HP: " << player.hp << endl;
    cout << "Boss HP: " << boss.hp << endl;
}


void waitForUserInput() {
    cout << "Press Enter to continue..." << endl;
    cin.ignore();
    cin.get();
}