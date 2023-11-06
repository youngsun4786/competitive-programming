#include<vector>
#include<list>
#include<iostream>

typedef long long ll;

using namespace std;

ll n, m, a, k;


int main() {

    cin >> n;
    int a[5001];
    bool found = false;

    for (int i = 1; i <= n; ++i) cin >> a[i];

    for (int i = 1; i <= n; ++i) {
        if (a[a[a[i]]] == i) found = true;
    }
    cout << (found ? "YES" : "NO") << "\n";

    return 0;
}