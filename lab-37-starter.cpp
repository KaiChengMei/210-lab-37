#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int sum_ascii(string s) {
    int sum=0;
    for ( char c : s) {
        sum += (int)c;
    }
    return sum;
}

int main() {
    ifstream file("lab-37-data.txt");
    if (file) {
        cout << "Error open file" << endl;
        return 1;
    }

    int total;
    while() {
        total += 
    }

    cout << sum_ascii("536B9DFC93AF") << endl;
    cout << sum_ascii("1DA9D64D02A0") << endl;
    cout << sum_ascii("666D109AA22E") << endl;
    cout << sum_ascii("E1D2665B21EA") << endl;
    
    return 0;
}

/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
