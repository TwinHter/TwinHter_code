int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
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
