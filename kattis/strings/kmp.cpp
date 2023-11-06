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
// typedef pair<int, int> pii;
// typedef pair<ll, ll> pll;
// typedef vector<int> vi;
// typedef vector<ll> vl;
// typedef vector<pii> vpi;
// typedef vector<pll> vpl;

const lld pi = 3.14159265358979323846;
 
ll n, m, k, q, l, r, x, y, z;
const ll INF = 4e18;
const ll template_array_size = 1e6 + 585;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string p, t;
ll ans = 0;


vector<ll> preprocess(string &pat);
 
// Prints occurrences of txt[] in pat[]
void KMP(string &pat, string&txt) {

    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    
 
    // Preprocess the pattern (calculate lps[] array)
    vector<ll> lps = preprocess(pat);
 
    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    while ((n - i) >= (m - j)) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
 
        if (j == m) {
            printf("Found pattern at index %d ", i - j);
            j = lps[j - 1];
        }
 
        // mismatch after j matches
        else if (i < n && pat[j] != txt[i]) {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0) j = lps[j - 1];
            else i = i + 1;
        }
    }
}
 
// Fills lps[] for given pattern pat[0..M-1]
vector<ll> preprocess(string &pat)
{
    // length of the previous longest prefix suffix
    int len = 0;

    vector<ll> lps(m);

    lps[0] = 0; // lps[0] is always 0
 
    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < m) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0) {
                len = lps[len - 1];
 
                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

void solve(int tc = 0) {
    cin >> p >> t;

    m = (ll) p.length();
    n = (ll) t.length();

    KMP(p, t);
    return;
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