const int MX = 2000010, LIM = 20;
ll bit[1030][1030], cur[1030][1030];
int n;
void update(int u, int v, int val) {
    for( ; u<=n; u+=u&(-u)) {
        for(int vv=v; vv<=n; vv+=vv&(-vv)) 
            bit[u][vv] += val;
    }
}
ll get(int u, int v) {
    ll ans = 0;
    for(; u>0; u-=u&(-u))
    for(int vv=v; vv>0; vv-=vv&(-vv)) ans += bit[u][vv];
    return ans;
}
ll query(int x1, int y1, int x2, int y2) {
    return get(x2, y2) - get(x1-1, y2) - get(x2, y1-1) + get(x1-1, y1-1);
}
void TwinHter() {
    cin >> n;
    n++;
    for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++) {
        bit[i][j] = 0;
        cur[i][j] = 0;
    }
}
int main (){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("cf.inp", "r", stdin); //freopen("cf.out", "w", stdout);
    int tests = 1; cin >> tests; 
    while(tests--) TwinHter();
}
