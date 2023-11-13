int getSum(int p) {
    int idx = p, ans = 0;
    while (idx > 0) {
        ans += bit[idx];
        idx -= (idx & (-idx));
    }
    return ans;
}
void update(int u, int v) {
    int idx = u;
    while (idx <= n) {
        bit[idx] += v;
        idx += (idx & (-idx));
    }
}