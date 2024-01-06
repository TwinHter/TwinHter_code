const ll MX = 100010;
int seg[MX*4], lz[MX*4];
void build(int p, int l, int r) {
    if(l > r) return;
    if(l == r) {
        seg[p] = 0;
        lz[p] = 0;
    }
    int mid = l+(r-l)/2;
    build(p<<1, l, mid); build(p<<1|1, mid+1, r);
    seg[p] = seg[p<<1] + seg[p<<1|1];
}
void down(int p) {
    int tmp = lz[p]; lz[p] = 0;
    seg[p<<1] += tmp; seg[p<<1|1] += tmp;
    lz[p<<1] += tmp; lz[p<<1|1] += tmp;
}
void update(int p, int l, int r, int u, int v, int val) {
    if(l > v || u > r) return;
    if(u <= l && r <= v) {
        seg[p] += val;
        lz[p] += val;
        return;
    }
    down(p);
    int mid = l+(r-l)/2;
    update(p<<1, l, mid, u, v, val); update(p<<1|1, mid+1, r, u, v, val);
    seg[p] = seg[p<<1] + seg[p<<1|1];
}
int get(int p, int l, int r, int u, int v) {
    if(l > v || u > r) return 0;
    if(u <= l && r <= v) return seg[p];
    down(p);
    int mid = l+(r-l)/2;
    return get(p<<1, l, mid, u, v) + get(p<<1|1, mid+1, r, u, v);
}
