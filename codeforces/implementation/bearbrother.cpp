#include<iostream>
#include<cmath>

int main() {
    int a, b;
    std::cin >> a >> b;
    int y = 0;

    while (a <= b) {
        a *= 3;
        b *= 2;
        ++y;
    }
    std::cout << y << "\n";
}