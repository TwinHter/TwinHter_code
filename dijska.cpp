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
const int MX = 100510, Lim = 60, base = 137;
vector<pii> a[MX];
ll dp[MX], pre[MX];
bool vis[MX];
void TwinHter() {
    int n, m, k; cin >> n >> m >> k;
    for(int i=1; i<=m; i++) {
        int u, v, w; cin >> u >> v >> w;
        a[u].pb({v, w}); a[v].pb({u, w});
    }
    
    for(pii u:a[1]) dp[u.fi] = u.se;
    for(int i=1; i<=n; i++) dp[i] = oo;
    dp[1] = 0;
    for(int i=1; i<=n; i++) vis[i] = false;
    priority_queue<pli, vector<pli>, greater<pli> > pq;
    while(!pq.empty()) pq.pop();
    for(int i=1; i<=n; i++) {
        if(dp[i] != oo) pq.push({dp[i], i});
    }
    while(!pq.empty()) {
        pli p = pq.top(); pq.pop();
        if(vis[p.se]) continue;
        vis[p.se] = true;
        for(pii u:a[p.se]) {
            if(dp[u.fi] > dp[p.se]+u.se && !vis[u.fi]) {
                dp[u.fi] = dp[p.se] + u.se;
                pq.push({dp[u.fi], u.fi});
            }
        }
    }
}
int main (){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("cf.inp", "r", stdin); //freopen("cf.out", "w", stdout);
    int tests = 1; //cin >> tests; 
    while(tests--) TwinHter();
}
