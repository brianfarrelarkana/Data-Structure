//contoh program penggunaan Polimorfisme
#include <iostream>
#include <string>

using namespace std;

// Base class
class Laki_laki{
  public:
    void profesi(){
    cout << "Saya adalah seorang laki-laki\n";
  }
};

// Derived class
class Bapak : public Laki_laki{
  public:
    void profesi(){
    cout << "Profesi saya adalah seorang : Bapak\n";
   }
};

// Derived class
class Suami : public Laki_laki{
  public:
    void profesi(){
    cout << "Profesi saya adalah seorang : Suami\n";
  }
};

int main(){
  Laki_laki laki_laki;
  Bapak bapak;
  Suami suami;

  laki_laki.profesi();
  bapak.profesi();
  suami.profesi();

  return 0;
}