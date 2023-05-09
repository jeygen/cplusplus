#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string filename = "parse_me.txt";
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }

    string line;
    while (getline(file, line)) {
        // do something with each line
        cout << line << endl;
    }

    file.close();
    return 0;
}

