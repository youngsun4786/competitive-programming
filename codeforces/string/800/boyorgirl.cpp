#include<iostream>
#include<string>
#include<set>


int main() {

    // use char map
    std::string s;
    std::cin >> s;
    std::set<char> set;

    for (int i = 0; i < s.size(); i++) {
        set.insert(s[i]);
    }

    (set.size() % 2 == 0) ? std::cout << "CHAT WITH HER!" :  std::cout << "IGNORE HIM!";
    return 0;
}