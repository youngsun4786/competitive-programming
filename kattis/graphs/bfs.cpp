#define push_back pb
#include<vector>
#include<iostream>
#include<list>

using namespace std;

int main() {

    int N, M; cin >> N >> M;

    // vector<Edge> adj[N + 1];


    // for (int i = 0; i < M; ++i) {
    //     int u, v, w; cin >> u >> v >> w;
    //     addEdge(u, v, w, adj);
    // }

    // int source = 2;

    // for (auto e : adj[source]) {
    //     printf("This is node: %d and this is the weight %d\n", e.node, e.weight);
    // }

    list<int> adj[N];

    for (int i = 0; i < M; ++i) {
    int u, v; cin >> u >> v;
    adj[u].__emplace_back(v);
    adj[v].__emplace_back(u);
    }

    printf("printing adj list\n");
    
    for (int i = 0; i < N; ++i) {
        for (auto &nodes : adj[i]) {
            cout << nodes << " ";
        }
        cout << "\n";
    }


    return 0;
}