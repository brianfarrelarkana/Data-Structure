//contoh program penggunakan kelas & object
#include <iostream>

using namespace std;

class DataDiri
{
public:
	void setNama(string x);
	void setAlamat(string x);
	void display();

private:
	string nama,alamat;
};

void DataDiri::setNama(string x){
	nama=x;
}

void DataDiri::setAlamat(string x){
	alamat=x;
}

void DataDiri::display(){
	cout << "Data diri yang anda inputkan :" << endl;
	cout << "Nama   : " << nama <<endl;
	cout << "Alamat : " << alamat <<endl;
	cout << endl;
}

int main(int argc, char const *argv[])
{
	// deklarasi object cara pertama
	DataDiri brian;
	string x;

	// akses object cara pertama
	cout << "Masukan Nama : ";
	getline(cin,x);
	brian.setNama(x);

	cout << "Masukan Alamat : ";
	getline(cin,x);
	brian.setAlamat(x);

	cout << endl;
	brian.display();

	// deklarasi object cara kedua
	DataDiri *farrel = new DataDiri();

	// akses object cara kedua
	cout << "Masukan Nama : ";
	getline(cin,x);
	farrel->setNama(x);

	cout << "Masukan Alamat : ";
	getline(cin,x);
	farrel->setAlamat(x);

	cout << endl;
	farrel->display();

	return 0;
}