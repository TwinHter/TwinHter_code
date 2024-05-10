// #pragma GCC optimize("Ofast")
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
