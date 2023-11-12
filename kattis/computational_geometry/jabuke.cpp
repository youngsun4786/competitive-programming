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

lld triangleArea(point a, point b, point c) {
    return abs(a.f*(b.s - c.s) + b.f*(c.s - a.s) + c.f*(a.s - b.s)) / 2;
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
    landArea = triangleArea(vertices[0], vertices[1], vertices[2]);

    cin >> n;
    int numTrees = 0;
    for (int i = 0; i < n; ++i) {
        lld x, y; cin >> x >> y;
        point tree = make_pair(x, y);
        lld A1 = triangleArea(vertices[0], tree, vertices[2]);
        lld A2 = triangleArea(vertices[0], vertices[1], tree);
        lld A3 = triangleArea(tree, vertices[1], vertices[2]);

        (landArea == A1 + A2 + A3) ? numTrees++ : numTrees;
    }

    printf("%.1Lf\n", landArea);
    cout << numTrees << '\n';
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