#include <iostream>
#include <string>
using namespace std;

int sum_ascii(string s) {
    int sum=0;
    int position = 1;
    for ( char c : s) {
        cout << position << ": " << (int)c << endl;
        sum += (int)c;
        position++;
    }
    cout << "sum of code " << s << ": " ;
    return sum;
}

int main() {
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
