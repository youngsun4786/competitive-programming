#define push_back pb
#include<vector>
#include<iostream>
#include<list>
#include<tuple>

using namespace std;


struct Edge {
  int node;
  int weight;
};

void addEdge(int u, int v, int w, vector<Edge> adj[]) {
    Edge e;
    e.weight = w; e.node = v;
    adj[u].pb(e);
}

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
        adj[u].pb(v);
        adj[v].pb(u);
    }

    printf("printing adj list\n");

    for (auto & nodes : adj) {
        for (auto & next : nodes) {
            cout << next << " ";
        }
        cout << endl;
    }

    // for (int i = 0; i < N; ++i) {
    //     for (auto &nodes : adj[i]) {
    //         cout << nodes << " ";
    //     }
    //     cout << "\n";
    // }


    return 0;
}