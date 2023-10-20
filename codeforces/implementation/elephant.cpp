#include<iostream>
using namespace std;

int betterSoln(int n) {
    return (n + 4)/5;
}

int main() {

    int n;
    cin >> n;
    int moves = betterSoln(n);
    // int moves = 0;

    // while (n != 0) {
    //     if (n - 5 >= 0) {
    //         n -= 5;
    //         moves++;
    //     } else if ( n - 4 >= 0) {
    //         n -= 4;
    //         moves++;
    //     } else if (n - 3 >= 0) {
    //         n -= 3;
    //         moves++;
    //     } else if (n - 2 >= 0) {
    //         n -= 2;
    //         moves++;
    //     } else if (n - 1 >= 0) {
    //         n -= 1;
    //         moves++;
    //     }
    // }
    cout << moves << "\n";
}