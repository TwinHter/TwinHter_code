// https://codeforces.com/contest/817/problem/F
// Lazy Update: 
// 1: [l, r] -> 1
// 2: [l, r] -> 0
// 3: [l, r] -> xor [l, r]
// #pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<long double, long double> pdd;
typedef pair<ll, pair<int, int>> piil;
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
const ll pd = 1e9 ; //998244353;
const ll oo = 3e18 + 1;
const int MX = 100900, Lim = 31, base = 137;
int seg[MX*8], lz[MX*8];
struct event {
    int type;
    ll l, r;
} ev[MX];
void down(int p, int l, int r) {
    int tmp = lz[p]; lz[p] = 0;
    if(tmp == 0) return;
    int mid = (l+r)>>1;
    if(tmp == 1) {
        seg[p<<1] = mid-l+1;
        seg[p<<1|1] = r-mid;
    }
    if(tmp == 2) seg[p<<1] = seg[p<<1|1] = 0;
    if(tmp == 3) {
        seg[p<<1] = mid-l+1-seg[p<<1];
        seg[p<<1|1] = r-mid-seg[p<<1|1];
    }
    if(tmp == 3) {
        lz[p<<1] = tmp-lz[p<<1]; 
        lz[p<<1|1] = tmp-lz[p<<1|1];
    }
    else lz[p<<1] = lz[p<<1|1] = tmp;
}
void update(int p, int l, int r, int u, int v, int type) {
    if(l > v || u > r) return;
    if(u <= l && r <= v) {
        if(type == 1) seg[p] = r-l+1;
        if(type == 2) seg[p] = 0;
        if(type == 3) seg[p] = r-l+1-seg[p];
        if(type == 3) lz[p] = 3-lz[p];
        else lz[p] = type;
        return; 
    }

    int mid = (l+r)>>1;
    down(p, l, r);
    update(p<<1, l, mid, u, v, type); update(p<<1|1, mid+1, r, u, v, type);
    seg[p] = seg[p<<1] + seg[p<<1|1];
} 
int get(int p, int l, int r) {
    if(l == r) return l;
    int mid = (l+r)>>1;
    down(p, l, r);
    if(seg[p<<1] == mid-l+1) return get(p<<1|1, mid+1, r);
    else return get(p<<1, l, mid);
} 
void TwinHter() {
    int n; cin >> n;
    vector<ll> cp;
    for(int i=1; i<=n; i++) {
        cin >> ev[i].type >> ev[i].l >> ev[i].r; 
        cp.pb(ev[i].l);
        cp.pb(ev[i].r+1);
    }
    cp.pb(1);
    sort(all(cp));
    cp.resize(unique(all(cp))-cp.begin());

    for(int i=1; i<=n; i++) {
        int L = lower_bound(all(cp), ev[i].l)-cp.begin()+1;
        int R = upper_bound(all(cp), ev[i].r)-cp.begin()+1;
        R--;
        //cout << L << " " << R << " ";
        update(1, 1, cp.size(), L, R, ev[i].type);

        cout << cp[get(1, 1, cp.size())-1] << '\n';
    }
}
int main (){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("cf.inp", "r", stdin); //freopen("cf.out", "w", stdout);
    int tests = 1; //cin >> tests; 
    while(tests--) TwinHter();
}
