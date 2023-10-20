#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<deque>
#include<set>
#include <cstdlib>
#include<algorithm>
#define REP(i, a, b) for (int i = a; i < b; i++)
#define endL endl;
#define endl "\n"
typedef long long ll;
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);

    // C style stdin (better for multiple inputs)
    // c fof char, d for int, s for string
    //scanf("%02d: %c %19s", &x, &ch, &str)
    int n, m; cin >> n >> m;

    int cap = m/n;

    int remain = m % n;

    REP(i, 0, n) {
        if (remain > 0) {
            REP(i, 0, cap + 1) {
                cout << "*";
            } 
            remain--;  
        } else {
            REP(i, 0, cap) {
                cout << "*";
            } 
        }
        cout << endl;


        
    }


    // scanf("%d", &n);


    // C style stout
    // c fof char, d for int, s for string
    //printf("%d %c %s\n", &x, &ch, &str)

    return 0;
}