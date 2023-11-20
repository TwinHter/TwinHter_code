const int Lim = 25;
int MX = 100010;
int lca[Lim][MX];
void dfs(int u, int f) {
    lca[0][u] = f;
    h[u] = h[f]+1;
    for(int i=1; i<Lim; i++) lca[i][u] = lca[i-1][lca[i-1][u]];
    
    for(int v:a[u])
        if(v != f) dfs(v, u);
}
int LCA(int u, int v) {
    if(h[u] != h[v]) {
        if(h[u] < h[v]) swap(u, v);
        int dif = h[u]-h[v];
        for(int i=0; i<Lim; i++) 
            if((dif>>i)&1) u = lca[i][u];
    }
    if(u == v) return u;
    for(int j=Lim-1; j>=0; j--) {
        if(lca[j][u] != lca[j][v]) u = lca[j][u], v = lca[j][v];
    }
    return lca[0][u];
}
