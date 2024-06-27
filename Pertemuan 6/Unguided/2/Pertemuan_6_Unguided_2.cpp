#include <iostream>

using namespace std;

char katkal[20];
int maks = 20, top = -1;

bool isFull(){
    if (top == maks - 1){
        return true;
    }else{
        return false;
    }
}

bool isEmpty(){
    if (top == -1){
        return true;
    }else{
        return false;
    }
}

void push(char data){
    katkal[top] = data;
    top++;
}

char pop(){
    char reverse;
    if (isEmpty()){
        cout << endl;
    }else{
        reverse = katkal[top - 1];
        top--;
    }
    return reverse;
}

int main()
{
    top = -1;
    bool palindrom = true;
    char katkal[maks];

    cout << "\nProgram Cek Kata atau Kalimat Palindrom\n\n";
    cout << "Masukkan kata atau kalimat : ";
    cin.getline(katkal, sizeof(katkal));

    for (int i = 0; katkal[i] != '\0'; i++){
        push(katkal[i]);
    }

    for (int i = 0; katkal[i] != '\0'; i++){
        if (katkal[i] != pop()){
            palindrom = false;
        }
    }

    if (palindrom){
        cout << "Kata atau kalimat yang dimasukkan merupakan polindrom\n";
    } else {
        cout << "Kata atau kalimat yang dimasukkan bukan merupakan polindrom\n";
    }
    
    return 0;
}