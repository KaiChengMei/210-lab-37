#include <iostream>
#include <string>
using namespace std;

void sum_ascii(string s) {
    int sum=0;
    for ( char c : s) {
        cout << (int)c << endl;
        sum += (int)c;
    }
    return sum;
}

int main() {
    cout << sum_ascii("536B9DFC93AF");
    

    return 0;
}

/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
