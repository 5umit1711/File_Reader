
#include "functions.h"

#include <iostream>
#include <system_error>

using namespace std;

vector<filesystem::path> findFiles(
    const filesystem::path& directory
) {
    vector<filesystem::path> files;
    error_code ec;

    filesystem::recursive_directory_iterator it(
        directory,
        filesystem::directory_options::skip_permission_denied,
        ec
    );

    filesystem::recursive_directory_iterator end;

    if (ec) {
        cerr << "Error scanning directory: "
             << ec.message() << '\n';
        return files;
    }

    while (it != end) {
        error_code typeError;

        if (it->is_regular_file(typeError) && !typeError) {
            files.push_back(it->path());
        }

        it.increment(ec);

        if (ec) {
            cerr << "Warning: Could not scan an entry: "
                 << ec.message() << '\n';
            ec.clear();
        }
    }

    return files;
}
