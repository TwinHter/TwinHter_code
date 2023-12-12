//https://www.spoj.com/problems/KQUERYO/
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
const ll oo = 9e18 + 1;
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
