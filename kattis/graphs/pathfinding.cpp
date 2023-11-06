#define push_back pb
#include<vector>
#include<iostream>

int N, M;

bool visited[1000005];
int par[1000005];

using namespace std;

void dfs (int s, int parent, vector<vector<int> > &adj) {
    if (visited[s]) return;
    visited[s] = true;
    par[s] = parent;

    // store extra information about the parent
    
    for (auto u : adj[s]) {
        // the starting node becomes the parent
        dfs(u, s, adj); // this vertex now visits the parent 
    }
    
}

int main() {

    int N, M; cin >> N >> M;
    
    vector<vector<int> > adj(N);
 
    for (int i = 0; i < M; ++i) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
    }

    printf("printing dfs\n");

    dfs(1, -1, adj);

    vector<int> path;
    int tmp = 3;

    while(tmp != -1) {
        path.pb(tmp);
        tmp = par[tmp];
    }

    reverse(path.begin(), path.end());
    
    for (int i = 0; i < path.size(); ++i) {
        cout << path[i] << " ";
    }

    return 0;
}