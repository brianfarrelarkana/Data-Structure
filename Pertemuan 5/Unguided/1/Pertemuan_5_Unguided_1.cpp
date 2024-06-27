#include <iostream>
#include <vector>

using namespace std;

class Mahasiswa
{
public:
    string nim, nama;
    int nilai;
};

class HashTable
{
private:
    int size;
    vector<vector<Mahasiswa>> table;

public:
    HashTable(int s)
    {
        size = s;
        table.resize(size);
    }

    int hash(string nim)
    {
        int total = 0;
        for (char c : nim)
        {
            total += (int)c;
        }
        return total % size;
    }

    void tambah_data(string nim, string nama, int nilai)
    {
        int index = hash(nim);
        for (Mahasiswa m : table[index])
        {
            if (m.nim == nim)
            {
                cout << "\nData mahasiswa dengan NIM " << nim << " sudah ada di dalam tabel\n";
                return;
            }
        }
        Mahasiswa m;
        m.nim = nim;
        m.nama = nama;
        m.nilai = nilai;
        table[index].push_back(m);
        cout << "\nData mahasiswa dengan NIM " << nim << " berhasil ditambahkan\n";
    }

    void hapus_data(string nim)
    {
        int index = hash(nim);
        for (int i = 0; i < table[index].size(); i++)
        {
            if (table[index][i].nim == nim)
            {
                table[index].erase(table[index].begin() + i);
                cout << "\nData mahasiswa dengan NIM " << nim << " berhasil dihapus\n";
                return;
            }
        }
        cout << "\nData mahasiswa dengan NIM " << nim << " tidak ditemukan\n";
    }

    void cari_nim(string nim)
    {
        int index = hash(nim);
        for (Mahasiswa m : table[index])
        {
            if (m.nim == nim)
            {
                cout << "\nData mahasiswa dengan NIM " << nim << " :\n";
                cout << "Nama  : " << m.nama << endl;
                cout << "Nilai : " << m.nilai << endl;
                return;
            }
        }
        cout << "\nData mahasiswa dengan NIM " << nim << " tidak ditemukan\n";
    }

    void cari_nilai(int min, int max)
    {
        bool found = false;
        for (vector<Mahasiswa> v : table)
        {
            for (Mahasiswa m : v)
            {
                if (m.nilai >= min && m.nilai <= max)
                {
                    if (!found)
                    {
                        cout << "\nData mahasiswa dengan nilai di antara " << min << " dan " << max << " :\n";
                        found = true;
                    }
                    cout << "NIM   : " << m.nim << endl;
                    cout << "Nama  : " << m.nama << endl;
                    cout << "Nilai : " << m.nilai << endl;\
                    cout << endl;
                }
            }
        }
        if (!found)
        {
            cout << "\nTidak ada data mahasiswa dengan nilai di antara " << min << " dan " << max << endl;
        }
    }
};

int main()
{
    HashTable data_mhs(10);
    string nim, nama;
    int pilih, nilai, min, max;

    while (true)
    {
        cout << "\nMenu Data Mahasiswa :\n\n";
        cout << "1. Tambah data mahasiswa\n";
        cout << "2. Hapus data mahasiswa\n";
        cout << "3. Cari data mahasiswa berdasarkan NIM\n";
        cout << "4. Cari data mahasiswa berdasarkan rentang nilai\n";
        cout << "5. Keluar program\n\n";
        cout << "Masukkan pilihan anda : "; cin >> pilih;

        switch (pilih)
        {
        case 1:
            cout << "Masukkan NIM   : "; cin >> nim;
            cout << "Masukkan Nama  : "; cin >> nama;
            cout << "Masukkan Nilai : "; cin >> nilai;
            data_mhs.tambah_data(nim, nama, nilai);
            break;

        case 2:
            cout << "Masukkan NIM : ";
            cin >> nim;
            data_mhs.hapus_data(nim);
            break;

        case 3:
            cout << "Masukkan NIM: ";
            cin >> nim;
            data_mhs.cari_nim(nim);
            break;

        case 4:
            cout << "Masukkan batas nilai bawah (min) : "; cin >> min;
            cout << "Masukkan batas nilai atas (max)  : "; cin >> max;
            data_mhs.cari_nilai(min, max);
            break;

        case 5:
            return 0;

        default:
            cout << "Pilihan yang anda masukkan tidak tersedia\n";
        }
        cout << endl;
    }
    return 0;
}