//https://codeforces.com/contest/1182/problem/E
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
const ll pd = 1e9 + 7;
ll oo = 9e18 + 1;
const int MX = 500100;
ll n, ans = 1;
matrix base;
ll inv(ll v, ll MOD = pd){
	if (v<=1) return v;
	return inv(MOD%v, MOD)*(MOD-MOD/v)%MOD;
}
ll pw(ll a, ll mu) {
    if(mu == 0) return 1;
    ll a2 = pw(a, mu/2); a2 = a2*a2%pd;
    if(mu % 2 == 0) return a2;
    return a*a2%pd;
}
matrix operator * (const matrix &a, const matrix &b) {
    int sz = 3;
    vector<ll> ci(sz, 0);
    matrix c(sz, ci);
    for(int i=0; i<sz; i++)
    for(int j=0; j<sz; j++)
    for(int k=0; k<sz; k++) {
        c[i][j] += a[i][k] * b[k][j];
        c[i][j] %= pd-1;
    }
    return c;
}
matrix pw_matrix(matrix a, ll mu) {
    if(mu == 1) return a;
    matrix p = pw_matrix(a, mu/2);
    p = p*p;
    if(mu % 2 == 0) return p;
    return a*p;
}
ll cal(ll f1, ll f2, ll f3) {
    return (base[2][0]*f1 + base[2][1]*f2 + base[2][2]*f3);
}

void TwinHter() {
    cin >> n ;
    base = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}};
    base = pw_matrix(base, n-3);
}
int main (){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("cf.inp", "r", stdin); //freopen("cf.out", "w", stdout);
    int tests = 1; //cin >> tests; 
    while(tests--) TwinHter();
}
