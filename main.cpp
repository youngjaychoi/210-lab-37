#include <iostream>
#include <fstream>
using namespace std;

int sum_ascii(string &s) {
    int sum = 0;
    for (char c : s) {
        sum += (int)c;
    }
    return sum;
}

int main()
{
    char a = 'A';
    cout << a << endl;
    cout << (int)a << endl;

    int b = 66;
    cout << b << endl;
    cout << (char)b << endl;

    string test_targets[] = {"536B9DFC93AF", "1DA9D64D02A0", "666D109AA22E", "E1D2665B21EA"};
    for (string test_string : test_targets) {
        cout << "Test string: " << test_string << endl;
        cout << "Sum of ASCII values: " << sum_ascii(test_string) << endl;
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
