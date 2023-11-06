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


void solve(int tc = 0) {
    // cin >> n >> m;
    pll yo = mp(0, 1);
    cout << yo.f << " " << yo.s << "\n";
}


class Edge {
    
    public:
    int u;
    int v;
    int w;

    Edge(int node1, int node2, int weight) {
        u = node1;
        v = node2;
        w = weight;
    }
};

int find(vector<int>& disjointSet, int n) {
    if (disjointSet[n] == -1) return n;

    int mid = find(disjointSet, disjointSet[n]);
    disjointSet[n] = mid;
    return mid;
}

void join(vector<int> &disjointSet, int node1, int node2) {
    node1 = find(disjointSet, node1);
    node2 = find(disjointSet, node2);
    disjointSet[node1] = node2;
}

class weightCompare {

    public:

    bool operator() (Edge& e1, Edge& e2) {
        return e1.w < e2.w;
    }
};

class nodeCompare {

    public:

    bool operator() (Edge& e1, Edge& e2) {
        if (e1.u == e2.u)  return e1.v < e2.v;
        return e1.u < e2.u;
    }
};


int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;

    while(cin >> n && cin >> m) {
        // address for edge test case

        if (n == 0) continue;
        // reading in the edges 
        vector<Edge> edges;
        REP(i, 0, m) {
            
            int u, v, w; cin >> u >> v >> w;

            Edge e(u, v, w);

            if (e.u > e.v) swap(e.u, e.v);

            // add the edge
            edges.push_back(e);

        }

        // Kruskal's algorithm
        // sort the edges in non-decreasing weight 

        weightCompare wc;
        sort(edges.begin(), edges.end(), wc);

        // setting up a visited node array
        vector<int> disjointSet(n, -1);

        vector<Edge> tracker;
        int totalWeight = 0;

        for (Edge e : edges) {
            int parent1 = find(disjointSet, e.u);
            int parent2 = find(disjointSet, e.v);

            if (parent1 == parent2) continue;

            join(disjointSet, e.u, e.v);
            totalWeight += e.w;
            tracker.push_back(e);
        }
        
        // Ensure spanning tree's connected

        int trees = 0;
        REP(i, 0, disjointSet.size()) {
            if (disjointSet[i] < 0) trees++;
        }

        if (trees > 1) {
            cout << "Impossible" << endl;
            continue;
        }

        cout << totalWeight << endl;

        // printout all edges as well
        nodeCompare nc;
        sort(tracker.begin(), tracker.end(), nc);

        REP(i, 0, tracker.size()) {
            cout << tracker[i].u << " " << tracker[i].v << endl;
        }
    }


    int tc = 1;
	// cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);



    
    // C style stdin (better for multiple inputs)
    // c fof char, d for int, s for string
    //scanf("%02d: %c %19s", &x, &ch, &str)


    // C style stout
    // c fof char, d for int, s for string
    //printf("%d %c %s\n", &x, &ch, &str)

    return 0;
}

 