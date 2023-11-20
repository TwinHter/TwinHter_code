//https://www.spoj.com/problems/MKTHNUM/
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
int main (){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("cf.inp", "r", stdin); //freopen("cf.out", "w", stdout);
    int tests = 1; //cin >> tests; 
    while(tests--) TwinHter();
}
