#include <iostream>
#include <fstream>
#include <map>
#include <list>
using namespace std;

int gen_hash_index(string &s) {
    int sum = 0;
    for (char c : s) {
        sum += (int)c;
    }
    return sum % 97;
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
        cout << "Hash index: " << gen_hash_index(test_string) << endl;
    }
    
    ifstream inFile("lab-37-data.txt");
    if (!inFile) {
        cerr << "file not opened" << endl;
        return 1;
    }

    // int grand_total = 0;
    // while (getline(inFile, record)) {
    //     int record_sum = sum_ascii(record);
    //     grand_total += record_sum;
    // }
    // cout << "Grand total of ASCII sum: " << grand_total << endl;

    map<int, list<string>> hash_table;
    
    string record;
    while (getline(inFile, record)) {
        int hash_index = gen_hash_index(record);
        hash_table[hash_index].push_back(record);
    }

    





    inFile.close();

    return 0;
}
/*
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
