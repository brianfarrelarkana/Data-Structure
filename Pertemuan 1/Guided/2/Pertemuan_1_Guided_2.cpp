#include <iostream>

using namespace std;

struct mahasiswa {
    char *name, *address;
    int age;
};

int main()
{
    // Menggunakan struct
    struct mahasiswa mhs1, mhs2;

    //Mengisi struct
    mhs1.name = "Hamid";
    mhs1.address = "Chillacap";
    mhs1.age = 30;

    mhs2.name = "Sepuh";
    mhs2.address = "Backasi";
    mhs2.age = 40;

    //Mencetak struct
    cout << "Mahasiswa 1\n";
    cout << "Nama\t:" << mhs1.name << endl;
    cout << "Alamat\t:" << mhs1.address << endl;
    cout << "Umur\t:" << mhs1.age << endl;

    cout << "Mahasiswa 2\n";
    cout << "Nama\t:" << mhs2.name << endl;
    cout << "Alamat\t:" << mhs2.address << endl;
    cout << "Umur\t:" << mhs2.age << endl;

    return 0;
   
}