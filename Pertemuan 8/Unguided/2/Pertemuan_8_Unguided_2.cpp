#include <iostream>

using namespace std;

int main()
{
    int x = 20;
    int jumlah = 0;
    char arr[x];
    char vokal[10] = {'A', 'I', 'U', 'E', 'O', 'a', 'i', 'u', 'e', 'o'};

    cout << "\nMasukkan kalimat : "; cin.getline(arr, sizeof(arr));

    for (int a = 0; arr[a] != '\0'; a++){
        for (int i = 0; i < 10; i++){
            if (arr[a] == vokal[i]){
                jumlah++;
            }
        }
    }

    cout << "\nBanyaknya huruf vokal pada kalimat anda adalah " << jumlah << endl;
    return 0;
}