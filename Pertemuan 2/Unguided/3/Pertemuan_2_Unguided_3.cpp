#include <iostream>

using namespace std;

int main()
{
    int menu352, x352, max352, min352;
    float jml352, rata352;

    cout << "Silakan masukkan panjang array : "; cin >> x352;

    int arr352[x352];

    for (int a352 = 0; a352 < x352; a352++)
    {
        cout << "Masukkan nilai array ke-" << a352 << " : "; cin >> arr352[a352];
    }
    
    do {
        cout << "\nSilakan pilih opsi di bawah ini :\n\n";
        cout << "1. Mencari nilai maksimum dari array\n";
        cout << "2. Mencari nilai minimum dari array\n";
        cout << "3. Mencari rata-rata dari array\n";
        cout << "4. Keluar program\n";
        cout << "Masukkan pilihan anda : "; cin >> menu352;

        switch (menu352)
        {
            case 1:
            max352 = arr352[0];
            for (int a352 = 0; a352 < x352; a352++)
            {
                if (arr352[a352] > max352)
                {
                    max352 = arr352[a352];
                }
            }
            cout << "\nNilai maksimum dari array yang sudah dimasukkan adalah " << max352 << endl;
            break;

            case 2:
            min352 = arr352[0];
            for (int a352 = 0; a352 < x352; a352++)
            {
                if (arr352[a352] < min352)
                {
                    min352 = arr352[a352];
                }
            }
            cout << "\nNilai minimum dari array yang sudah dimasukkan adalah " << min352 << endl;
            break;

            case 3:
            jml352 = 0;
            for (int a352 = 0; a352 < x352; a352++)
            {
                jml352 = arr352[a352] + jml352;
            }

            rata352 = jml352 / x352;
            cout << "\nRata-rata dari array yang sudah dimasukkan adalah " << rata352 << endl;
            break;

            case 4:
            cout << "Terima kasih karena sudah menggunakan program ini :)";
            break;

        }

    } while (menu352 < 4);

}