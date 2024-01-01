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
const int MX = 2000010, LIM = 20;
ll bit[1030][1030], cur[1030][1030];
int n;
void update(int u, int v, int val) {
    for( ; u<=n; u+=u&(-u)) {
        for(int vv=v; vv<=n; vv+=vv&(-vv)) 
            bit[u][vv] += val;
    }
}
ll get(int u, int v) {
    ll ans = 0;
    for(; u>0; u-=u&(-u))
    for(int vv=v; vv>0; vv-=vv&(-vv)) ans += bit[u][vv];
    return ans;
}
ll query(int x1, int y1, int x2, int y2) {
    return get(x2, y2) - get(x1-1, y2) - get(x2, y1-1) + get(x1-1, y1-1);
}
void TwinHter() {
    cin >> n;
    n++;
    for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++) {
        bit[i][j] = 0;
        cur[i][j] = 0;
    }
}
int main (){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("cf.inp", "r", stdin); //freopen("cf.out", "w", stdout);
    int tests = 1; cin >> tests; 
    while(tests--) TwinHter();
}