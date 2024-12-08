#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <list>
using namespace std;

int gen_hash_index(string s) {
    int sum=0;
    for ( char c : s) {
        sum += (int)c;
    }
    return sum;
}

int main() {
    ifstream file("lab-37-data.txt");
    if (!file) {
        cout << "Error open file" << endl;
        return 1;
    }

    // Create the std::map named hash_table. The key in the map is an int, the hash index. The value in a map is a std::list, which will contain the 12-character codes from the file that all map to that hash index.
    map<int, list<string>> hash_table;

    int total;
    string line;
    while(getline(file,line)) {
        // Receive its hash index that's returned from the function. Input that pair into the map (the hash index and the code string).
        int index = gen_hash_index(line);
        hash_table[index] = line; 
    }
    file.close();

    for ( int i = 0; i < 100; i++) {
        cout << "Index : " << hash_table.first << " code : ";
        for ( string code : entry.second) {
            cout << code << ", " ;
        }
    }
    return 0;
}

/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
