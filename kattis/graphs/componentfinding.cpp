#include<list>
#include<vector>
#include<iostream>
#include<unordered_map>
#define enld endl
#define endl "\n"


using namespace std;
// bool visited[1000005];


void dfs (char s, unordered_map<char, list<char> > &adj, unordered_map<char, bool> &visited, vector<char> &comp) {
    if (visited[s]) return;
    visited[s] = true;
    comp.push_back(s);

    for (auto &u : adj[s]) {
        dfs(u, adj ,visited, comp);
    }
}


int main() {

    int N, M; cin >> N >> M;

    unordered_map<char, list<char> > adj(N); 
    unordered_map<char, bool> visited(N);

    vector<vector<char> > comps;
    vector<char> comp;

    for (int i = 0; i < M; ++i) {
        char u, v; cin >> u >> v;
        adj[u].__emplace_back(v);
        adj[v].__emplace_back(u);
    } 

    for (char c = 'a'; c <= 'j'; ++c) {
        if (!visited[c]) {
            dfs (c, adj, visited, comp);
            // when code reaches here all components have been found
            comps.push_back(comp);
            comp.clear();
        }
    }


    // output components
    printf("\nPrinting all the components\n");

    for (auto &comp : comps) {
        for (auto &v : comp) {
            cout << v << " ";
        }
        cout << "\n";
    }
    

    return 0;
}