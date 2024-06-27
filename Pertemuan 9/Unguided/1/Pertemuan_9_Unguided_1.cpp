#include <iostream>
#include <iomanip>

using namespace std;

int x, jarak;
string kota_2211102352;
string simpul[10];
int busur[10][10];

void banyak()
{
    cout << "\nSelamat datang di program graf\n";
    cout << "\nSilakan masukkan jumlah simpul : "; cin >> x;
}

void nama()
{
    cout << "\nSilakan masukkan nama simpul :\n";
    for (int i = 0; i < x; i++)
    {
        cout << "Simpul " << i+1 << ": "; cin >> kota_2211102352;
        simpul[i] = kota_2211102352;
    }
}

void bobot()
{
    cout << "\nSilakan masukkan bobot antar simpul :\n";
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x; j++)
        {
            cout << simpul[i] << "\t-->\t" << simpul[j] << "\t= "; cin >> jarak;
            busur [i][j] = jarak;
        }
    }
}

void tampil()
{
    cout << endl;
    cout << "\t";
    for (int i = 0; i < x; i++)
    {
        cout << "\t" << simpul[i];
    }
    cout << endl;
    for (int i = 0; i < x; i++)
    {
        cout << simpul [i] << "\t";
        for (int j = 0; j < x; j++)
        {
            cout << "\t" << busur[i][j];
        }
        cout << endl;
    }
}

int main()
{
    banyak();
    nama();
    bobot();
    tampil();
    return 0;
}