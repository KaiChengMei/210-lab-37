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

void display100(map<int, list<string>> hash_table) {
    int i = 1;
    for ( auto a : hash_table) {
        if (i > 100) { break; }
        cout << "Index : " << a.first << " Code : ";
        for ( string code : a.second) {
            cout << code << ", " ;
        }
        cout << endl;
        i++;
    }
}

void search(map<int, list<string>> hash_table) {
    int key;
    cout << "Key to search: ";
    cin >> key;
    for (auto a : hash_table) {
        if (a.first == key) {
            cout << "Key: " << key << " Code: ";
            for ( string code : a.second) {
                cout << code << ", ";
            }
            cout << endl;
            return;
        }
    }
    cout << "Key not found" << endl;
}

void add(map<int, list<string>> hash_table) {
    string code;
    cout << "Code to add: ";
    cin >> code;

    hash_table[gen_hash_index(code)].push_back(code);
    cout << "Code added." << endl;
}

// remove key not code
void remove(map<int, list<string>> hash_table) {
    int key;
    cout << "Key to remove: ";
    cin >> key;
    if (hash_table.erase(key)) {
        hash_table.erase(key);
        cout << "Key removed." << endl;
    } else {
        cout << "Key not found." << endl;
    }

}

void modify(map<int, list<string>> hash_table) {
    int key;
    string newcode;
    cout << "Key to modify: ";
    cin >> key;
    cout << "New code to replace: ";
    cin >> newcode;

    for (auto a : hash_table) {
        if (a.first == key) {
            a.second.clear();
            a.second.push_back(newcode);
            cout << "Code modified." << endl;
            return;
        }
    }
    cout << "Key not found." << endl;
}

int main() {
    ifstream file("lab-37-data.txt");
    if (!file) {
        cout << "Error open file" << endl;
        return 1;
    }

    // Create the std::map named hash_table. The key in the map is an int, the hash index. The value in a map is a std::list, which will contain the 12-character codes from the file that all map to that hash index.
    map<int, list<string>> hash_table;

    string line;
    while(getline(file,line)) {
        // Receive its hash index that's returned from the function. Input that pair into the map (the hash index and the code string).
        int index = gen_hash_index(line);
        // list! need to use push back
        hash_table[index].push_back(line); 
    }
    file.close();

    int choice;
    do {
        cout << "Menu" << endl;
        cout << "[1] print the first 100 entries" << endl;
        cout << "[2] search for a key" << endl;
        cout << "[3] add a key" << endl;
        cout << "[4] remove a key" << endl;
        cout << "[5] modify a key" << endl;
        cout << "[6] exit" << endl;
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1:
                display100(hash_table);
                break;
            case 2:
                search(hash_table);
                break;
            case 3:
                add(hash_table);
                break;
            case 4:
                remove(hash_table);
                break;
            case 5:
            case 6:
                cout << "exiting...." << endl;
                break;
            default:
                cout << "Enter 1~6" << endl;

        }
    } while ( choice != 6);

    return 0;
}

/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
