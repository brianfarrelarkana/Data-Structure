#include <iostream>

using namespace std;

struct unguided_1
{
    string nama;
    int umur;
    unguided_1 *next;
};

unguided_1 *head;
unguided_1 *tail;

void init()
{
    head = NULL;
    tail = NULL;
}

bool isEmpty()
{
    if (head == NULL)
        return true;

    else
        return false;
}

int hitung_data()
{
    unguided_1 *hitung;
    hitung = head;
    int jumlah = 0;
    while (hitung != NULL)
    {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}

void hapus_data_tengah(int posisi)
{
    unguided_1 *hapus, *bantu, *bantu2;
    if (posisi < 1 || posisi > hitung_data())
    {
        cout << "\nPosisi di luar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "\nPosisi bukan posisi tengah" << endl;
    }
    else
    {
        int nomor = 1;
        bantu = head;
        while (nomor <= posisi)
        {
            if (nomor == posisi - 1)
            {
                bantu2 = bantu;
            }
            if (nomor == posisi)
            {
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        bantu2->next = bantu;
        delete hapus;
    }
}

void tambah_data_tengah(string nama, int umur, int posisi)
{
    if (posisi < 1 || posisi > hitung_data())
    {
        cout << "\nPosisi diluar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "\nPosisi bukan posisi tengah" << endl;
    }
    else
    {
        unguided_1 *baru, *bantu;
        baru = new unguided_1();
        baru->nama = nama;
        baru->umur = umur;

        bantu = head;
        int nomor = 1;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

void tambah_data_depan(string nama, int umur)
{
    unguided_1 *baru = new unguided_1;
    baru->nama = nama;
    baru->umur = umur;
    baru->next = NULL;

    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        baru->next = head;
        head = baru;
    }
}

void tambah_data_belakang(string nama, int umur)
{
    unguided_1 *baru = new unguided_1;
    baru->nama = nama;
    baru->umur = umur;
    baru->next = NULL;

    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        tail->next = baru;
        tail = baru;
    }
}

void ganti_data_tengah(string nama, int umur, int posisi)
{
    unguided_1 *bantu;

    if (isEmpty() == false)
    {
        if (posisi < 1 || posisi > hitung_data())
        {
            cout << "\nPosisi di luar jangkauan" << endl;
        }
        else if (posisi == 1)
        {
            cout << "\nPosisi bukan posisi tengah" << endl;
        }
        else
        {
            bantu = head;
            int nomor = 1;
            while (nomor < posisi)
            {
                bantu = bantu->next;
                nomor++;
            }
            bantu->nama = nama;
            bantu->umur = umur;
        }
    }
    else
    {
        cout << "\nList masih kosong!" << endl;
    }
}

void tampilkan_data()
{
    unguided_1 *bantu;
    bantu = head;

    if (isEmpty() == false)
    {   
        cout << endl;
        while (bantu != NULL)
        {
            cout << bantu->nama << "\t" << ends;
            cout << bantu->umur << endl;
            bantu = bantu->next;
        }
    }
    else
    {
        cout << "\nList masih kosong!" << endl;
    }
}

int main()
{
    init();
    string nama;
    int pilih, umur, posisi;

    cout << "\n\nSelamat datang di menu program single linked list non-circular\n";

    while(true)
    {
        cout << "\nSilakan pilih menu yang anda ingin lakukan\n";
        cout << "1. Menambahkan data awal\n";
        cout << "2. Menambahkan data tengah\n";
        cout << "3. Menambahkan data belakang\n";
        cout << "4. Menghapus data tengah\n";
        cout << "5. Mengubah data tengah\n";
        cout << "6. Menampilkan data\n";
        cout << "7. Keluar program\n";
        cout << "Masukkan pilihan anda : "; cin >> pilih;

        switch(pilih)
        {
            case 1:
            {
                cout << "\nMasukkan nama : "; cin >> nama;
                cout << "Masukkan umur : "; cin >> umur;
                tambah_data_depan(nama, umur);
                break;
            }
            
            case 2:
            {
                cout << "\nMasukkan posisi data baru : "; cin >> posisi;
                cout << "\nMasukkan nama : "; cin >> nama;
                cout << "Masukkan umur : "; cin >> umur;
                tambah_data_tengah(nama, umur, posisi);
                break;
            }

            case 3:
            {
                cout << "\nMasukkan nama : "; cin >> nama;
                cout << "Masukkan umur : "; cin >> umur;
                tambah_data_belakang(nama, umur);
                break;
            }

            case 4:
            {
                cout << "\nMasukkan posisi data yang akan dihapus : "; cin >> posisi;
                hapus_data_tengah(posisi);
                break;
            }

            case 5:
            {
                cout << "\nMasukkan posisi data yang akan diubah : "; cin >> posisi;
                cout << "\nMasukkan nama baru : "; cin >> nama;
                cout << "Masukkan umur baru : "; cin >> umur;
                ganti_data_tengah(nama, umur, posisi);
                break;
            }

            case 6:
            {
                tampilkan_data();
                break;
            }

            case 7:
            {
                return 0;
            }
            default:
            {
                cout << "\nPilihan yang anda masukkan tidak ada di menu\n";
                break;
            }
        }
    }
    return 0;
}