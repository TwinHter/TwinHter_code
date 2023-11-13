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
const int MX = 200010, LIM = 20;
int n, k, t[MX];
ll pre[MX];
ld inv[MX], pinv[MX], psum[MX];
vector<ld> dp, predp;
ld F(int u, int v) {return psum[v]-psum[u-1]-1.L*pre[u-1]*(pinv[v]-pinv[u-1]);}
void cal(int l, int r, int optl, int optr) {
    if(l > r) return;
    int mid = (l+r)>>1;
    pair<ld, int> best = {-1, -1};
    for(int i=optl; i<=min(optr, mid); i++) {
        if(best.fi > predp[i-1] + F(i, mid) || best.fi == -1)
            best = {predp[i-1] + F(i, mid), i};
    }

    dp[mid] = best.first;
    cal(l, mid-1, optl, best.se);
    cal(mid+1, r, best.se, optr);
}

void TwinHter() {
    // [u, v] -> x = (S[u, i]-ti)/S[u, v]
    // -> time[i] = 1 / (1-x)^2 * (1-x) = 1/(1-x) = S[u, i] / ti
    // -> time[u, v] = psum[v] - psum[u-1] - S[1, u-1]*(pinv[v] - pinv[u-1])
    // dp[v] = dp[u-1] + time[u, v]
    cin >> n >> k;
    for(int i=1; i<=n; i++) {
        cin >> t[i];
        inv[i] = 1.L*1/t[i];
        pre[i] = pre[i-1]+t[i];
        pinv[i] = pinv[i-1]+inv[i];
    }
    // psum[i] = sum(S[1, i]/ti) (i: 1->i)
    for(int i=1; i<=n; i++) {
        psum[i] = psum[i-1] + 1.L*pre[i]*inv[i];
    }

    for(int i=0; i<=n+1; i++) dp.pb(0);
    for(int i=1; i<=n; i++) {
        dp[i] = psum[i];
    }

    for(int loop=2; loop<=k; loop++) {
        predp = dp;
        cal(1, n, 1, n);
    }
    cout << fixed << setprecision(8) << dp[n] << '\n';
}
int main (){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("cf.inp", "r", stdin); //freopen("cf.out", "w", stdout);
    int tests = 1; //cin >> tests; 
    while(tests--) TwinHter();
}