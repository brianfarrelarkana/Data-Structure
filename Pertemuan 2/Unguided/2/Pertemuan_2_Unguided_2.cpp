#include <iostream>

using namespace std;

int main()
{
    int x352, y352, z352;
    cout << "Masukkan tinggi array  : "; cin >> x352;
    cout << "Masukkan lebar array   : "; cin >> y352;
    cout << "Masukkan panjang array : "; cin >> z352;
    cout << endl;    
    
    int arr352[x352][y352][z352];

    for (int a352 = 0; a352 < x352; a352++)
    {
        for (int b352 = 0; b352 < y352; b352++)
        {
            for (int c352 = 0; c352 < z352; c352++)
            {
                cout << "Input Array[" << a352 << "][" << b352 << "][" << c352 << "] = ";
                cin >> arr352[a352][b352][c352];
            }
        }
        cout << endl;
    }

    for (int a352 = 0; a352 < x352; a352++)
    {
        for (int b352 = 0; b352 < y352; b352++)
        {
            for (int c352 = 0; c352 < z352; c352++)
            {
                cout << arr352[a352][b352][c352] << " " << ends;
            }
            cout << endl;
        }
        cout << endl;
    }
}