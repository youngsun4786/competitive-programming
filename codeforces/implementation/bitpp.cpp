#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();

    int x = 0;
    while(n--) {
        string st;
        getline(cin, st);
        if (st.find('+') < st.length()) x++;
        if (st.find('-') < st.length()) x--;
    }
    cout << x << "\n";
}