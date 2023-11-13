#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<long double, long double> pdd;
typedef vector<vector<ll> > matrix;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define popb pop_back
#define pf push_front
#define popf pop_front
template <class T> inline T sqr(T x) { return x * x; };
template <class T> inline bool maximize(T& a, T b) { return (a < b) ? a = b, true : false; }
template <class T> inline bool minimize(T& a, T b) { return (a > b) ? a = b, true : false; }
 
string lowcase = "abcdefghijklmnopqrstuvwxyz";
string upcase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string number = "0123456789";
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
const ll pd = 1e9;
ll oo = 9e18 + 1;
const int MX = 200100;
int n, k, del[MX], child[MX], dis[MX], mxdis;
ll sum[MX], dis2[MX];
vector<int> a[MX], ap;
void dfs(int u, int f = -1) {
    child[u] = 1;
    for(int v:a[u])
        if(!del[v] && v != f) {
            dfs(v, u);
            child[u] += child[v];
        }
}
int centroid(int u, int f, int nn) {
    for(int v:a[u])
        if(!del[v] && child[v] >= nn/2 && v != f) return centroid(v, u, nn);
    return u;
}
ll cal(int u) {
    ll ans = 0;
    dfs(u); // child
 
    int sz = child[u];
    int root = centroid(u, u, sz);
    del[root] = 1;
    ans += process(root, sz);
    for(int v:a[root]) 
        if(!del[v]) ans += cal(v);
 
    return ans;
}
void TwinHter() {
    cin >> n >> k;
    for(int i=1; i<n; i++) {
        int u, v; cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }
}
int main (){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("cf.inp", "r", stdin); //freopen("cf.out", "w", stdout);
    int tests = 1; //cin >> tests; 
    while(tests--) TwinHter();
}