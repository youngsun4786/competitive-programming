#include<iostream>

int main() {

    int n, k, next = 0; std::cin >> n >> k;
    int a[n]; 

    for (int i = 0; i < n; i++) std::cin >> a[i];

    k -= 1;

    for (int i = 0; i < n; i++) {
        if (a[i] > 0 && a[i] >= a[k]) next++;
    }
    std::cout << next;
}
