#include <iostream>

using namespace std;

struct queue{
    string nama;
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

void enqueueAntrian(string nama){
    if (isFull()){
        cout << "Antrian Penuh\n";
    }else{
        if (isEmpty()){
            head = new queue();
            head->nama = nama;
            head->next = NULL;
            tail = head;
        }else{
            newNode = new queue();
            newNode->nama = nama;
            newNode->next = NULL;
            tail->next = newNode;
            tail = newNode;
        }
    }
}

void dequeueAntrian(){
    if (isEmpty()){
        cout << "Antrian kosong\n";
    }else{
        del = head;
        head = head->next;
        del->next = NULL;
        delete del;
    }
}

void clearQueue(){
    if (isEmpty()){
        cout << "Antrian kosong\n";
    }else{
        cur = head;
        while (cur != NULL)
        {
            del = cur;
            cur = cur->next;
            del->next = NULL;
            delete del;
        }
        head = NULL;
        tail = NULL;
    }
}

void viewQueue(){
    if (isEmpty()){
        cout << "Antrian kosong\n";
    }else{
        cout << "Data Antrian Teller :\n";
        cur = head;
        int nomor = 1;
        while (nomor <= maks){
            if (cur != NULL){
                cout << nomor << ". " << cur->nama << endl;
                cur = cur->next;
            }else{
                cout << nomor << ". " << "(kosong)\n";
            } nomor++;
        } cout << "Jumlah antrian : " << countQueue() << endl;
    } cout << endl;
}

int main()
{
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    dequeueAntrian();
    viewQueue();
    clearQueue();
    viewQueue();
    return 0;
}