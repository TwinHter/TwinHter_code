// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
#define all(x) x.begin(),x.end()
template <class T> inline T sqr(T x) { return x * x; };
template <class T> inline bool maximize(T& a, T b) { return (a < b) ? a = b, true : false; }
template <class T> inline bool minimize(T& a, T b) { return (a > b) ? a = b, true : false; }
 
string lowcase = "abcdefghijklmnopqrstuvwxyz";
string upcase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string number = "0123456789";
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
const ll pd = 998244353;
const ll oo = 3e18 + 1;
const int MX = 200100, Lim = 20, block = 320;
int n, m, dtime = 0, num[MX], low[MX];
vector<int> a[MX], khop;
vector<pii> cau;
void dfs(int u, int f) {
    num[u] = low[u] = ++dtime;
    int child = 0, ok = 0;
    for(int v:a[u]) {
        if(v == f) continue;
        if(num[v])
            low[u] = min(low[u], num[v]);  
        else {
            dfs(v, u);
            ++child;
            low[u] = min(low[u], low[v]);
            if(low[v] == num[v]) cau.pb({u, v});
            if(low[v] >= num[u]) ok = 1;
        }
    }
    if(u == f) ok = 0;
    if(ok) khop.pb(u);
    if(u == f && child > 1) khop.pb(u); 
}
void TwinHter() {
    cin >> n >> m;
    for(int i=1; i<=m; i++) {
        int u, v; cin >> u >> v;
        a[u].pb(v); a[v].pb(u);
    }

    for(int i=1; i<=n; i++) {
        if(!num[i]) dfs(i, i);
    }
    cout << khop.size() << " " << cau.size() << '\n';
}
int main (){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("cf.inp", "r", stdin); //freopen("cf.out", "w", stdout);
    int tests = 1; //cin >> tests; 
    while(tests--) TwinHter();
}
