#include<iostream>
#include<string>

int main() {

    int n; std::cin >> n;
    std::string s;
    while(n--) {
        std::cin >> s;
        std::string res = s.length() > 10 ? s[0] + std::to_string(s.length() - 2) + s[s.length() - 1] : s;
        std::cout << res << "\n";

    }

    // std::string ss[n];
    // std::string res[n];

    // std::cin.ignore();
    // for (int i = 0; i < n; i++) std::getline(std::cin, ss[i]);

    // for (int i = 0; i < n; i++) {
    //     ss[i].length() > 10 ? res[i] = ss[i][0] + std::to_string(ss[i].length() - 2) + ss[i][ss[i].length() - 1] : res[i] = ss[i];
    // }

    // for (auto s : res) {
    //     std::cout << s << "\n";
    // }

    
    return 0;
}