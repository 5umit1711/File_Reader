
#include "functions.h"

#include <cctype>
#include <fstream>
#include <iostream>

using namespace std;

InvertedIndex buildIndex(
    const vector<filesystem::path>& files
) {
    InvertedIndex index;

    for (const auto& filePath : files) {
        ifstream file(filePath);

        if (!file.is_open()) {
            cerr << "Warning: Cannot open "
                 << filePath.string() << '\n';
            continue;
        }

        string line;
        size_t lineNumber = 0;

        while (getline(file, line)) {
            ++lineNumber;
            string word;

            auto storeWord = [&]() {
                if (!word.empty()) {
                    index[word].push_back({
                        filePath,
                        lineNumber,
                        line
                    });
                    word.clear();
                }
            };

            for (unsigned char ch : line) {
                if (isalnum(ch) || ch == '_') {
                    word += static_cast<char>(tolower(ch));
                } else {
                    storeWord();
                }
            }

            storeWord();
        }

        if (file.bad()) {
            cerr << "Warning: Error reading "
                 << filePath.string() << '\n';
        }
    }

    return index;
}

void searchIndex(
    const InvertedIndex& index,
    const string& query
) {
    string normalizedQuery;

    for (unsigned char ch : query) {
        if (isalnum(ch) || ch == '_') {
            normalizedQuery += static_cast<char>(tolower(ch));
        } else {
            cerr << "Error: Search only supports a single word "
                    "containing letters, digits, or underscores.\n";
            return;
        }
    }

    if (normalizedQuery.empty()) {
        cerr << "Error: Search query cannot be empty.\n";
        return;
    }

    auto it = index.find(normalizedQuery);

    cout << "Search query: " << query << '\n';

    if (it == index.end()) {
        cout << "No matches found.\n";
        return;
    }

    const auto& occurrences = it->second;
    filesystem::path currentFile;
    bool firstFile = true;

    for (const auto& occurrence : occurrences) {
        if (firstFile || occurrence.filePath != currentFile) {
            currentFile = occurrence.filePath;
            firstFile = false;

            cout << "\nFile: " << currentFile.string() << '\n';
            cout << "----------------------------------------\n";
        }

        cout << "Line " << occurrence.lineNumber
             << ": " << occurrence.lineText << '\n';
    }

    cout << "\nMatching occurrences: "
         << occurrences.size() << '\n';
}
