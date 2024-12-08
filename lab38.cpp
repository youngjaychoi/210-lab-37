#include <iostream>
#include <fstream>
#include <map>
#include <list>
using namespace std;

int gen_hash_index(string &s);
void print_100(map<int, list<string>> &hash_table);
void search_key(map<int, list<string>> &hash_table, int key);
void add_key(map<int, list<string>> &hash_table, string &code);
void remove_key(map<int, list<string>> &hash_table, int key);
void modify_key(map<int, list<string>> &hash_table, int old_key, int new_key);

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

    map<int, list<string>> hash_table;
    
    string record;
    while (getline(inFile, record)) {
        int hash_index = gen_hash_index(record);
        hash_table[hash_index].push_back(record);
    }

    inFile.close();

    int choice = 0;
    do {
        cout << "\nMenu:" << endl;
        cout << "1. Print the first 100 entries" << endl;
        cout << "2. Search for a key" << endl;
        cout << "3. Add a key" << endl;
        cout << "4. Remove a key" << endl;
        cout << "5. Modify a key" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
    }





    return 0;
}

int gen_hash_index(string &s) {
    int sum = 0;
    for (char c : s) {
        sum += (int)c;
    }
    return sum % 97;
}

void print_100(map<int, list<string>> &hash_table) {
    int count = 0;
    for (auto &entry : hash_table) {
        if (count >= 100)
            break;
        cout << "Hash Index: " << entry.first << " / Codes: ";
        int countS = 0;
        for (string &code : entry.second) {
            if (countS >= 10)                       // I add 10 limit display of codes per index for convenience.
                break;
            cout << code << " ";
            countS++;
        }
        cout << endl;
        count++;
    }
}

void search_key(map<int, list<string>> &hash_table, int key) {
    auto it = hash_table.find(key);
    if (it != hash_table.end()) {
        cout << "Hash Index: " << key << " / Codes: ";
        for (string &code : it->second) {
            cout << code << " ";
        }
        cout << endl;
    } else {
        cout << "Key not found" << endl;
    }
}

void add_key(map<int, list<string>> &hash_table, string &code) {
    int hash_index = gen_hash_index(code);
    hash_table[hash_index].push_back(code);
    cout << code << " added to " << hash_index << endl;
}

void remove_key(map<int, list<string>> &hash_table, int key) {
    
}

void modify_key(map<int, list<string>> &hash_table, int old_key, int new_key) {

}
