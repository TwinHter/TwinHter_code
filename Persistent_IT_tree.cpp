//https://www.spoj.com/problems/DQUERY/
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
int main (){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("cf.inp", "r", stdin); //freopen("cf.out", "w", stdout);
    int tests = 1; //cin >> tests; 
    while(tests--) TwinHter();
}
