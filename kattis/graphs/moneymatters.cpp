#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<deque>
#include<set>
#include<queue>
#include<algorithm>
#include <utility>  
#define REP(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
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
// typedef vector<int> vi;
// typedef vector<ll> vl;
// typedef vector<pii> vpi;
// typedef vector<pll> vpl;

const lld pi = 3.14159265358979323846;
 
ll n, m, k, q, l, r, x, y, z;
const ll INF = 4e18;
const ll template_array_size = 1e6 + 585;
// ll a[template_array_size];
// ll b[template_array_size];
// ll c[template_array_size];
string s, t;
ll ans = 0;

vector<ll> edges[1000005];
bool vis[1000005];
ll owe[1000005];


bool bfs(ll s) {
    
    queue<ll> q;
    q.push(s);
    ll sum = 0;

    while(!q.empty()) {
        ll x = q.front();
        q.pop();

        if (vis[x]) continue;
        vis[x]= true;
        sum += owe[x];
        // printf("This is the money owed by friend %lld:%lld\n",x, owe[x]);
        // printf("CURRENT SUM: %lld\n", sum);
        
        for (ll next : edges[x]) {
            if (!vis[next]) {
                q.push(next);
            }
        }
    }

    if (sum > 0) return false;

    return true;
}



void solve(int tc = 0) {
    cin >> n >> m;

    for (ll i = 0; i < n; ++i) {
        ll money; cin >> money;
        owe[i] = money;
    }

    for (ll i = 0; i < m; ++i) {
        ll x, y; cin >> x >> y;
        edges[x].pb(y);
        edges[y].pb(x);
    }

    for (ll i = 0; i < sizeof(vis); ++i) {
        vis[i] = false;
    }

    ll sum = 0;
    bool res = false;

    for (ll i = 0; i < n; ++i) {
        if (!vis[i]){
           res = bfs(i);
           if (res == false) {
            cout << "IMPOSSIBLE";
            return;
           }
        }
    }

    if (res) cout << "POSSIBLE";
    // printf("This is the sum %lld", sum);
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