#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<deque>
#include<iomanip>
#include<stack>
#include<set>
#include<algorithm>
#include<math.h>
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


const lld pi = 3.14159265358979323846;
 
ll n, m, k, q, l, r, x, y, z;
const ll INF = 4e18;
const ll template_array_size = 1e6 + 585;
string s, t;
ll ans = 0;

// define point
using point = pair<lld, lld>;

lld distance(lld x1, lld y1, lld x2, lld y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

point mid(lld x1, lld y1, lld x2, lld y2) {
    lld fs = (x1 + x2) / 2;
    lld sec = (y1 + y2) / 2;
    return make_pair(fs, sec);
}

point getNext(lld x1, lld y1, lld x2, lld y2) {
   return make_pair((2.0 * x2) - x1, (2.0 * y2) - y1);
}

void solve(int tc = 0) {
    // input vertices 
    lld landArea = 0.0;
    point vertices[3];

    for (int i = 0; i < 3; ++i) {
        lld x, y;
        cin >> x >> y;
        vertices[i] = make_pair(x, y);
    }
    
    lld d1 = distance(vertices[0].f, vertices[0].s, vertices[1].f, vertices[1].s);
    lld d2 = distance(vertices[1].f, vertices[1].s, vertices[2].f, vertices[2].s);
    lld d3 = distance(vertices[2].f, vertices[2].s, vertices[0].f, vertices[0].s);

    lld m = max(max(d1, d2), d3);

    point midpoint, res;
    
    if (m == d1) {
        midpoint = mid(vertices[0].f, vertices[0].s, vertices[1].f, vertices[1].s);
        res = getNext(vertices[2].f, vertices[2].s, midpoint.f, midpoint.s);
    } else if (m == d2) {       
        midpoint = mid(vertices[2].f, vertices[2].s, vertices[1].f, vertices[1].s);
        res = getNext(vertices[0].f, vertices[0].s, midpoint.f, midpoint.s);
    } else {
        midpoint = mid(vertices[0].f, vertices[0].s, vertices[2].f, vertices[2].s);
        res = getNext(vertices[1].f, vertices[1].s, midpoint.f, midpoint.s);
    }

     cout << res.f << " " << res.s << "\n";
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