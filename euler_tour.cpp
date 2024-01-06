// #pragma GCC optimize("Ofast")
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
void TwinHter() {
    int n; cin >> n;
    for(int i=1; i<n; i++) {
        int u, v; cin >> u >> v;
        a[u].pb(v); a[v].pb(u);
    }
    h[0] = -1; N = 0;
    ETT(1, 0);
    for(int i=1; i<=n; i++)
        if(out[i] == 0) out[i] = in[i];
    //for(int i=1; i<=N; i++) cout << et[i] << " "; cout << '\n';
}
