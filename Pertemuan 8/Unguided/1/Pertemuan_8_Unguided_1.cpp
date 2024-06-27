#include <iostream>

using namespace std;

char kalimat[20];
char cari;

void selection_sort()
{
    int panjang = 0;
    while (kalimat[panjang] != '\0')
    {
        panjang++;
    }

    for (int x = 0; x < panjang - 1; x++)
    {
        int min = x;
        for (int y = x + 1; y < panjang; y++)
        {
            if (kalimat[y] < kalimat[min])
            {
                min = y;
            }
        }
        if (min != x)
        {
            char sem = kalimat[x];
            kalimat[x] = kalimat[min];
            kalimat[min] = sem;
        }
    }
}

void binary_search()
{
    int awal = 0;
    int akhir = 0;
    while (kalimat[akhir] != '\0')
    {
        akhir++;
    }
    akhir--;

    bool huruf_ditemukan = false;

    cout << "\nHuruf '" << cari << "' ditemukan pada indeks ke ";
    for (int x = awal; x <= akhir; x++)
    {
        if (kalimat[x] == cari)
        {
            cout << x << ", ";
            huruf_ditemukan = true;
        }
    }
    cout << endl;

    if (!huruf_ditemukan)
    {
        cout << "Huruf '" << cari << "' tidak ditemukan dalam kalimat" << endl;
    }
}

int main()
{
    cout << "\nMasukkan kalimat : "; cin.getline(kalimat, sizeof(kalimat));
    cout << "Masukkan huruf yang ingin dicari : "; cin >> cari;

    selection_sort();
    cout << "\nKalimat setelah diurutkan : " << kalimat << endl;

    binary_search();

    return 0;
}