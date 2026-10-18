
#include "functions.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void readFile(const filesystem::path& filePath) {
    ifstream file(filePath);

    if (!file.is_open()) {
        cerr << "Error: Could not open "
             << filePath.string() << '\n';
        return;
    }

    string line;
    int lineNumber = 1;

    while (getline(file, line)) {
        cout << lineNumber << ": " << line << '\n';
        lineNumber++;
    }
}
