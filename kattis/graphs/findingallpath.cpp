#define push_back pb
#include<vector>
#include<iostream>

int N, M;

bool visited[1000005];

// vector<vector<int> > allPaths;

using namespace std;

void dfs (int s, int e, vector<vector<int> > &adj, vector<int> &path, vector<vector<int> > &paths) {
    if (visited[s]) return;
    visited[s] = true;
    path.pb(s);

    if (s == e) {
        paths.pb(path);
    } else {
        // go through the adjacent nodes
        for (auto u : adj[s]) {
            // the starting node becomes the parent
            if (!visited[u]) {
                dfs(u, e, adj, path, paths); // this vertex now visits the parent 
            }
        }
    }

    visited[s] = false;
    path.pop_back();    
}

int main() {

    int N, M; cin >> N >> M;
    
    vector<vector<int> > adj(N);
    vector<int> path;
    vector<vector<int> > paths;
    // int parent[N];
 
    for (int i = 0; i < M; ++i) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
    }

    int start = 1;
    int end = 3;

    dfs(start, end, adj, path, paths);

    printf("printing paths\n");

    for (auto &path : paths) {
        for (auto &v : path) {
            cout << v << " ";
        }
        cout << "\n";
    }
    return 0;
}