//https://www.spoj.com/problems/COT/
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<long double, long double> pdd;
typedef vector<vector<ll> > matrix;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define popb pop_back
#define pf push_front
#define popf pop_front
#define all(x) x.begin(),x.end()
template <class T> inline T sqr(T x) { return x * x; };
template <class T> inline bool maximize(T& a, T b) { return (a < b) ? a = b, true : false; }
template <class T> inline bool minimize(T& a, T b) { return (a > b) ? a = b, true : false; }
 
string lowcase = "abcdefghijklmnopqrstuvwxyz";
string upcase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string number = "0123456789";
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
const ll pd = 998244353;
const ll oo = 3e18 + 1;
const int MX = 200100, Lim = 20, block = 320;
int n, m, cnt, lca[Lim][MX], h[MX], in[MX];
int nVer, nNode, ver[MX], id[MX];
vector<int> a[MX], rr;
map<int, int> M;
struct Node {
    int left, right, val;
} it[5000100];
int build(int l, int r) {
    if(l == r) {
        it[++nNode] = {0, 0, 0};
        return nNode;
    }
    int mid = (l+r)>>1, cur = ++nNode;
    if(mid >= l) it[cur].left = build(l, mid);
    if(mid+1 <= r) it[cur].right = build(mid+1, r);
    it[cur].val = 0;
    return cur;
}
void reval(int p){
    it[p].val = it[it[p].left].val + it[it[p].right].val;
}
int update(int l, int r, int u, int old) {
    if(l == r) {
        it[++nNode] = {0, 0, it[old].val+1};
        return nNode;
    }
    int mid = (l+r)>>1, cur = ++nNode;
    if(mid >= u) {
        it[cur].left = update(l, mid, u, it[old].left);
        it[cur].right = it[old].right;
        reval(cur);
    }
    else {
        it[cur].left = it[old].left;
        it[cur].right = update(mid+1, r, u, it[old].right);
        reval(cur);
    }
    return cur;
}
void dfs(int u, int f) {
    lca[0][u] = f;
    h[u] = h[f]+1;
    ++nVer;
    id[u] = nVer;
    ver[nVer] = update(1, cnt, in[u], ver[id[f]]);
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
int cal(int l, int r, int u, int v, int uv, int puv, int k) {
    if(l == r) return l;
    int mid = (l+r)>>1;
    int val = it[it[u].left].val+it[it[v].left].val
            -it[it[uv].left].val-it[it[puv].left].val;
    if(val >= k) return cal(l, mid, it[u].left, it[v].left, it[uv].left, it[puv].left, k);
    else return cal(mid+1, r, it[u].right, it[v].right, it[uv].right, it[puv].right, k-val);
}
void TwinHter() {
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> in[i];
        rr.pb(in[i]);
    }
    sort(all(rr));
    rr.resize(unique(all(rr))-rr.begin());
    for(int u:rr) M[u] = ++cnt;
    for(int i=1; i<=n; i++) {
        in[i] = M[in[i]];
        //cout << in[i] << " ";
    }

    for(int i=1; i<n; i++) {
        int u, v; cin >> u >> v;
        a[u].pb(v); a[v].pb(u);
    }
    h[0] = 0;

    ver[0] = build(1, cnt);
    id[0] = 0;
    dfs(1, 0);
    while(m--) {
        int u, v, k; cin >> u >> v >> k;
        int uv = LCA(u, v), ans = cal(1, cnt, ver[id[u]], ver[id[v]], ver[id[uv]], ver[id[lca[0][uv]]], k);
        //cout << uv << " ";
        cout << rr[ans-1] << '\n';
    }

}
int main (){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("cf.inp", "r", stdin); //freopen("cf.out", "w", stdout);
    int tests = 1; //cin >> tests; 
    while(tests--) TwinHter();
}
