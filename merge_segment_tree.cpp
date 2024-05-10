//https://www.spoj.com/problems/MKTHNUM/
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
const int MX = 200100, LIM = 25, block = 320;
int n, q, a[MX];
vector<int> it[MX*4];
void build(int p, int l, int r) {
    if(l > r) return;
    if(l == r) {
        it[p].pb(a[l]);
        return;
    }
    int mid = (l+r)>>1;
    build(p<<1, l, mid); build(p<<1|1, mid+1, r);
    merge(all(it[p<<1]), all(it[p<<1|1]), back_inserter(it[p]));
}
int get(int p, int l, int r, int u, int v, int val) {
    if(l > v || u > r) return 0;
    if(u <= l && r <= v) {
        return upper_bound(all(it[p]), val)-it[p].begin();
    }
    int mid = (l+r)>>1;
    return get(p<<1, l, mid, u, v, val) + get(p<<1|1, mid+1, r, u, v, val);
}
void TwinHter() {
    cin >> n >> q;
    for(int i=1; i<=n; i++) cin >> a[i];
    build(1, 1, n);    
    while(q--) {
        int l, r, k; cin >> l >> r >> k;

        int ans = 0;
        for(int L=-1e9, R=1e9; L<=R; ) {
            int mid = (L+R)>>1;
            if(get(1, 1, n, l, r, mid) >= k) {
                ans = mid; R = mid-1;
            } else L = mid+1;
        }
        cout << ans << '\n';
    }
}
