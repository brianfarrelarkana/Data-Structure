#include <iostream>

using namespace std;

int main()
{
    int arr352[10];

    cout << "Masukkan data array      : ";

    for (int x352 = 0; x352 < 10; x352++)
    {
        cin >> arr352[x352];
    }

    cout << "Nomor genap dalam array  : ";

    for (int x352 = 0; x352 < 10; x352++)
    {
        if (arr352[x352] % 2 == 0)
        {
            cout << arr352[x352] << ", ";
        }
    }

    cout << "\nNomor ganjil dalam array : ";

    for (int x352 = 0; x352 < 10; x352++)
    {
        if (arr352[x352] % 2 == 1)
        {
            cout << arr352[x352] << ", ";
        }
    }

}