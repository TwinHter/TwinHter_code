//https://www.spoj.com/problems/KQUERYO/
const int MX = 300010, LIM = 55000;
vector<int> seg[MX*4];
int n;
pii a[MX];
void build(int p, int l, int r) {
    if(l > r) return;
    if(l == r) {
        seg[p].pb(a[l].fi);
        return;
    }
    int mid = (l+r)>>1;
    build(p<<1, l, mid); build(p<<1|1, mid+1, r);
    merge(all(seg[p<<1]), all(seg[p<<1|1]), back_inserter(seg[p]));
}
int get(int p, int l, int r, int u, int v, int k) {
    if(l > v || u > r) return 0;
    if(u <= l && r <= v) {
        return seg[p].size()-(upper_bound(all(seg[p]), k)-seg[p].begin());
    }
    int mid = (l+r)>>1;
    return get(p<<1, l, mid, u, v, k) + get(p<<1|1, mid+1, r, u, v, k);
}
void TwinHter() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> a[i].fi;
        a[i].se = i;
    }
    build(1, 1, n);

    int q; cin >> q;
    int lastAns = 0;
    while(q--) {
        int u, v, k; cin >> u >> v >> k;
        u ^= lastAns;
        v ^= lastAns;
        k ^= lastAns;
        
        int ans = get(1, 1, n, u, v, k);
        cout << ans << '\n';
        lastAns = ans;
    }
}
int main (){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("cf.inp", "r", stdin); //freopen("cf.out", "w", stdout);
    int tests = 1; //cin >> tests; 
    while(tests--) TwinHter();
}
