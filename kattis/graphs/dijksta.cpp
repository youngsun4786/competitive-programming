#include<queue>
#include<vector>
#include<list>
#include<iostream>
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<deque>
#include<set>
#include<algorithm>
#include <utility>  
#define REP(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define readgraph(list, edges) for (int i = 0; i < edges; i++) {int a, b; cin >> a >> b; a--; b--; list[a].pb(b); list[b].pb(a);}
#define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define f first
#define s second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

const lld pi = 3.14159265358979323846;
 
ll n, m, k, q, l, r, x, y, z;
const ll INF = 4e18;
const ll template_array_size = 1e6 + 585;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;





void dijkstra(ll source, vector<list<pair<ll, ll> > > &adj, vector<ll> &distance,
  vector<bool> &visited) {
  
  // priority queue to retrieve the next node in O(logn)
  priority_queue<pair<ll, ll>,  vector<pair<ll, ll> >, greater<pair<ll, ll> > > pq;
  
  // initialization
  for (ll i = 1; i <= n; ++i)  distance[i] = INF;
    
  distance[source] = 0;
  pq.push({0, source});
  
  while(!pq.empty()) {

    pair<ll, ll> cur = pq.top(); 
    pq.pop();
    
    int dist = cur.first, targ = cur.second;
    
    if (visited[targ]) continue;
    visited[targ] = true;
    
    for (pair <ll, ll> next : adj  [targ]) {
         ll w = next.second;
         
      if (dist + w < distance[next.first]) {
          distance[next.first] = dist + w;     
          // if we use default priority queue
          pq.push({distance[next.first], next.first});
      }
    }
  }
}


void solve(int tc = 0) {
    cin >> n >> m;

  vector<list<pair<ll, ll> > > adj(n + 1);
  
  // instantiate graph
  
  vector<ll> distance(n + 1);
  vector<bool> visited(n + 1, false); 
  dijkstra(0, adj, distance, visited);

}


int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);

    // C style stdin (better for multiple inputs)
    // c fof char, d for int, s for string
    //scanf("%02d: %c %19s", &x, &ch, &str)


    // C style stout
    // c fof char, d for int, s for string
    //printf("%d %c %s\n", &x, &ch, &str)

    int tc = 1;
	// cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);

    return 0;
}

 

 