
#include <iostream>
#include "functions.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: file_reader <search_word>\n";
        return 1;
    }

    string query = argv[1];

    if (query.empty()) {
        cerr << "Error: Search query cannot be empty.\n";
        return 1;
    }

    filesystem::path directory = "test_data";
    error_code ec;

    if (!filesystem::is_directory(directory, ec) || ec) {
        cerr << "Error: Invalid directory: "
             << directory.string() << '\n';
        return 1;
    }

    vector<filesystem::path> files = findFiles(directory);

    if (files.empty()) {
        cout << "No files found in the directory.\n";
        return 0;
    }

    InvertedIndex index = buildIndex(files);

    searchIndex(index, query);

    return 0;
}
