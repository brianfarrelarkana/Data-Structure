#include <iostream>
#include <string>

using namespace std;

class manusia
{
	public:virtual void datadiri(string nama, string alamat) = 0;
	public: void sifat(){
		cout << "Sifat manusia itu adalah suka bekerja sama";
	}
};

class pekerjaan: public manusia{
	public:void datadiri(string n, string a){
		nama = n;
		alamat = a;
	}
	void kerja(string p);
	void display();

	private:string nama, alamat, profesi;
};

void pekerjaan::kerja(string p){
	profesi = p;
}

void pekerjaan::display(){
	cout << "Nama saya             : " << nama << endl;
	cout << "Tempat tinggal        : " << alamat << endl;
	cout << "Pekerjaan saya adalah : " << profesi << endl;
}

int main(int argc, char const *argv[])
{
	pekerjaan brian;
	string nama, alamat, profesi;

	cout << "Masukan data anda" << endl;
	cout << endl;
	cout << "Masukan nama anda      : ";
	getline(cin,nama);
	cout << "Masukan alamat anda    : ";
	getline(cin,alamat);
	cout << "Masukan pekerjaan anda : ";
	getline(cin,profesi);

	cout << endl;
	brian.datadiri(nama,alamat);
	brian.kerja(profesi);
	brian.display();
	brian.sifat();

	return 0;
}