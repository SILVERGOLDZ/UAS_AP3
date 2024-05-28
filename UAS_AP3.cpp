#include <iostream>
#include <conio.h>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <conio.h>
#include "animasi.h"
#include "class.h"
using namespace std;

void delay(int x){
    this_thread::sleep_for(chrono::milliseconds(x));
}

void char_delay(const string& teks, int ms, int x) {
    if (x == 1){
        system("cls");
    }

    for (char c : teks) {
        cout << c << flush; 
        delay(ms); 
    } 
    
}

void intro(){
    const char* array_string[] = {"\n\n\n\n\n\n\n\n\n\n\n                                               Tips!",
                                     "\n\n                       Tekan enter untuk melanjutkan setiap dialog yang muncul",
                                     "\n\n\n\n\n\n\n\n\n\n\n                                         ",
                                     "selamat bermain!", "Belajar", "C++", "doumo"};

    int arraySize = sizeof(array_string) / sizeof(array_string[0]);
    
    char_delay(array_string[0], 10,0);
    delay(1000);
    char_delay(array_string[1],10,0);
    getchar();
    system("cls");
    char_delay(array_string[2],10,0);
    char_delay(array_string[3],100,0);
    getchar();
    system("cls");
}

void teks(){
    const char* array_string[] = {"Tips!\nTekan enter untuk melanjutkan setiap dialog yang muncul",
                                     "Selamat bermain", "Belajar", "C++", "doumo"};

    int arraySize = sizeof(array_string) / sizeof(array_string[0]);
}

int main(){
    system("cls");
    char option;
    //intro();

    player karakter;
    string prev_nama = "";
    while(true){
    char_delay("Bagaimana saya memanggil anda?\n",10,0);
    cin >> karakter.nama;
    
    if (karakter.nama == prev_nama){
        char_delay("...",10,1);getch();
        char_delay("\nKamu bercanda?",10,1);getch();
        char_delay("\nBukankah nama ini sama dengan yang sebelumnya???",10,1);getch();
        char_delay("...",10,1);getch();
        char_delay("...",10,1);getch();
        char_delay("...",10,1);getch();
        char_delay("\nBaiklah...",20,1);getch();
    }
    prev_nama = karakter.nama;

    system("cls");
    char_delay("Hi, ", 10,0);delay(1000);
    char_delay(karakter.nama + "...",200,0);
    delay(1000);
    balik:
    char_delay("\nApakah nama ini sudah benar?(y/n)",10,0);
    option = getch();
        if (option == 'y'){
            break;
        }
        else if(option == 'n'){
            system("cls");
            continue;
        }
        else{
            cout << "\nerror! Pilihan hanya y atau n!\n";
            goto balik;
        }
    }
}