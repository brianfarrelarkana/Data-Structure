#include <iostream>

using namespace std;

struct unguided_2
{
    string nama_produk;
    int harga;
    unguided_2 *prev;
    unguided_2 *next;
};

    unguided_2 *head;
    unguided_2 *tail;

void init()
    {
        head = nullptr;
        tail = nullptr;
    }

int hitung_total()
{
    unguided_2 *current = head;
    int hitung = 0;
    while (current != nullptr)
    {
        hitung++;
        current = current->next;
    }
    return hitung;
}

void tambah_data (string nama_produk, int harga)
{
    unguided_2 *newNode = new unguided_2;
    newNode->nama_produk = nama_produk;
    newNode->harga = harga;
    newNode->next = nullptr;
    newNode->prev = tail;
    if (tail != nullptr)
    {
        tail->next = newNode;
    }
    else
    {
        head = newNode;
    }
    tail = newNode;
}

void hapus_data()
{
    if (head == nullptr)
    {
        return;
    }
    unguided_2 *temp = head;
    head = head->next;
    if (head != nullptr)
    {
        head->prev = nullptr;
    }
    else
    {
        tail = nullptr;
    }
    delete temp;
}

bool update_data (string nama_produk_lama, string nama_produk_baru, int harga_lama, int harga_baru)
{
    unguided_2 *current = head;
    while (current != nullptr)
    {
        if (current->nama_produk == nama_produk_lama && current->harga == harga_lama)
        {
            current->nama_produk = nama_produk_baru;
            current->harga = harga_baru;
            return true;
        }
        current = current->next;
    }
    return false;
}

void tambah_tengah(string nama_produk, int harga, int posisi)
{
    if (head == nullptr){
        cout << "\nList masih kosong!" << endl;
    } else if (posisi == 1){
        cout << "\nPosisi bukan posisi tengah" << endl;
    } else if (posisi < 1 || posisi > hitung_total()){
        cout << "\nPosisi di luar jangkauan" << endl;
    } else {
        unguided_2 *newNode;
        newNode = new unguided_2();
        newNode->nama_produk = nama_produk;
        newNode->harga = harga;

        unguided_2 *current = head;
        int nomor = 1;
        while (nomor < posisi - 1){
            current = current->next;
            nomor++;
        }

        unguided_2 *afterNode;
        afterNode = current->next;
        newNode->prev = current;
        newNode->next = afterNode;
        current->next = newNode;
        afterNode->prev = newNode;

    }
}

void hapus_tengah(string nama_produk, int harga, int posisi)
{
    if (head == nullptr){
        cout << "\nList masih kosong!" << endl;
    } else if (posisi == 1){
        cout << "\nPosisi bukan posisi tengah" << endl;
    } else if (posisi < 1 || posisi > hitung_total()){
        cout << "\nPosisi di luar jangkauan" << endl;
    } else {
        unguided_2 *current = head;
        int nomor = 1;
        while (nomor < posisi - 1){
            current = current->next;
            nomor++;
        }

        unguided_2 *hapus;
        unguided_2 *afterNode;
        hapus = current->next;
        afterNode = hapus->next;
        current->next = afterNode;
        afterNode->prev = current;
        delete hapus;
    }
}

void hapus_total()
{
    unguided_2 *current = head;
    while (current != nullptr)
    {
        unguided_2 *temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
}

void display()
{
    unguided_2 *current = head;
    cout << "\nNama Produk        Harga\n\n";
    while (current != nullptr)
    {
        cout << current->nama_produk << "\t\t" << ends;
        cout << current->harga << endl;
        current = current->next;
    }
    cout << endl;
}

int main()
{
    init();
    string nama_produk, nama_produk_lama, nama_produk_baru;
    int harga, harga_lama, harga_baru, pilih, posisi;
    while (true)
    {
        cout << "\nToko Skincare Purwokerto\n";
        cout << "1. Tambah Data\n";
        cout << "2. Hapus Data\n";
        cout << "3. Update Data\n";
        cout << "4. Tambah Data Urutan Tertentu\n";
        cout << "5. Hapus Data Urutan Tertentu\n";
        cout << "6. Hapus Seluruh Data\n";
        cout << "7. Tampilkan Data\n";
        cout << "8. Exit\n";
        cout << "Masukkan pilihan : "; cin >> pilih;
        
        switch (pilih)
        {
            case 1:
            {
                cout << "\nMasukkan nama produk  : "; cin >> nama_produk;
                cout << "Masukkan harga produk : "; cin >> harga;
                tambah_data(nama_produk, harga);
                break;
            }
            case 2:
            {
                hapus_data();
                break;
            }
            case 3:
            {
                cout << "\nMasukkan nama produk lama  : "; cin >> nama_produk_lama;
                cout << "Masukkan harga produk lama : "; cin >> harga_lama;

                cout << "\nMasukkan nama produk baru  : "; cin >> nama_produk_baru;
                cout << "Masukkan harga produk baru : "; cin >> harga_baru;
                bool updated = update_data(nama_produk_lama, nama_produk_baru, harga_lama, harga_baru);
                if (!updated)
                {
                    cout << "\nData tidak ditemukan" << endl;
                }
                break;
            }
            case 4:
            {   
                cout << "\nMasukkan posisi data baru : "; cin >> posisi;

                cout << "\nMasukkan nama produk : "; cin >> nama_produk;
                cout << "Masukkan harga       : "; cin >> harga;

                tambah_tengah(nama_produk, harga, posisi);
                break;
            }
            case 5:
            {   
                cout << "\nMasukkan posisi data yang akan dihapus : "; cin >> posisi;
                
                hapus_tengah(nama_produk, harga, posisi);
                break;
            }
            case 6:
            {
                hapus_total();
                break;
            }
            case 7:
            {
                display();
                break;
            }
            case 8:
            {
                return 0;
            }
            default:
            {
                cout << "\nPilihan anda tidak ada di menu" << endl;
                break;
            }
        }
    }
    return 0;
}