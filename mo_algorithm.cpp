//https://codeforces.com/contest/220/problem/B
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
const int MX = 101000, LIM = 25, block = 320;
struct query {
    int l, r, id;
} q[MX];
bool cmp(query a, query b) {
    if(a.l/block == b.l/block) return a.r/block < b.r/block;
    else return a.l/block < b.l/block;
}
int d[MX], ans[MX], a[MX];
void TwinHter() {
    int n, m; cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=m; i++) {
        cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }
    sort(q+1, q+1+m, cmp);

    int dem = 0, curL = q[1].l, curR = q[1].r;
    for(int i=q[1].l; i<=q[1].r; i++) {
        if(a[i] > n) continue;
        if(d[a[i]] == a[i]) dem--;
        d[a[i]] += 1;
        if(d[a[i]] == a[i]) dem++;
    }
    ans[q[1].id] = dem;

    for(int i=2; i<=m; i++) {
        while(curL > q[i].l) {
            curL--;
            if(a[curL] <= n) {
                if(d[a[curL]] == a[curL]) dem--;
                d[a[curL]]++;
                if(d[a[curL]] == a[curL]) dem++;
            }
        }
        while(curL < q[i].l) {
            if(a[curL] <= n) {
                if(d[a[curL]] == a[curL]) dem--;
                d[a[curL]]--;
                if(d[a[curL]] == a[curL]) dem++;
            }
            curL++;
        }
        while(curR > q[i].r) {
            if(a[curR] <= n) {
                if(d[a[curR]] == a[curR]) dem--;
                d[a[curR]]--;
                if(d[a[curR]] == a[curR]) dem++;
            }
            curR--;
        }
        while(curR < q[i].r) {
            curR++;
            if(a[curR] <= n) {
                if(d[a[curR]] == a[curR]) dem--;
                d[a[curR]]++;
                if(d[a[curR]] == a[curR]) dem++;
            }
        }
        ans[q[i].id] = dem;
    }
    for(int i=1; i<=m; i++) cout << ans[i] << '\n';
}
int main (){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("cf.inp", "r", stdin); //freopen("cf.out", "w", stdout);
    int tests = 1; //cin >> tests; 
    while(tests--) TwinHter();
}
