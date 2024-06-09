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

void animasikan(string text, int n, int j)
{
    
    while (true) {
        for (int i = n ; i <= j; ++i) {
            system("cls");
            cout << monsterFrames[i] << "\n" << text << endl;
            delay(700);
        }
    }

 
}


void intro(){
    const char* array_string[] = {"\n\n\n\n\n\n\n\n\n\n\n                                               Tips!",
                                     "\n\n                       Tekan enter untuk melanjutkan setiap dialog yang muncul",
                                     "\n\n\n\n\n\n\n\n\n\n\n                                         ",
                                     "selamat bermain!"};

    int arraySize = sizeof(array_string) / sizeof(array_string[0]);
    
    char_delay(array_string[0], 10,0,0);
    delay(1000);
    char_delay(array_string[1],10,0,1);
    system("cls");
    char_delay(array_string[2],10,0,0);
    char_delay(array_string[3],100,0,1);
    system("cls");
}


int main(){
    system("cls");
    pemilihan opsi;
    opsi.option;
    //intro();

    player karakter;
    string prev_nama = "";
    while(true){
    introducer1();
    char_delay("Bagaimana saya memanggil anda?\n",10,0,0);
    cin >> karakter.nama;
    delay(500);
    
    if (karakter.nama == prev_nama){
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
    prev_nama = karakter.nama;

    system("cls");
    introducer2();
    char_delay("Hi, ", 10,0,0);delay(1000);
    char_delay(karakter.nama + "...",200,0,0);
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
        //prologue()
    }

    else if (opsi.option =='n'){
        system("cls");
    }

    else{
        goto balik2;
    }

    ///////////////////////////////////////////////////////
    boss monster;
    player chara;

    balik3:
    char_delay("Pick your class...",10,1,0);
    cout << klass[0];
    opsi.option = getch();
    if (opsi.option == '1'){
        karakter.senjata = "sword";
        karakter.x = 2000;
        karakter.y = 8000;
        karakter.hp = 1000;
    }
    else if(opsi.option == '2'){
        karakter.senjata = "bow";
        karakter.x = 1000;
        karakter.y = 3000;
        karakter.hp = 700;
    }
    else if (opsi.option == '3'){
        karakter.senjata = "shield";
        karakter.x = 500;
        karakter.y = 2000;
        karakter.hp = 500;
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
    cout << monsterFrames[0];
        char_delay("Manusia bodoh...", 10, 0, 1);
        system("cls");
    cout << monsterFrames[0];
        char_delay("Biar aku perlihatkan rasanya keputusasaan...!", 10, 0, 1);
        system("cls");
    animasikan("", 0, 6);

}