#include<list>
#include<vector>
#include<iostream>
#include<unordered_map>
#include<queue>
#define enld endl
#define endl "\n"

using namespace std;

// always pass the reference
void bfs (char s, unordered_map<char, list<char> > &adj, unordered_map<char, bool> &visited, unordered_map<char, int> &distance) {

    queue<char> q;
    distance[s] = 0;
    visited[s] = true;
    q.push(s);

    while(!q.empty()) {
        char x = q.front();
        q.pop();

        for (auto &u : adj[x]) {
            if (!visited[u]) {
                distance[u] = distance[x] + 1;
                visited[u]= true;
                q.push(u);
            }
        }
    }
}


int main() {

    int N, M; cin >> N >> M;

    unordered_map<char, list<char> > adj(N); 
    unordered_map<char, bool> visited(N);
    unordered_map<char, int> distance(N);

    vector<vector<char> > comps;
    vector<char> comp;

    for (int i = 0; i < M; ++i) {
        char u, v; cin >> u >> v;
        adj[u].__emplace_back(v);
        adj[v].__emplace_back(u);
    } 


    char start = 'b';

    bfs(start, adj, visited, distance);

     // output distances
    printf("\nPrinting all the distances\n ");

    for (auto &[k ,v] : distance) {
        printf("node: %c\ndistance: %d\n\n", k, v);
    }

    // for (char c = 'a'; c <= 'j'; ++c) {
    //     if (!visited[c]) {
    //         dfs (c, adj, visited, comp);
    //         // when code reaches here all components have been found
    //         comps.push_back(comp);
    //         comp.clear();
    //     }
    // }


    // output components
    printf("\nPrinting all the components\n");

    // for (auto &comp : comps) {
    //     for (auto &v : comp) {
    //         cout << v << " ";
    //     }
    //     cout << endl;
    // }
    

    return 0;
}