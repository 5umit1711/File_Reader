
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <filesystem>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

struct Occurrence {
    filesystem::path filePath;
    size_t lineNumber;
    string lineText;
};

using InvertedIndex =
    unordered_map<string, vector<Occurrence>>;

vector<filesystem::path> findFiles(
    const filesystem::path& directory
);

void readFile(const filesystem::path& filePath);

int searchFiles(
    const filesystem::path& filePath,
    const string& query
);

InvertedIndex buildIndex(
    const vector<filesystem::path>& files
);

void searchIndex(
    const InvertedIndex& index,
    const string& query
);

#endif
