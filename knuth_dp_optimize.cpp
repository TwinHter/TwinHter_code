//https://codeforces.com/group/WlhLOpeYWh/contest/485765/problem/D
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
const int MX = 5002, LIM = 20;
int n, k, a[MX];
ll dp[MX], pre[MX];
int opt[MX][MX];
ll dis(int l, int r) {
    return 1LL*(r-l+1)*(pre[r]-pre[l-1]);
}
void TwinHter() {
    cin >> n >> k;
    pre[0] = 0;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        pre[i] = pre[i-1]+a[i];
        dp[i] = 1LL*pre[i]*i;
        opt[1][i] = 1;
    }
    dp[0] = oo;
    
    for(int i=2; i<=k; i++) {
        opt[i][n+1] = n;
        for(int j=n; j>=0; j--) {
            opt[i][j] = -1;
            if(j >= i) {
                dp[j] = oo;
                for(int z=opt[i-1][j]; z<=opt[i][j+1]; z++) {
                    if(opt[i][j] == -1 || dp[z-1] + dis(z, j) < dp[j]) {
                        opt[i][j] = z;
                        dp[j] = dp[z-1] + dis(z, j);
                    }
                }
            }
            else dp[j] = oo;
        }
    }
    cout << dp[n] - pre[n] << '\n';
}
int main (){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("cf.inp", "r", stdin); //freopen("cf.out", "w", stdout);
    int tests = 1; //cin >> tests; 
    while(tests--) TwinHter();
}
