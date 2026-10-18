
#include "functions.h"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int searchFiles(const filesystem::path& filePath, const string& query) {
    ifstream file(filePath);

    if (!file.is_open()) {
        cerr << "Error opening file: "
             << filePath.string() << '\n';
        return 0;
    }

    string line;
    int lineNumber = 0;
    int matches = 0;
    bool headingPrinted = false;

    while (getline(file, line)) {
        lineNumber++;

        if (line.find(query) != string::npos) {

            if (!headingPrinted) {
                cout << "\nFile: " << filePath.string() << '\n';
                cout << "----------------------------------------\n";
                headingPrinted = true;
            }

            cout << "Line " << lineNumber << ": "
                 << line << '\n';

            matches++;
        }
    }

    return matches;
}
