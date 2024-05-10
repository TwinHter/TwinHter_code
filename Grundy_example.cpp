// https://www.codechef.com/problems/FDIVGAME?tab=statement
// #pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
//mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<long double, long double> pdd;
typedef pair<ll, int> pli;
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
int dx4[] = {0, 0, -1, 1};
int dy4[] = {-1, 1, 0, 0};
int dx8[] = {0, 0, -1, 1, -1, -1, 1, 1};
int dy8[] = {-1, 1, 0, 0, -1, 1, -1, 1};
const ll pd = 1000000007;
const ll oo = 2e9 + 1;
const int MX = 4000010, Lim = 448, base = 137;
vector<pli> A, pre;
int check(ll u) {
  pli tmp = {u, 0};
  auto it = lower_bound(all(pre), tmp);
  return (*it).se;
}
void TwinHter() { 
  int n; cin >> n;
  vector<ll> a;
  a.assign(n+10, 0);
  for(int i=0; i<n; i++) {
    ll x; cin >> x;
    a[i] = check(x+1);
    // cout << a[i] << " ";
  }

  ll ans = 0;
  for(int i=0; i<n; i++) ans ^= a[i];
  if(ans) cout << "Henry\n";
  else cout << "Derek\n";
}
int main (){
  ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
  // freopen("cf.inp", "r", stdin); //freopen("cf.out", "w", stdout);
  A.push_back({1, 0}); pre.push_back({1, 0});
  A.push_back({1, 1}); pre.push_back({2, 1});
  A.push_back({2, 2}); pre.push_back({4, 2});
  A.push_back({2, 3}); pre.push_back({6, 3});
  A.push_back({6, 0}); pre.push_back({12, 0});
  ll LIM = 1e18 + 12;
  cout << LIM << '\n';
  while(true) {
    pll tmp = A[A.size()-4];
    if(pre.back().fi + tmp.fi * 12 > LIM) {
      pre.push_back({LIM, tmp.se});
      break;
    }
    A.push_back({tmp.fi*12, tmp.se});
    pre.push_back({pre.back().fi + A.back().fi, tmp.se});
  }
  int tests = 1; cin >> tests; 
  while(tests--) TwinHter();
}