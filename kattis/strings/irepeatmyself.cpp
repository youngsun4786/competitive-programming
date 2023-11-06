#include <iostream>
#include <string>

using namespace std;

std::string smallestPattern(std::string& pattern, int n) {

    std::string s;

    // build the pattern for n times (essentially creates a longer string)
    for (int i = 0; i < n; ++i) s += pattern;

    return s;
}

bool startsWith(const std::string&str, const std::string &prefix) {
    return str.size() >= prefix.size() && str.compare(0, prefix.size(), prefix) == 0;
}

int main() {

    int T; std::cin >> T;
    std::cin.ignore();

    // abbcabbcabbabbcabb

    while(T--) {
        std::string s;
        std::getline(std::cin, s);

        // processing starts
        for (int i = 1; i <= s.size(); ++i) {
            std::string tmp = s.substr(0, i);
            int n = (s.size() / tmp.size()) + 1;
            // printf("string: %s | iteration: %d | n : %d\n", tmp.c_str(), i, n);

            // cout << n << "\n";

            if (startsWith(smallestPattern(tmp, n), s)) {
                cout << tmp.length() << "\n";
                break;
            }

        }
    }
}