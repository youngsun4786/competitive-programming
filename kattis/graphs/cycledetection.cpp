#include<list>
#include<vector>
#include<iostream>
#include<unordered_map>
#include<queue>
#include<stack>
#define enld endl
#define endl "\n"

using namespace std;

bool found = false;

// always pass the reference
void checkCycle (char s, unordered_map<char, list<char> > &adj, 
unordered_map<char, bool> &state, vector<char> &cycle, stack<char> &stk) {

    if (state[s] != 0) return;
    state[s] = 1;
    stk.push(s); // add element to the stack

    for (auto &u : adj[s]) {
        if (state[u] == 1) { // found a cycle while processing neighbor
            found = true;
            
            // trace the cycle backwards, until prev occurrences
            while(stk.top() != u) { // top is the last element in the stack
                cycle.push_back(stk.top());
                stk.pop(); // remove last element
            }
            cycle.push_back(u);
            reverse(cycle.begin(), cycle.end());
            return; // exit dfs
        } else if (state[u] == 0) {
            checkCycle(u, adj, state, cycle, stk);
        }
        if (found) return; // exit dfs
    }
    stk.pop();
    state[s] = 2;
}


int main() {

    int N, M; cin >> N >> M;

    unordered_map<char, list<char> > adj(N); 
    unordered_map<char, bool> state(N);
    stack <char> stk;
    vector<char> cycle;

    for (int i = 0; i < M; ++i) {
        char u, v; cin >> u >> v;
        adj[u].__emplace_back(v);
    } 

    for (char c = 'a'; c <= 'd'; ++c) {
        if (state[c] == 0) {
            checkCycle(c, adj, state, cycle, stk);
            if (found) break;
        }
    }

    // cycle.pop_back();

    // processing the cycle 
    for (auto &v : cycle) {
        cout << v << " ";
    }
    

    return 0;
}