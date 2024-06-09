#include <iostream>
#include <cstdlib>
using namespace std;

class pemilihan{
public:
    char option;
};

int crit(int x, int y){
    int multiplier = (rand() % (y - x + x)) + x;
    return multiplier;
}

int serang(int a, int b){
        srand(time(NULL));        
        int damage = (rand() % (b - a + 1)) + a;

        return damage;
}

class bar{
public:
    int hp_ui = 100;
};

class boss{
public:
    string nama = "Apex Dominator";
    int hp = 100000;

    int x = 70, y = 120;
    int attack(){
        int damage = serang(x,y);
        int penentu_crit = crit(1,10);

            if (penentu_crit == 1 || penentu_crit == 2){
                damage *= 2;
            }
        return damage;
    }
    
};

class player{
public:
    string nama;
    string senjata;
    int hp;

    int x,y;
    int attack(){
        int damage = serang(x,y);
        if (senjata == "sword"){
            int penentu_crit = crit(1,5);

            if (penentu_crit == 1 || penentu_crit == 2){
                damage *= 2;
            }
        }
        return damage;
    }

float scale(float z){
    boss mons;

    float hp_sebelum = mons.hp; 
    float ahh = mons.hp - z; 
    double hitung = 1 - (ahh / hp_sebelum);

    float darah = 100 *hitung; 

    return hitung;
}
    
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

};