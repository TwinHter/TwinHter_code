// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
const int MX = 200100, Lim = 20, block = 320;
int n, m, dtime = 0, low[MX], num[MX], del[MX], scc;
vector<int> a[MX];
deque<int> dq;
void dfs(int u) {
    num[u] = low[u] = ++dtime;
    dq.pb(u);
    for(int v:a[u]) {
        if(del[v]) continue;
        if(num[v])
            low[u] = min(low[u], num[v]);  
        else {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
    }
    if(low[u] == num[u]) {
        ++scc;
        while(dq.back() != u) {
            del[dq.back()] = 1;
            dq.popb();
        }
        del[u] = 1; 
        dq.popb();
    }
}
void TwinHter() {
    cin >> n >> m;
    for(int i=1; i<=m; i++) {
        int u, v; cin >> u >> v;
        a[u].pb(v);
    }

    for(int i=1; i<=n; i++) {
        if(!num[i]) dfs(i);
    }
    cout << scc << '\n';
}
