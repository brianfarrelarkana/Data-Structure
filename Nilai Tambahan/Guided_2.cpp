//contoh program penggunaan konstruktor & destruktor
#include <iostream>

using namespace std;

class Mahasiswa
{
public:
	Mahasiswa(string x, double y); /// konstruktor
	~Mahasiswa(); /// destruktor
	void display();

private:
	string nama;
	double ipk;
};

void Mahasiswa::display(){
	cout << "Nama anda adalah : " << nama << endl;
	cout << "IPK anda adalah  : " << ipk << endl;
}

Mahasiswa::Mahasiswa(string x, double y){
	cout << "Object dibuat dan konstruktor dijalankan" << endl;
	cout << endl;
	nama = x;
	ipk = y;
}

Mahasiswa::~Mahasiswa(){
	cout << "Object dihancurkan dan destruktor dijalankan" << endl;
	cout << endl;
}

int main(int argc, char const *argv[])
{
	Mahasiswa brian("Brian", 4);
	brian.display();
	return 0;
}