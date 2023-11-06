#include<vector>
#include<list>
#include<iostream>

typedef long long ll;

using namespace std;



int main() {
    int n; 
    
    while (cin >> n && n > 0) {
        int g[n][n];
        bool weak[n];

        // initialize weak array
        for (int i = 0; i < n; ++i) {
            weak[i] = true;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> g[i][j];
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (g[i][j] && g[i][k] && g[j][k]) weak[i] = false;
                }
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (weak[i]) cout << i << " ";
        }
        cout << "\n";
    }

    

}