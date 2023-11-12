#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<deque>
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

double distance(lld x1, lld y1, lld x2, lld y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

void solve(int tc = 0) {
    cin >> n;
    // angle distance pair
    using point = pair<lld, lld>;
    
    while(n--) {
        cin >> m;

        pair<lld, lld> origin = make_pair(0.0, 0.0);
        lld currAngle = 0.0, x = 0.0, y = 0.0;
        
        vector<point> points(m);

        for (int i = 0; i < m; ++i) {
            lld angle; lld distance;
            cin >> angle >> distance;
            points[i] = make_pair(angle, distance);

            y += points[i].s * sin(points[i].f);
            x += points[i].s * cos(points[i].f);
            

        }
        cout << x << " " << y << "\n";
        // for (int i = 0; i < m; ++i) {
        //     cout << points[i].f << " " << points[i].s << "\n";
        // } 
    }





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