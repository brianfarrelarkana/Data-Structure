#include <iostream>

using namespace std;

class Mahasiswa352 {
    public:
        string nama352;
        int nim352;
        float ipk352;
};

struct player352 {
    string nickname352;
    int level352;
    float score352;
};

int main(){
    
    Mahasiswa352 bio1_352, bio2_352, bio3_352;

    bio1_352.nama352 = "Brian Farrel Arkana";
    bio1_352.nim352 = 352;
    bio1_352.ipk352 = 4.0;

    bio2_352.nama352 = "Bedjo Sudarsono";
    bio2_352.nim352 = 333;
    bio2_352.ipk352 = 2.5;

    bio3_352.nama352 = "Bella Aurora";
    bio3_352.nim352 = 321;
    bio3_352.ipk352 = 3.25;

    cout << "\nClass\n\n";
    cout << "Nama Mahasiswa      : " << bio1_352.nama352 << endl;
    cout << "NIM Akhir Mahasiswa : " << bio1_352.nim352 << endl;
    cout << "IPK Mahasiswa       : " << bio1_352.ipk352 << endl;

    cout << "\nNama Mahasiswa      : " << bio2_352.nama352 << endl;
    cout << "NIM Akhir Mahasiswa : " << bio2_352.nim352 << endl;
    cout << "IPK Mahasiswa       : " << bio2_352.ipk352 << endl;

    cout << "\nNama Mahasiswa      : " << bio3_352.nama352 << endl;
    cout << "NIM Akhir Mahasiswa : " << bio3_352.nim352 << endl;
    cout << "IPK Mahasiswa       : " << bio3_352.ipk352 << endl;


    struct player352 player1_352, player2_352, player3_352;

    player1_352.nickname352 = "Gokyuzu Ust";
    player1_352.level352 = 100;
    player1_352.score352 = 10.5;

    player2_352.nickname352 = "Avci Nyx";
    player2_352.level352 = 50;
    player2_352.score352 = 5.5;

    player3_352.nickname352 = "candycane";
    player3_352.level352 = 25;
    player3_352.score352 = 3;

    cout << "\n\nStruct\n\n";
    cout << "Nickname : " << player1_352.nickname352 << endl;
    cout << "Level    : " << player1_352.level352 << endl;
    cout << "Score    : " << player1_352.score352 << endl;

    cout << "\nNickname : " << player2_352.nickname352 << endl;
    cout << "Level    : " << player2_352.level352 << endl;
    cout << "Score    : " << player2_352.score352 << endl;

    cout << "\nNickname : " << player3_352.nickname352 << endl;
    cout << "Level    : " << player3_352.level352 << endl;
    cout << "Score    : " << player3_352.score352 << endl;

    return 0;
}