#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

char simpul[9] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};

int boardNewbie[9][9] = {
    {0, 0, 4, 5, 1, 2, 3, 6, 0},
    {2, 7, 5, 0, 0, 0, 0, 0, 0},
    {0, 3, 6, 0, 7, 8, 0, 9, 5},
    {9, 2, 8, 7, 3, 0, 0, 0, 0},
    {0, 0, 7, 1, 8, 5, 0, 2, 9},
    {5, 4, 0, 0, 9, 0, 8, 7, 3},
    {7, 1, 0, 0, 4, 9, 0, 0, 6},
    {6, 5, 0, 3, 2, 0, 7, 8, 0},
    {4, 8, 0, 6, 5, 0, 9, 1, 2}
};

int solvedNewbie[9][9] = {
    {8, 9, 4, 5, 1, 2, 3, 6, 7},
    {2, 7, 5, 9, 6, 3, 1, 4, 8},
    {1, 3, 6, 4, 7, 8, 2, 9, 5},
    {9, 2, 8, 7, 3, 4, 6, 5, 1},
    {3, 6, 7, 1, 8, 5, 4, 2, 9},
    {5, 4, 1, 2, 9, 6, 8, 7, 3},
    {7, 1, 2, 8, 4, 9, 5, 3, 6},
    {6, 5, 9, 3, 2, 1, 7, 8, 4},
    {4, 8, 3, 6, 5, 7, 9, 1, 2}
};

int boardSepuh[9][9] = {
    {0, 0, 0, 4, 0, 0, 0, 9, 1},
    {0, 0, 7, 0, 0, 9, 0, 8, 6},
    {0, 0, 0, 7, 0, 0, 0, 0, 0},
    {0, 1, 0, 8, 7, 0, 0, 6, 0},
    {7, 9, 0, 0, 0, 0, 0, 2, 8},
    {0, 8, 0, 0, 2, 8, 0, 5, 0},
    {0, 0, 0, 0, 0, 7, 0, 0, 0},
    {8, 2, 0, 1, 0, 0, 9, 0, 0},
    {1, 7, 0, 0, 0, 6, 0, 0, 0}
};

int solvedSepuh[9][9] = {
    {5, 3, 8, 4, 6, 2, 7, 9, 1},
    {2, 4, 7, 3, 1, 9, 5, 8, 6},
    {9, 6, 1, 7, 5, 8, 2, 3, 4},
    {3, 1, 2, 8, 7, 5, 4, 6, 9},
    {7, 9, 5, 6, 4, 1, 3, 2, 8},
    {6, 8, 4, 9, 2, 3, 1, 5, 7},
    {4, 5, 9, 2, 8, 7, 6, 1, 3},
    {8, 2, 6, 1, 3, 4, 9, 7, 5},
    {1, 7, 3, 5, 9, 6, 8, 4, 2}  
};

