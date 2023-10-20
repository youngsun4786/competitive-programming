#include<iostream>
#include<algorithm>

int main() {

    int n, e, u = 0, c = 0; 
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> e;
        // add event's situation
        c += e;
        // no police available from previous loops
        if (c < 0) {
            u++;
            c = 0;
        }
    }
    std::cout << u;

    return 0;
}