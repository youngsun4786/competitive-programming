#include<iostream>

int main() {
    int n; std::cin >> n;
    int total_sol = 0;

    while(n--) {
        int sol = 0;
        for (int i = 0; i < 3; i++) {
            int s;
            std::cin >> s;
            if (s == 1) sol ++;
        }
        if (sol > 1) total_sol++;
    }

    std::cout << total_sol;
    return 0;
}