#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<deque>
#include<queue>
#include<stack>
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

vector<ll> edges[300005];
ll indegree[300005];
vector<ll> topsort;
ll dp[100005];

void solve(int tc = 0) {
    cin >> n >> m >> s;

    for (ll i = 0; i < m; ++i) {
        cin >> x >> y;
        x--; y--;
        edges[x].push_back(y);
        edges[y].push_back(x);

        ++indegree[y];
    }

    queue<ll> q;
    ll cnt = 0;
    for (ll i = 0; i < n; ++i) {
        if (indegree[i] == 0) q.push(i);
    }
    
    while(!q.empty()) {
        ++cnt;
        ll x = q.front(); q.pop();
        topsort.push_back(x);

        for (ll next : edges[x]) {
            --indegree[next];
            if (indegree[next] == 0) q.push(next);
        }
    }

    if (cnt < n) cout << -1 << "\n";

    ll ans = 0;
    for (char c = 'a'; c <= 'z'; c++) {
        memset(dp, 0, sizeof(dp));

        for (ll x : topsort) {
            if (s[x] == c) ++ dp[x];
            for (ll next : edges[x]) {
                dp[next] = max(dp[next], dp[x]);
            }
            ans = max(ans, dp[x]);
        }
    }
}

// DAG - directed acyclic graph should not contain any CYCLES


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