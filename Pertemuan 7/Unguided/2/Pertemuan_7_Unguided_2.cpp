#include <iostream>

using namespace std;

struct queue{
    string nama, nim;
    queue *next;
};

int maks = 5;
queue *head, *tail, *cur, *del, *newNode;

int countQueue(){
    if (head == NULL){
        return 0;
    }else{
        int jumlah = 0;
        cur = head;
        while (cur != NULL){
            cur = cur->next;
            jumlah++;
        } return jumlah;
    }
}

bool isEmpty(){
    if (countQueue() == 0){
        return true;
    }else{
        return false;
    }
}

bool isFull(){
    if (countQueue() == maks){
        return true;
    }else{
        return false;
    }
}

void enqueueAntrian(string nama, string nim){
    if (isFull()){
        cout << "\nAntrian Penuh\n";
    }else{
        if(isEmpty()){
            head = new queue();
            head->nama = nama;
            head->nim = nim;
            head->next = NULL;
            tail = head;
        }else{
            newNode = new queue();
            newNode->nama = nama;
            newNode->nim = nim;
            newNode->next = NULL;
            tail->next = newNode;
            tail = newNode;
        }
    }
}

void dequeueAntrian(){
    if(isEmpty()){
        cout << "\nAntrian Kosong\n";
    }else{
        del = head;
        head = head->next;
        del->next = NULL;
        delete del;
        cout << "\nData telah dihapus\n";
    }
}

void clearQueue(){
    if (isEmpty()){
        cout << "\nAntrian Kosong\n";
    }else{
        cur = head;
        while (cur != NULL){
            del = cur;
            cur = cur->next;
            del->next = NULL;
            delete del;
        }
        head = NULL;
        tail = NULL;
        cout << "\nData berhasil di reset\n";
    }
}

void viewQueue(){
    if (isEmpty()){
        cout << "\nAntrian Kosong";
    }else{
        cout << "\nData Antrian :\n\n";
        cout << "Nama Mahasiswa\tNIM\n";
        cur = head;
        int nomor = 1;
        while (nomor <= maks){
            if (cur != NULL){
                cout << cur->nama << "\t\t" << cur->nim << endl;
                cur = cur->next;
            } nomor++;
        } cout << "\nBanyak antrian : " << countQueue() << endl;
    }
}

int main(){
    int pilih;
    string nama, nim;

    while (true){
        cout << "Data Antrian Mahasiswa\n\n";
        cout << "1. Masukkan data\n";
        cout << "2. Hapus satu data\n";
        cout << "3. Reset data\n";
        cout << "4. Tampilkan data\n";
        cout << "5. Keluar\n";
        cout << "\nMasukkan pilihan anda : "; cin >> pilih;

        switch (pilih){
            case 1 :
            cout << "\nMasukkan nama mahasiswa : "; cin >> nama;
            cout << "Masukkan NIM mahasiswa  : "; cin >> nim;
            enqueueAntrian(nama, nim);
            break;

            case 2:
            dequeueAntrian();
            break;

            case 3:
            clearQueue();
            break;

            case 4:
            viewQueue();
            break;

            case 5 :
            return 0;

            default:
            cout << "\nPilihan yang anda masukkan tidak tersedia\n";
        }
        cout << "\n" << endl;
    }
    return 0;
}