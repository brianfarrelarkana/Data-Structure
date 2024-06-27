#include <iostream>

using namespace std;

int main (){
    int pilih352;
    float a352, b352, c352, k352, l352;

    do {
    cout << "\n\nSelamat datang di kalkulator segitiga\n";
    cout << "\nSilakan pilih opsi di bawah ini :\n";
    cout << "1. Menghitung keliling segitiga\n";
    cout << "2. Menghitung luas segitiga\n";
    cout << "3. Keluar program\n";
    cout << "Masukkan pilihan anda : "; cin >> pilih352;

    switch (pilih352){

        case 1:
        cout << "\nSilakan masukkan panjang dari ketiga sisi segitiga :\n\n";
        cout << "Panjang sisi pertama : "; cin >> a352;
        cout << "Panjang sisi kedua   : "; cin >> b352;
        cout << "Panjang sisi ketiga  : "; cin >> c352;
        k352 = a352 + b352 + c352;
        cout << "\nKeliling segitiga = " << a352 << " + " << b352 << " + " << c352 << " = " << k352;
        break;

        case 2:
        cout << "\nSilakan masukkan panjang alas segitiga : "; cin >> a352;
        cout << "Silakan masukkan tinggi segitiga       : "; cin >> b352;
        l352 = a352 * b352 / 2;
        cout << "\nLuas segitiga = " << a352 << " * " << b352 << " / 2 = " << l352;
        break;
    } 
    } while (pilih352 < 3);

    return 0;
}