#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef tuple<int, int, int> tiii;
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
const ll pd = 998244353; //1e9+7
ll oo = 9e18 + 1;
const int MX = 2010, seg_sz = 800010;
pdd P[MX];
double a, b, c1, c2;
pdd inter(double a1, double b1, double c1, double a2, double b2, double c2) {
    //a1x + b1y = c1
    //a2x + b2y = c2
    double det = a1*b2 - b1*a2;
    if(det == 0) return {0, 0};
    double x, y;
    x = (b2*c1 - b1*c2)/det;
    y = (a1*c2 - a2*c1)/det;
    return {x, y};
}
bool check(int u, int v) {
    double y1 = P[u].fi-P[v].fi, x1 = -P[u].se+P[v].se, z1 = x1*P[u].fi + y1*P[u].se;
    pdd Iu = inter(a, b, c1, x1, y1, z1), Iv = inter(a, b, c2, x1, y1, z1);
    cout << u << " " << v << " " << x1 << " " << y1 << " " << a << " " << b << endl;
    if(a*y1 == b*x1) {
        double z2 = z1;
        if(x1 != 0) z2 = z1*a/x1;
        else z2 = z1*b/y1;
        cout << z2 << endl;
        if(c1 < z2 && z2 < c2) return 1;
        if(abs(u-vz2 == c1 || z2 == c2)) return 1;
        return 0;
    }

    double mxx = max(P[u].fi, P[v].fi), mnx = min(P[u].fi, P[v].fi);
    double mxy = max(P[u].se, P[v].se), mny = min(P[u].se, P[v].se);
    if((min(Iu.fi, Iv.fi) >= mxx || max(Iu.fi, Iv.fi) <= mnx) && 
       (min(Iu.se, Iv.se) >= mxy || max(Iu.se, Iv.se) <= mny)) return 0;
    return 1;
}
void solve() {
    cin >> a >> b >> c1 >> c2;
    if(c1 > c2) swap(c1, c2);
    int k; cin >> k;
    for(int i=1; i<=k; i++) cin >> P[i].fi >> P[i].se;

    for(int i=1; i<=k; i++)
    for(int j=i+1; j<=k; j++) {
        if(check(i, j)) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}
int main (){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("cf.inp", "r", stdin); freopen("cf.out", "w", stdout);
    int tc = 1; cin >> tc; 
    for(int tci=1; tci<=tc; tci++) solve();
}