#include <windows.h>
#include <iostream>
#include <conio.h>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <conio.h>
#include "animasi.h"
#include "class.h"
using namespace std;

void clrl() {
    cout << "\033[A"; //cursor ke atas
    cout << "\033[2K"; //menghapus satu baris
}

void animasikan()
{
    
    for (int i = 0; i < 6; ++i) {
        system("cls");
        cout << monsterFrames[i] << "\n"<< endl;
        delay(700);
    }
}



void intro(){
    char_delay("\n\n\n\n\n\n\n\n\n\n\n                                               Tips!", 10,0,0);
    delay(1000);
    char_delay("\n\n                       Tekan enter untuk melanjutkan setiap dialog yang muncul",10,0,1);
    system("cls");
    char_delay("\n\n\n\n\n\n\n\n\n\n\n                                         ",10,0,0);
    char_delay( "selamat bermain!",100,0,1);
    system("cls");
}


int main(){
    system("cls");
    pemilihan opsi;
    intro();

    Player player;
    string prev_nama = "";
    while(true){
    introducer1();
    char_delay("Bagaimana saya memanggil anda?\n",10,0,0);
    cin >> player.nama;
    delay(500);
    
    if (player.nama == prev_nama){
        system("cls");
        introducer3();
        char_delay("\n...",10,0,1);clrl();
        char_delay("\nKamu bercanda?",10,0,1);clrl();
        char_delay("\nBukankah nama ini sama dengan yang sebelumnya???",10,0,1);clrl();
        char_delay("\n...",10,1,1);
        char_delay("\n...",10,1,1);
        char_delay("\n...",10,1,1);
        char_delay("\nBaiklah...",20,1,1);
    }
    
    prev_nama = player.nama;

    system("cls");
    introducer2();
    char_delay("Hi, ", 10,0,0);delay(1000);
    char_delay(player.nama + "...",200,0,0);
    delay(1000);
    balik1:
    char_delay("\nApakah nama ini sudah benar?(y/n)",10,0,0);
    opsi.option = getch();
        if (opsi.option == 'y'){
            break;
        }
        else if(opsi.option == 'n'){
            system("cls");
            continue;
        }
        else{
            cout << "\nerror! Pilihan hanya y atau n!\n";
            goto balik1;
        }
    }

    char_delay("Senang bertemu denganmu...",10,1,1);
    balik2:
    char_delay("Apakah Kamu ingin membaca prologue terlebih dahulu? (y/n)",10,1,0);
    opsi.option = getch();
    
    if (opsi.option == 'y'){
        system("cls");
        prologue();
    }

    else if (opsi.option =='n'){
        system("cls");
    }

    else{
        goto balik2;
    }

    ///////////////////////////////////////////////////////
    balik3:
    char_delay("Pick your class...",10,1,0);
    cout << klass[0];
    opsi.option = getch();
    if (opsi.option == '1'){
        player.senjata = "sword";
        player.x = 5000;
        player.y = 19000;
        player.hp = 12000;
    }
    else if(opsi.option == '2'){
        player.senjata = "bow";
        player.x = 3000;
        player.y = 15000;
        player.hp = 9000;
    }
    else if (opsi.option == '3'){
        player.senjata = "shield";
        player.x = 2000;
        player.y = 13000;
        player.hp = 20000;
    }
    else{
        char_delay("\nError! Pilihan hanya 1 sampai 3... (press enter to continue)",10,1,1);
        getch();
        goto balik3;
    }
    for (int i = 0 ; i < 4; ++i) {
            system("cls");
            cout << tulis_besar[i];
            delay(1000);
        }
    
    system ("cls");
    delay(2000);

    ////////////////////////// game on /////////////////////////////
    Boss boss;
    bar health;
    cout << monsterFrames[0];
        char_delay("Manusia bodoh...", 10, 0, 1);
        system("cls");
    cout << monsterFrames[0];
        char_delay("Biar aku perlihatkan rasanya keputusasaan...!", 10, 0, 1);
        system("cls");
    animasikan();
    hp_interface(health.hp_ui);

srand(time(NULL));


    // Setup player



    cout << "\n\nBattle Start!" << endl;


    while (player.hp > 0 && boss.hp > 0) {
        // Player's turn
        system("cls");
        cout << monsterFrames[6];
        hp_interface(health.hp_ui);

        cout << "Player's turn to attack!" << endl;
        waitForUserInput();
        system("cls");
        int player_damage = player.attack();
        int temp_mons_hp = boss.hp;
        boss.hp -= player_damage;
        float hitung = boss.hp / temp_mons_hp;
        health.hp_ui *= hitung;


        cout << monsterFrames[6];
        hp_interface(health.hp_ui);
        
        cout << "Player dealt " << player_damage << " damage to the boss!" << endl;

        if (boss.hp <= 0) {
            cout << "Boss defeated!" << endl;
            break;
        }

        // Display status
        displayStatus(player, boss);

        // Boss's turn
        cout << "Boss's turn to attack!" << endl;
        waitForUserInput();
        int boss_damage = boss.attack();
        player.hp -= boss_damage;
        cout << "Boss dealt " << boss_damage << " damage to the player!" << endl;

        if (player.hp <= 0) {
            cout << "Player defeated!" << endl;
            break;
        }

        // Display status
        displayStatus(player, boss);
        waitForUserInput();
    }

    if (player.hp > 0) {
        system("cls");
        cout << monsterFrames[7]<< "Congratulations, " << player.nama << "! You have defeated the boss!" << endl;
    } else {
        cout << "Game Over! The boss has defeated you." << endl;
    }

    return 0;
}