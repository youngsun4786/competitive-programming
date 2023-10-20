#include<iostream>
#include<string>

int easierSoln(std::string s1, std::string s2) {
    // conversion to us strcmp
    const char * s = s1.c_str();
    const char * f = s2.c_str();
    return strcmp(s, f);
}

int main() {

    std::string s1;
    std::string s2;

    // // instead of this 
    // std::cin >> s1;
    // std::cin >> s2;

    // DO THIS
    std::cin >> s1 >> s2;

    std::cout << easierSoln(s1, s2) << std::endl;

    // int s1_p = 0, s2_p = 0, res = 0;
    // for (int i = 0; i < s1.length(); i++) {
    //     s1[i] = tolower(s1[i]);
    //     s2[i] = tolower(s2[i]);
    //     if (s1[i] == s2[i]) {
    //         res++;
    //         continue;
    //     }
    //     (s1[i] > s2[i]) ? std::cout << "1"  : std::cout << "-1";
    //     break; 
    // }
    // if (res == s1.length()) std::cout << "0";
    // std::cout << "This is s1 count " << s1_p << std::endl;
    // std::cout << "This is s2 count " << s2_p << std::endl;
    // (s1_p == 0 && s2_p == 0) ? std::cout << "0" : (s1_p > s2_p) ? std::cout << "1" : std::cout << "-1";
    return 0;
}