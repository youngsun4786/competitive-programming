#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<deque>
#include<set>
#include<stack>
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


const lld pi = 3.14159265358979323846;
 
ll n, m, k, q, l, r, x, y, z;
const ll INF = 4e18;
const ll template_array_size = 1e6 + 585;

string s, t;
ll ans = 0;

vector<ll> edges[1000005];
bool vis[1000005];
ll owe[1000005];

bool found = false;


bool dfs (ll s) {

    stack<ll> stk;

    vis[s] = true;

    ll sum = 0;

    stk.push(s);
    while (!stk.empty()) {
        ll x = stk.top();
        stk.pop();

        if (vis[x]) continue;
        
        vis[x] = true;
        sum += owe[x];

        for (auto next : edges[x]) {
            if (!vis[next]) {
                stk.push(next);
            }
        }        
    }

    if (sum != 0){
        found = true;
        return false;
    }

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

    for (ll i = 0; i < n; ++i) {
        if (vis[i]) continue;

        stack<ll> stk;

        ll sum = 0;

        stk.push(i);
        while (!stk.empty()) {
            ll x = stk.top();
            stk.pop();

            if (vis[x]) continue;
            
            vis[x] = true;
            sum += owe[x];

            for (auto next : edges[x]) {
                if (!vis[next]) {
                    stk.push(next);
                }
            }        
        }

        if (sum != 0){
            found = true;
        }
    }
    (found) ? cout << "IMPOSSIBLE" << "\n" : cout << "POSSIBLE" << "\n";
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