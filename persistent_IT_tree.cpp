//https://www.spoj.com/problems/DQUERY/
const int MX = 200100, LIM = 25, block = 320;
int n, d[1000100], a[MX];
int cnt = 0;
struct Node {
    int left, right, val;
} it[1000100];
int nNode = 0, nVer = 0, ver[MX*2], ID[MX];
int build(int l, int r) {
    if(l == r) {
        ++nNode;
        it[nNode] = {0, 0, 0};
        return nNode;
    }
    int cur = ++nNode, mid = (l+r)>>1;
    if(l <= mid) it[cur].left = build(l, mid);
    if(mid+1 <= r) it[cur].right = build(mid+1, r);
    return cur;
}
void reval(int cur) {
    it[cur].val = it[it[cur].left].val + it[it[cur].right].val;
}
int update(int l, int r, int u, int v, int oldId) {
    if(l == r) {
        it[++nNode] = {0, 0, v};
        return nNode;
    } 

    int cur = ++nNode, mid = (l+r)>>1;
    if(mid >= u) {
        it[cur].left = update(l, mid, u, v, it[oldId].left);
        it[cur].right = it[oldId].right;
        reval(cur);
    }  
    else {
        it[cur].left = it[oldId].left;
        it[cur].right = update(mid+1, r, u, v, it[oldId].right);
        reval(cur);
    }
    return cur;
}
int get(int id, int l, int r, int u, int v) {
    if(l > v || u > r) return 0;
    if(u <= l && r <= v) return it[id].val;

    int mid = (l+r)>>1;
    return get(it[id].left, l, mid, u, v) + get(it[id].right, mid+1, r, u, v);
}
void TwinHter() {
    cin >> n;// >> k;
    dp.assign(n+1, 0);
    build(1, n);
    ver[0] = 1;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        if(d[a[i]] > 0) {
            ++nVer;
            ver[nVer] = update(1, n, d[a[i]], 0, ver[nVer-1]);
        }
        ++nVer;
        ver[nVer] = update(1, n, i, 1, ver[nVer-1]);
        ID[i] = nVer;
        d[a[i]] = i;
    }

    int q; cin >> q;
    while(q--) {
        int l, r; cin >> l >> r;
        cout << get(ver[ID[r]], 1, n, l, r) << '\n';
    }
}