bool isBoardEqual(int board[9][9], int solved[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] != solved[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void levelNewbie()
{
    int salah = 0;
    int angka;
    char kolom, baris, k, b;

    boardNewbie[0][0] = 0;
    boardNewbie[0][1] = 0;
    boardNewbie[0][8] = 0;
    boardNewbie[1][3] = 0;
    boardNewbie[1][4] = 0;
    boardNewbie[1][5] = 0;
    boardNewbie[1][6] = 0;
    boardNewbie[1][7] = 0;
    boardNewbie[1][8] = 0;
    boardNewbie[2][0] = 0;
    boardNewbie[2][3] = 0;
    boardNewbie[2][6] = 0;
    boardNewbie[3][5] = 0;
    boardNewbie[3][6] = 0;
    boardNewbie[3][7] = 0;
    boardNewbie[3][8] = 0;
    boardNewbie[4][0] = 0;
    boardNewbie[4][1] = 0;
    boardNewbie[4][6] = 0;
    boardNewbie[5][2] = 0;
    boardNewbie[5][3] = 0;
    boardNewbie[5][5] = 0;
    boardNewbie[6][2] = 0;
    boardNewbie[6][3] = 0;
    boardNewbie[6][6] = 0;
    boardNewbie[6][7] = 0;
    boardNewbie[7][2] = 0;
    boardNewbie[7][5] = 0;
    boardNewbie[7][8] = 0;
    boardNewbie[8][2] = 0;
    boardNewbie[8][5] = 0;

    while (salah < 3 && !isBoardEqual(boardNewbie, solvedNewbie))
    {
        cout << "\n       Kesalahan : " << salah << "/3";
        cout << "\n\n   ";
        for (int i = 0; i < 9; i++)
        { if (i == 3 || i == 6)
            cout << "  ";
            cout << " " << simpul[i];
        }
        cout << "\n\n";
        for (int i = 0; i < 9; i++)
        {
            cout << simpul [i] << "  ";
            for (int j = 0; j < 9; j++)
            { if (j == 3 || j == 6)
                cout << " |";
                if (boardNewbie[i][j] == 0)
                cout << "  ";
                else 
                cout << " " << boardNewbie[i][j];
            } if (i == 2 || i == 5){
                cout << "\n    ";
                for (int i = 1; i < 8; i++)
                cout << "---";
            }
            cout << endl;
        }
        cout << endl;

        cout << "Masukkan koordinat angka yang ingin di isi (contoh : aa)\n";
        cout << "Abjad Samping, Abjad Atas (Baris, Kolom) : "; cin >> kolom; cin >> baris;

        k = kolom;
        b = baris;

        if (kolom == 'A' || kolom == 'a'){
            kolom = 0;
        } else if (kolom == 'B' || kolom == 'b'){
            kolom = 1;
        } else if (kolom == 'C' || kolom == 'c'){
            kolom = 2;
        } else if (kolom == 'D' || kolom == 'd'){
            kolom = 3;
        } else if (kolom == 'E' || kolom == 'e'){
            kolom = 4;
        } else if (kolom == 'F' || kolom == 'f'){
            kolom = 5;
        } else if (kolom == 'G' || kolom == 'g'){
            kolom = 6;
        } else if (kolom == 'H' || kolom == 'h'){
            kolom = 7;
        } else if (kolom == 'I' || kolom == 'i'){
            kolom = 8;
        } else {
            cout << "\nAbjad yang anda maukkan salah atau tidak tersedia!\n";
        }

        if (baris == 'A' || baris == 'a'){
            baris = 0;
        } else if (baris == 'B' || baris == 'b'){
            baris = 1;
        } else if (baris == 'C' || baris == 'c'){
            baris = 2;
        } else if (baris == 'D' || baris == 'd'){
            baris = 3;
        } else if (baris == 'E' || baris == 'e'){
            baris = 4;
        } else if (baris == 'F' || baris == 'f'){
            baris = 5;
        } else if (baris == 'G' || baris == 'g'){
            baris = 6;
        } else if (baris == 'H' || baris == 'h'){
            baris = 7;
        } else if (baris == 'I' || baris == 'i'){
            baris = 8;
        } else {
            cout << "\nAbjad yang anda maukkan salah atau tidak tersedia!\n";
        }

        if (boardNewbie[kolom][baris] != 0){
            cout << "\nKoordinat telah terisi!\n";
        } else if (boardNewbie[kolom][baris] == 0) {
        cout << "\nMasukkan angka :\n";
        cout << k << " -> " << b << " = "; cin >> angka;
        boardNewbie[kolom][baris] = angka;

        if (solvedNewbie[kolom][baris] != angka){
            cout << "\n\n\nJawaban anda salah!\n\n\n";
            boardNewbie[kolom][baris] = 0;
            salah++;
        }
        }
    }
    if (salah == 3){
        cout << "\n\n\nNice Try :)\n\n\n\n\n\n";
    } else if (isBoardEqual(boardNewbie, solvedNewbie)){
        cout << "\n\n\nCongrats kamu berhasil menyelesaikan level ini!\n\n\n\n\n\n";
    }
}

void levelSepuh()
{
    int salah = 0;
    int angka;
    char kolom, baris, k, b;

    boardSepuh[0][0] = 0;
    boardSepuh[0][1] = 0;
    boardSepuh[0][2] = 0;
    boardSepuh[0][4] = 0;
    boardSepuh[0][5] = 0;
    boardSepuh[0][6] = 0;
    boardSepuh[1][0] = 0;
    boardSepuh[1][1] = 0;
    boardSepuh[1][3] = 0;
    boardSepuh[1][4] = 0;
    boardSepuh[1][6] = 0;
    boardSepuh[2][0] = 0;
    boardSepuh[2][1] = 0;
    boardSepuh[2][2] = 0;
    boardSepuh[2][4] = 0;
    boardSepuh[2][5] = 0;
    boardSepuh[2][6] = 0;
    boardSepuh[2][7] = 0;
    boardSepuh[2][8] = 0;
    boardSepuh[3][0] = 0;
    boardSepuh[3][2] = 0;
    boardSepuh[3][5] = 0;
    boardSepuh[3][6] = 0;
    boardSepuh[3][9] = 0;
    boardSepuh[4][2] = 0;
    boardSepuh[4][3] = 0;
    boardSepuh[4][4] = 0;
    boardSepuh[4][5] = 0;
    boardSepuh[4][6] = 0;
    boardSepuh[5][0] = 0;
    boardSepuh[5][2] = 0;
    boardSepuh[5][3] = 0;
    boardSepuh[5][6] = 0;
    boardSepuh[5][8] = 0;
    boardSepuh[6][0] = 0;
    boardSepuh[6][1] = 0;
    boardSepuh[6][2] = 0;
    boardSepuh[6][3] = 0;
    boardSepuh[6][4] = 0;
    boardSepuh[6][6] = 0;
    boardSepuh[6][7] = 0;
    boardSepuh[6][8] = 0;
    boardSepuh[7][2] = 0;
    boardSepuh[7][4] = 0;
    boardSepuh[7][5] = 0;
    boardSepuh[7][7] = 0;
    boardSepuh[7][8] = 0;
    boardSepuh[8][2] = 0;
    boardSepuh[8][3] = 0;
    boardSepuh[8][4] = 0;
    boardSepuh[8][6] = 0;
    boardSepuh[8][7] = 0;
    boardSepuh[8][8] = 0;

    while (salah < 3 && !isBoardEqual(boardSepuh, solvedSepuh))
    {
        cout << "\n       Kesalahan : " << salah << "/3";
        cout << "\n\n   ";
        for (int i = 0; i < 9; i++)
        { if (i == 3 || i == 6)
            cout << "  ";
            cout << " " << simpul[i];
        }
        cout << "\n\n";
        for (int i = 0; i < 9; i++)
        {
            cout << simpul [i] << "  ";
            for (int j = 0; j < 9; j++)
            { if (j == 3 || j == 6)
                cout << " |";
                if (boardSepuh[i][j] == 0)
                cout << "  ";
                else 
                cout << " " << boardSepuh[i][j];
            } if (i == 2 || i == 5){
                cout << "\n    ";
                for (int i = 1; i < 8; i++)
                cout << "---";
            }
            cout << endl;
        }
        cout << endl;

        cout << "Masukkan koordinat angka yang ingin di isi (contoh : aa)\n";
        cout << "Abjad Samping, Abjad Atas (Baris, Kolom) : "; cin >> kolom; cin >> baris;

        k = kolom;
        b = baris;

        if (kolom == 'A' || kolom == 'a'){
            kolom = 0;
        } else if (kolom == 'B' || kolom == 'b'){
            kolom = 1;
        } else if (kolom == 'C' || kolom == 'c'){
            kolom = 2;
        } else if (kolom == 'D' || kolom == 'd'){
            kolom = 3;
        } else if (kolom == 'E' || kolom == 'e'){
            kolom = 4;
        } else if (kolom == 'F' || kolom == 'f'){
            kolom = 5;
        } else if (kolom == 'G' || kolom == 'g'){
            kolom = 6;
        } else if (kolom == 'H' || kolom == 'h'){
            kolom = 7;
        } else if (kolom == 'I' || kolom == 'i'){
            kolom = 8;
        } else {
            cout << "\nAbjad yang anda maukkan salah atau tidak tersedia!\n";
        }

        if (baris == 'A' || baris == 'a'){
            baris = 0;
        } else if (baris == 'B' || baris == 'b'){
            baris = 1;
        } else if (baris == 'C' || baris == 'c'){
            baris = 2;
        } else if (baris == 'D' || baris == 'd'){
            baris = 3;
        } else if (baris == 'E' || baris == 'e'){
            baris = 4;
        } else if (baris == 'F' || baris == 'f'){
            baris = 5;
        } else if (baris == 'G' || baris == 'g'){
            baris = 6;
        } else if (baris == 'H' || baris == 'h'){
            baris = 7;
        } else if (baris == 'I' || baris == 'i'){
            baris = 8;
        } else {
            cout << "\nAbjad yang anda maukkan salah atau tidak tersedia!\n";
        }

        if (boardSepuh[kolom][baris] != 0){
            cout << "\nKoordinat telah terisi!\n";
        } else if (boardSepuh[kolom][baris] == 0){
        cout << "\nMasukkan angka :\n";
        cout << kolom << " -> " << baris << " = "; cin >> angka;
        boardSepuh[kolom][baris] = angka;
        
        if (solvedSepuh[kolom][baris] != angka){
            cout << "\n\n\nJawaban anda salah!\n\n\n";
            boardSepuh[kolom][baris] = 0;
            salah++;
        }
        }
    }
    if (salah == 3){
        cout << "\n\n\nNice Try :)\n\n\n\n\n\n";
    } else if (isBoardEqual(boardSepuh, solvedSepuh)){
        cout << "\n\n\nCongrats kamu berhasil menyelesaikan level ini!\n\n\n\n\n\n";
    }
}

int mainMenu()
{
    int pilihan;
    cout << "============= Sudoku =============\n";
    cout << "1. Play\n";
    cout << "2. Credit\n";
    cout << "3. Quit\n";
    cout << "Masukkan pilihan anda : "; cin >> pilihan;
    cout << endl;
    return pilihan;
}

void credit()
{
    cout << "Dibuat Oleh :\n";
    cout << "1. Arya Hadi Pratama		(2211102329)\n";
    cout << "2. Nabil Helmy Asshidiqi	(2211102335)\n";
    cout << "3. Putra Bhanu Anggoro		(2211102338)\n";
    cout << "4. Regina Permatasari		(2211102345)\n";
    cout << "5. Nasrulloh Yuli Nugroho	(2211102348)\n";
    cout << "6. Brian Farrel Arkana		(2211102352)\n\n\n";
}

int pilihLevel()
{
    int level;
    cout << "============= Sudoku =============\n";
    cout << "1. Newbie\n";
    cout << "2. Sepuh\n";
    cout << "Pilih level yang akan dimainkan : "; cin >> level;
    cout << endl;
    return level;
}

int main()
{
    while (true)
    {
        int pilihan = mainMenu();
        switch (pilihan)
        {
            case 1:
            {
            int level = pilihLevel();
            if (level == 1)
            {
                levelNewbie();
            }
            else if (level == 2)
            {
                levelSepuh();
            }
            break;
            };

            case 2:
            credit();
            break;

            case 3:
            cout << "Terimakasih telah bermain sudoku!\n";
            return 0;

            default:
            cout << "Pilihan yang anda masukkan salah. Silahkan coba lagi!\n\n\n";
        }
    }
    return 0;
}