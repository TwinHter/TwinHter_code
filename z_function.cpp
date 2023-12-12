//https://codeforces.com/contest/126/problem/B
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
const ll pd = 1e9 + 7; //998244353;
const ll oo = 3e18 + 1;
const int MX = 230900, Lim = 20, block = 320;
vector<int> z_function(string s) {
    vector<int> z(s.size());
    for(int i=1, l=0, r=0; i<s.size(); i++) {
        if(i <= r) z[i] = min(r-i+1, z[i-l]);
        while(i + z[i] < s.size() && s[i+z[i]]==s[z[i]]) z[i]++;
        if(i + z[i] - 1 > r) {
            l = i;
            r = i+z[i]-1;
        }
    }
    return z;
} 
void TwinHter() {
    string s; cin >> s;
    vector<int> Z = z_function(s);
    int ans = 0, mx = 0;
    for(int i=1; i<s.size(); i++) {
        if(i+Z[i] == s.size() && Z[i] <= mx) ans = max(ans, Z[i]);
        mx = max(mx, Z[i]);
    }
    
    if(ans == 0) cout << "Just a legend";
    else {
        for(int i=0; i<ans; i++) cout << s[i];
    }
}
int main (){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("cf.inp", "r", stdin); //freopen("cf.out", "w", stdout);
    int tests = 1; //cin >> tests; 
    while(tests--) TwinHter();
}
