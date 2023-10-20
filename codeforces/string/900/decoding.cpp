#include<iostream>
#include<string>

std::string betterSoln(std::string s, int n) {
    std::string res;
    for (int i = 0; i < n; i++) {
        // to determine partiy -> odd/evenness for number at the idx
        if (n - i % 2) {
           res += s[i]; 
        } else {
            res = s[i] + res;
        }
    }
}
int main() {
    int n;
    std::string s;
    std::cin >> n;
    std::cin.ignore();
    std::getline(std::cin, s);

    std::string res;
    std::string tmp = s;
    if (n % 2 == 0) {
        for (int i = 0; i < n; i++) {

            if (i % 2 == 0) {
                res.insert(0, 1, tmp[i]);
            }else {
                res += tmp[i];
            }
        }         
    }else {
        for (int i = 0; i < n; i++) {

            if (i % 2 == 0) {
                res += tmp[i];
            }else {
                res.insert(0, 1, tmp[i]);
            }
        }
    }

    std::cout << res << "\n";

}