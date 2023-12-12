//https://codeforces.com/group/FLVn1Sc504/contest/212925/problem/G
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
const ll oo = 9e18 + 1;
const int MX = 250510, LIM = 55000;
int n, a[MX];
pii ev[MX];
vector<int> Node[MX], bit[MX];
void fakeUpdate(int x, int y) {
    for(; x<=n; x+=x&(-x)) Node[x].pb(y);
} 
void fakeget(int x, int y) {
    for(; x>0; x-=x&(-x)) Node[x].pb(y);
}
void update(int x, int y, int val) {
    for(; x<=n; x+=x&(-x))
    for(int yy=lower_bound(all(Node[x]), y)-Node[x].begin()+1; yy<=Node[x].size(); yy+=yy&(-yy))
        bit[x][yy] += val;
}
int get(int x, int y) {
    int ans = 0;
    for(; x>0; x-=x&(-x))
    for(int yy=lower_bound(all(Node[x]), y)-Node[x].begin()+1; yy>0; yy-=yy&(-yy))
        ans += bit[x][yy];
    return ans;
}
void fakeGet(int x1, int y1, int x2, int y2) {
    if(x1 > x2 || y1 > y2) return;
    fakeget(x2, y2);
    fakeget(x1-1, y2);
    fakeget(x2, y1-1);
    fakeget(x1-1, y1-1);
}
int Get(int x1, int y1, int x2, int y2) {
    if(x1 > x2 || y1 > y2) return 0;
    return get(x2, y2) - get(x1-1, y2) - get(x2, y1-1) + get(x1-1, y1-1);
}
void TwinHter() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        fakeUpdate(i, a[i]);
        fakeGet(1, a[i]+1, i-1, LIM);
        fakeGet(i+1, 1, n, a[i]-1);
    }

    int q; cin >> q;
    for(int i=1; i<=q; i++) {
        cin >> ev[i].fi >> ev[i].se;
        fakeUpdate(ev[i].fi, ev[i].se);
        fakeGet(1, ev[i].se+1, ev[i].fi-1, LIM);
        fakeGet(ev[i].fi+1, 1, n, ev[i].se-1);
    }

    for(int i=1; i<=n; i++) {
        sort(all(Node[i]));
        Node[i].resize(unique(all(Node[i])) - Node[i].begin());
        bit[i].assign(Node[i].size()+10, 0);
    }
    
    ll ans = 0;
    for(int i=1; i<=n; i++) {
        ans += Get(1, a[i]+1, i-1, LIM);
        ans += Get(i+1, 1, n, a[i]-1);
        update(i, a[i], 1);
        //cout << ans << " ";
    }
    
    for(int i=1; i<=q; i++) {
        ans -= Get(1, a[ev[i].fi]+1, ev[i].fi-1, LIM);
        ans -= Get(ev[i].fi+1, 1, n, a[ev[i].fi]-1);

        update(ev[i].fi, a[ev[i].fi], -1);
        update(ev[i].fi, ev[i].se, 1);
        ans += Get(1, ev[i].se+1, ev[i].fi-1, LIM);
        ans += Get(ev[i].fi+1, 1, n, ev[i].se-1);
        a[ev[i].fi] = ev[i].se;
        cout << ans << '\n';
    }

}
int main (){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("cf.inp", "r", stdin); //freopen("cf.out", "w", stdout);
    int tests = 1; //cin >> tests; 
    while(tests--) TwinHter();
}
