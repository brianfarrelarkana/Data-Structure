#include <iostream>

using namespace std;

int main()
{
    int a;
    int jumlah = 0;
    int x = 10;
    int arr[x] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int cari = 4;

    for (a = 0; a < x; a++){
        if (arr[a] == cari){
            jumlah++;
        }
    }

    cout << "\nData = {";
    for (a = 0; a < x; a++){
        if (a != x-1){
            cout << arr[a] << ", ";
        } else {
            cout << arr[a] << "}\n\n";
        }
    }

    cout << "Banyaknya angka 4 pada data di atas adalah " << jumlah << endl;
    return 0;
}