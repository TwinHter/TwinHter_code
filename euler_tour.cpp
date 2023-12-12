// #pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<long double, long double> pdd;
typedef pair<ll, int> pli;
typedef vector<vector<ll> > matrix;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define popb pop_back
#define pf push_front
#define popf pop_front
#define all(x) x.begin(),x.end()
template <class T> inline T sqr(T x) { return x * x; };
template <class T> inline bool maximize(T& a, T b) { return (a < b) ? a = b, true : false; }
template <class T> inline bool minimize(T& a, T b) { return (a > b) ? a = b, true : false; }
 
string lowcase = "abcdefghijklmnopqrstuvwxyz";
string upcase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string number = "0123456789";
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
const ll pd = 1e9+7; //998244353;
const ll oo = 3e18 + 1;
const int MX = 200010, Lim = 31, base = 137;
int N = 0, et[MX*2], in[MX], out[MX], h[MX], up[Lim][MX];
vector<int> a[MX];
void ETT(int u, int f) {
    et[++N] = u; in[u] = N;
    h[u] = h[f]+1;
    up[0][u] = f;
    for(int i=1; i<Lim; i++) up[i][u] = up[i-1][up[i-1][u]];
    for(int v:a[u]) {
        if(v != f) ETT(v, u);
    }
    if(u != 1) {
        et[++N] = f; out[f] = N;
    }
}

int Find(int u, int dis) {
    if(dis < 0) return -1;
    for(int i=0; i<Lim; i++)
        if((dis>>i)&1) u = up[i][u];
    return u;
}
void TwinHter() {
    int n, q; cin >> n >> q;
    for(int i=1; i<n; i++) {
        int u, v; cin >> u >> v;
        a[u].pb(v); a[v].pb(u);
    }
    h[0] = -1;
    ETT(1, 0);
    for(int i=1; i<=n; i++)
        if(out[i] == 0) out[i] = in[i];
    //for(int i=1; i<=N; i++) cout << et[i] << " "; cout << '\n';
}
int main (){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("cf.inp", "r", stdin); //freopen("cf.out", "w", stdout);
    int tests = 1; //cin >> tests; 
    while(tests--) TwinHter();
}
