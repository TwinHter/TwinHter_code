// Tutorial 2d dp using matrix mul: https://threadsiiithyderabad.quora.com/Solving-Dynamic-Programming-with-Matrix-Exponentiation
// Problem: https://oj.vnoi.info/problem/olp_ct22_restore
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
const ll pd = 1e9 + 7; //998244353;
const ll oo = 3e18 + 1;
const int MX = 300900, Lim = 100000, base = 137;

matrix I;
int sz;
matrix operator * (const matrix &A, const matrix &B) {
    matrix C(sz, vector<ll>(sz, 0));
    for(int i=0; i<sz; i++)
    for(int j=0; j<sz; j++)
    for(int k=0; k<sz; k++) {
        C[i][j] += A[i][k]*B[k][j]%pd;
        C[i][j] %= pd;
    }
    return C;
}
matrix Power(matrix A, int m) {
    matrix ans = I;
    for(; m>0; m>>=1) {
        if(m&1) ans = ans*A;
        A = A*A;
    }
    return ans;
}
void TwinHter() {
    int m, k; cin >> m >> k;

    sz = k;
    I.assign(sz, vector<ll>(sz, 0));
    for(int i=0; i<sz; i++) I[i][i] = 1;
    matrix A(sz, vector<ll>(sz, 0));
    // (i, j) = (i-1, j) + 3*(i-1, j-1) + 3*(i-1, j-2);
    for(int i=0; i<k; i++) {
        int p2 = (i-1+k)%k, p3 = (i-2+k)%k, p1 = i%k;
        A[i][p1] = 1; A[i][p2] = 3; A[i][p3] = 3;
    }
    A = Power(A, m-1);

    ll ans = (A[0][1]*3+A[0][2]*3+A[0][0]-1+pd) % pd;
    cout << ans << '\n';
}
int main (){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("cf.inp", "r", stdin); //freopen("cf.out", "w", stdout);
    int tests = 1; //cin >> tests; 
    while(tests--) TwinHter();
}

