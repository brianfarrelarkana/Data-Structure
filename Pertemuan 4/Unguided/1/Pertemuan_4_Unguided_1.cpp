#include <iostream>

using namespace std;

struct unguided
{
    string nama;
    string nim;
    unguided *next;
};

unguided *head, *tail, *baru, *bantu, *hapus, *sebelum, *hitung;
void init()
{
    head = NULL;
    tail = NULL;
};

bool isEmpty()
{
    if (head == NULL && tail == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int hitung_list()
{
    hitung = head;
    int jumlah = 0;
    while (hitung != NULL)
    {
        hitung = hitung->next;
        jumlah++;
    }
    return jumlah;
}

void tambah_depan(string nama, string nim)
{
    unguided *baru = new unguided;
    baru->nama = nama;
    baru->nim = nim;
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

void tambah_belakang(string nama, string nim)
{
    unguided *baru = new unguided;
    baru->nama = nama;
    baru->nim = nim;
    baru->next = NULL;

    if (isEmpty() == true)
    {
        head = tail = baru;
    }
    else
    {
        tail->next = baru;
        tail = baru;
    }
};

void tambah_tengah(string nama, string nim, int posisi)
{
    if (posisi < 1 || posisi > hitung_list())
    {
        cout << "\nPosisi diluar jangkauan\n\n" << endl;
    }
    else if (posisi == 1)
    {
        cout << "\nPosisi bukan posisi tengah\n\n" << endl;
    }
    else
    {
        baru = new unguided();
        baru->nama = nama;
        baru->nim = nim;

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

void hapus_depan()
{
    if (isEmpty() == false)
    {
        if (head->next != NULL)
        {
            cout << "\nData " << head->nama << " berhasil di hapus\n\n";
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "\nList kosong!\n\n" << endl;
    }
}

void hapus_belakang()
{
    if (isEmpty() == false)
    {
        if (head != tail)
        {
            hapus = tail;
            bantu = head;
            while (bantu->next != tail)
            {
                bantu = bantu->next;
            }
            cout << "\nData " << tail->nama << " berhasil di hapus\n\n";
            tail = bantu;
            tail->next = NULL;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "\nList kosong!\n\n" << endl;
    }
}

void hapus_tengah(int posisi)
{
    if (posisi < 1 || posisi > hitung_list())
    {
        cout << "\nPosisi di luar jangkauan\n\n" << endl;
    }
    else if (posisi == 1)
    {
        cout << "\nPosisi bukan posisi tengah\n\n" << endl;
    }
    else
    {
        int nomor = 1;
        bantu = head;
        while (nomor <= posisi)
        {
            if (nomor == posisi - 1)
            {
                sebelum = bantu;
            }
            if (nomor == posisi)
            {
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        cout << "\nData " << hapus->nama << " berhasil di hapus\n\n";
        sebelum->next = bantu;
        delete hapus;
    }
}

void ubah_depan(string nama, string nim)
{
    if (isEmpty() == 0)
    {
        cout << "\nData " << head->nama << " telah diganti dengan data " << nama << "\n\n";
        head->nama = nama;
        head->nim = nim;
    }
    else
    {
        cout << "\nList masih kosong!\n\n" << endl;
    }
}

void ubah_belakang(string nama, string nim)
{
    if (isEmpty() == 0)
    {
        cout << "\nData " << tail->nama << " telah diganti dengan data " << nama << "\n\n";
        tail->nama = nama;
        tail->nim = nim;
    }
    else
    {
        cout << "\nList masih kosong!\n\n" << endl;
    }
}

void ubah_tengah(string nama, string nim, int posisi)
{
    if (isEmpty() == 0)
    {
        if (posisi < 1 || posisi > hitung_list())
        {
            cout << "\nPosisi di luar jangkauan\n\n" << endl;
        }
        else if (posisi == 1)
        {
            cout << "\nPosisi bukan posisi tengah\n\n" << endl;
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
            cout << "\nData " << bantu->nama << " telah diganti dengan data " << nama << "\n\n";
            bantu->nama = nama;
            bantu->nim = nim;
        }
    }
    else
    {
        cout << "\nList masih kosong!\n\n" << endl;
    }
}

void hapus_list()
{
    bantu = head;
    while (bantu != NULL)
    {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "\nList berhasil di hapus\n\n";
}

void tampilkan_list()
{
    bantu = head;
    if (isEmpty() == false)
    {
        cout << "\nData Mahasiswa\n";
        cout << "\nNAMA         NIM\n\n";

        while (bantu != NULL)
        {
            cout << bantu->nama << "\t" << ends;
            cout << bantu->nim << endl;
            bantu = bantu->next;
        }
        cout << "\n";
    }
    else
    {
        cout << "\nList masih kosong!\n\n" << endl;
    }
}
int main()
{
    init();
    string nama, nim;
    int pilih, posisi;
    cout << "\n\nSelamat Datang\n";
    
    while (true)
    {
        cout << "\nMenu Program Single Linked List Non-Circular\n";
        cout << "\nSilakan pilih menu yang anda ingin lakukan\n";
        cout << "1.  Tambah Depan\n";
        cout << "2.  Tambah Belakang\n";
        cout << "3.  Tambah Tengah\n";
        cout << "4.  Ubah Depan\n";
        cout << "5.  Ubah Belakang\n";
        cout << "6.  Ubah Tengah\n";
        cout << "7.  Hapus Depan\n";
        cout << "8.  Hapus Belakang\n";
        cout << "9.  Hapus Tengah\n";
        cout << "10. Hapus List\n";
        cout << "11. Tampilkan List\n";
        cout << "0.  Keluar Program\n";
        cout << "\nMasukkan pilihan anda : ";
        cin >> pilih;
        switch (pilih)
        {
        case 1:
        {
            cout << "\n-Tambah Depan-\n";
            cout << "\nMasukkan Nama : "; cin >> nama;
            cout << "Masukkan NIM  : "; cin >> nim;
            cout << "\nData " << nama << " berhasil di input\n\n";
            tambah_depan(nama, nim);
            break;
        }
        case 2:
        {
            cout << "\n-Tambah Belakang-\n";
            cout << "\nMasukkan Nama : "; cin >> nama;
            cout << "Masukkan NIM  : "; cin >> nim;
            cout << "\nData " << nama << " berhasil di input\n\n";
            tambah_belakang(nama, nim);
            break;
        }
        case 3:
        {
            cout << "\n-Tambah Tengah-\n";
            cout << "\nMasukkan Nama   : "; cin >> nama;
            cout << "Masukkan NIM    : "; cin >> nim;
            cout << "Masukkan Posisi : "; cin >> posisi;
            cout << "\nData " << nama << " berhasil di input\n\n";
            tambah_tengah(nama, nim, posisi);
            break;
        }
        case 4:
        {
            cout << "\n-Ubah Depan-\n";
            cout << "\nMasukkan Nama : "; cin >> nama;
            cout << "Masukkan NIM  : "; cin >> nim;
            ubah_depan(nama, nim);
            break;
        }
        case 5:
        {
            cout << "\n-Ubah Belakang-\n";
            cout << "\nMasukkan Nama : "; cin >> nama;
            cout << "Masukkan NIM  : "; cin >> nim;
            ubah_belakang(nama, nim);
            break;
        }
        case 6:
        {
            cout << "\n-Ubah Tengah-\n";
            cout << "\nMasukkan Nama   : "; cin >> nama;
            cout << "Masukkan NIM    : "; cin >> nim;
            cout << "Masukkan Posisi : "; cin >> posisi;
            ubah_tengah(nama, nim, posisi);
            break;
        }
        case 7:
        {
            cout << "\n-Hapus Depan-\n";
            hapus_depan();
            break;
        }
        case 8:
        {
            cout << "\n-Hapus Belakang-\n";
            hapus_belakang();
            break;
        }
        case 9:
        {
            cout << "\n-Hapus Tengah-\n";
            cout << "\nMasukkan Posisi : "; cin >> posisi;
            hapus_tengah(posisi);
            break;
        }
        case 10:
        {
            cout << "\n-Hapus List-\n";
            hapus_list();
            break;
        }
        case 11:
        {
            tampilkan_list();
            break;
        }
        case 0:
        {
            return 0;
        }
        default:
        {
            cout << "\nPilihan yang anda masukkan tidak ada di menu\n\n";
                break;
        }
        }
    }
    return 0;
}