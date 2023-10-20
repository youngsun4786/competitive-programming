#include<iostream>
#include<vector>
#include<algorithm>

int main() {

    int n; 
    std::cin >> n;

    std::vector<int> v;

    for (int i = 0; i < n; i++) {
        int e;
        std::cin >> e;
        v.push_back(e);
    }
    std::sort(v.begin() ,v.end());
    int min = std::min(v[n-1] - v[1], v[n-2] - v[0]);
    std::cout << min << "\n";

    return 0;
}