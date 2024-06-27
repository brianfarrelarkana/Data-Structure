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
    char katkal[maks];

    cout << "\nProgram Membalikkan Kata atau Kalimat\n\n";
    cout << "Masukkan kata atau kalimat        : ";
    cin.getline(katkal, sizeof(katkal));

    for (int i = 0; katkal[i] != '\0'; i++){
        push(katkal[i]);
    }

    cout << "\nKata atau kalimat setelah dibalik : ";
    
    while (!isEmpty()){
        cout << pop();
    }

    return 0;
}