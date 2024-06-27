#include <iostream>
#include <map>

using namespace std;

int main(){
    std::map<int, std::string>nama352;

    nama352[1] = "Agent 47";
    nama352[2] = "John Wick";
    nama352[3] = "Dominic Toretto";

    std::cout << "\nMost Wanted List :\n\n";
    std::cout << "1. " << nama352[1] << std::endl;
    std::cout << "2. " << nama352[2] << std::endl;
    std::cout << "3. " << nama352[3] << std::endl;
    std::cout << "\nJumlah Most Wanted : " << nama352.size() << std::endl;

    return 0;
}