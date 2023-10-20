#include<iostream>
#include<string>

int main() {
    std::string w;
    std::cin >> w;

    int lower = 0, upper = 0;

    for (auto c : w) {
        if (c >= 'A' && c <= 'Z') upper++;
        if (c >= 'a' && c <= 'z') lower++;
    }

    int (*op) (int);
    lower >= upper ? op=tolower : op=toupper;
    // must pass reference
    for (auto &c : w) {
        c = op(c);
    }
    std::cout << w << "\n";
}

