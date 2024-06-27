#include <iostream>

using namespace std;

class pajak
{
public:
	pajak();
	~pajak();
	void setgaji(int g);
	void display();

private:
	int gaji;
	double pajakmu;
	double getpajak();
};

pajak::pajak(){
	//menjalankan konstruktor
	cout << "Mulai" << endl;
}

pajak::~pajak(){
	//menjalankan destruktor
	cout << "Selesai" << endl;
}

//penggunakan enkapsulasi
void pajak::setgaji(int g){
	gaji = g;
}
//contoh program penggunakan enkapsulasi
double pajak::getpajak(){
	double total;

	if (gaji > 2000000)
	{
		total = gaji * 0.15;
	}else{
		total = 50000;
	}

	return total;
}

void pajak::display(){
	pajakmu = getpajak();
	cout << "Pajak yang anda bayar adalah : " << pajakmu << endl;
}


int main(int argc, char const *argv[])
{
	pajak brian;
	int gaji;
	cout << "Program untuk menghitung nilai pajak" << endl;
	cout << endl;

	cout << "Masukan jumlah gaji yang anda terima : ";
	cin >> gaji;

	brian.setgaji(gaji);
	brian.display();

	return 0;
}