#include <iostream>

using namespace std;

class HashTable {
private:
    static const int TABLE_SIZE2211102352 = 30;
    string table2211102352[TABLE_SIZE2211102352];

    int hashFunction(const char* key221112352) {
        int sum2211102352 = 0;
        const char* c2211102352 = key221112352;
        while (*c2211102352) {
            sum2211102352 += static_cast<int>(*c2211102352);
            ++c2211102352;
        }
        return sum2211102352 % TABLE_SIZE2211102352;
    }

public:
    void insert(const char* key221112352) {
        int index2211102352 = hashFunction(key221112352);
        if (table2211102352[index2211102352].empty()) {
            table2211102352[index2211102352] = key221112352;
        } else {
            int newIndex2211102352 = (index2211102352 + 1) % TABLE_SIZE2211102352;
            while (!table2211102352[newIndex2211102352].empty()) {
                newIndex2211102352 = (newIndex2211102352 + 1) % TABLE_SIZE2211102352;
            }
            table2211102352[newIndex2211102352] = key221112352;
        }
    }

    void displayIndex(const char* key221112352) {
        int index2211102352 = hashFunction(key221112352);
        if (table2211102352[index2211102352] == key221112352) {
            cout << key221112352 << " terdapat pada index ke-" << index2211102352 << endl;
        }
    }
};

int main()
{
    HashTable hashTable;

    hashTable.insert("AJOJING");
    hashTable.insert("CHARLIE");

    hashTable.displayIndex("AJOJING");
    hashTable.displayIndex("CHARLIE");

    return 0;
}