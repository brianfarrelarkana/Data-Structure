//contoh program penggunaan inheritance
#include <iostream>

using namespace std;

class mahlukhidup
{
protected:
	string nama, sifat;

public:
	void setmahluk(string n, string s){
		nama = n;
		sifat = s;
	}
};

// kelas hewan merupakan turunan dari kelas mahlukhidup
class hewan: public mahlukhidup{
public:
	void hewanku(){
		cout << "Nama Hewan      : " << nama << endl;
		cout << "Merupakan Hewan : " << sifat << endl;
	}
};

// kelas tumbuhan merupakan turunan dari kelas mahlukhidup
class tumbuhan: public mahlukhidup{
public:
	void tumbuhanku(){
		cout << "Nama Tumbuhan      : " << nama << endl;
		cout << "Merupakan Tumbuhan : " << sifat << endl;
	}
};

int main(int argc, char const *argv[])
{
	cout << "Contoh Inheritance" << endl;
	cout << endl;
	tumbuhan a;
	a.setmahluk("Apel", "Dikotil");
	a.tumbuhanku();
	cout << endl;

	hewan b;
	b.setmahluk("Monyet", "Mamalia Omnivora");
	b.hewanku();
	cout << endl;

	return 0;
}