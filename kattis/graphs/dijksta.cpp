#include<queue>
#include<vector>
#include<list>
#include<iostream>

typedef long long ll;
using namespace std;

ll N, M, k;

void dijkstra(int source, vector<list<pair<int, int> > > &adj, vector<int> &distance,
  vector<bool> &visited) {
  
  // priority queue to retrieve the next node in O(logn)
  priority_queue<pair<int, int>,  vector<pair<int, int> >, greater<pair<int, int> > > pq;
  
  // initialization
  for (int i = 1; i <= N; ++i)  distance[i] = INT_MAX;
    
  distance[source] = 0;
  pq.push({0, source});
  
  while(!pq.empty()) {

    pair<int, int> cur = pq.top(); 
    pq.pop();
    
    int dist = cur.first, targ = cur.second;
    
    if (visited[targ]) continue;
    visited[targ] = true;
    
    for (pair <int, int> next : adj  [targ]) {
         int w = next.second;
         
      if (dist + w < distance[next.first]) {
          distance[next.first] = dist + w;     
          // if we use default priority queue
          pq.push({distance[next.first], next.first});
      }
    }
  }
}


int main() {
  cin >> N >> M;

  vector<list<pair<int, int> > > adj(N + 1);
  
  // instantiate graph
  
  
  vector<int> distance(N + 1);
  vector<bool> visited(N + 1, false); 
  dijkstra(0, adj, distance, visited);
  
  
 return 0; 
}