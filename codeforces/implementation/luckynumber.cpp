#include<iostream>
using namespace std;


int main() {
    
    long long int n;
    cin >> n;

    int cnt = 0, r = 0;
    while (n != 0) {
        r = n % 10;
        if (r == 4 || r == 7) cnt++;
        n /= 10;
    }

    if (cnt == 4 || cnt == 7) cout << "YES";
    else cout << "NO";

}