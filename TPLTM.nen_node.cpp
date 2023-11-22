//https://oj.vnoi.info/problem/kcollect
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
const ll pd = 998244353;
const ll oo = 3e18 + 1;
const int MX = 200100, Lim = 20, block = 320;
int n, m, timed, cnt, ans; 
int num[MX], low[MX], reNode[MX], dp[MX], val[MX];
bool vis[MX], del[MX];
char ch[110][110];
deque<int> dq;
vector<int> a[MX], b[MX];

int cvt(int u, int v) {return (u-1)*m+v;}
void dfs(int u) {
    num[u] = low[u] = ++timed;
    dq.pb(u);
    for(int v:a[u]) {
        if(del[v]) continue;
        if(num[v]) low[u] = min(low[u], num[v]);
        else {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
    }

    if(num[u] == low[u]) {
        ++cnt;
        while(dq.back() != u) {
            int tmp = dq.back();
            del[tmp] = true;
            reNode[tmp] = cnt;
            dq.popb();
        }
        del[u] = true;
        reNode[u] = cnt;
        dq.popb();
    }
}
void dfs2(int u) {
    vis[u] = true;
    dp[u] += val[u];
    int ans = 0;
    for(int v:b[u]) {
        if(vis[v]) {
            ans = max(ans, dp[v]);
            continue;
        }
        dfs2(v);
        ans = max(ans, dp[v]);
    }
    dp[u] += ans;
}
void TwinHter() {
    cin >> n >> m;
    for(int i=1; i<=n; i++) 
    for(int j=1; j<=m; j++) cin >> ch[i][j];

    for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++) {
        int p = cvt(i, j);
        char tmp = ch[i][j];
        if(tmp == '#') {
            del[p] = true;
            continue;
        }
        if(i < n && ch[i+1][j] != '#') a[p].pb(cvt(i+1, j));
        if(j < m && ch[i][j+1] != '#') a[p].pb(cvt(i, j+1));
        if(tmp == 'W' && j > 1 && ch[i][j-1] != '#') a[p].pb(cvt(i, j-1));
        if(tmp == 'N' && i > 1 && ch[i-1][j] != '#') a[p].pb(cvt(i-1, j)); 
    }
    for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++) {
        if(!del[cvt(i, j)]) dfs(cvt(i, j));
    }

    for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++) {
        int p = cvt(i, j);
        char tmp = ch[i][j];
        if(tmp == '#') continue;
        if(tmp != 'W' && tmp != 'N')
            val[reNode[p]] += tmp-'0';
        for(int u:a[p]) {
            if(reNode[u] == reNode[p]) continue;
            b[reNode[p]].pb(reNode[u]);
            //cout << p << " " << u << '\n';
        }
    }
    
    dfs2(reNode[1]);
    //for(int i=1; i<=cvt(n, m); i++) cout << dp[i] << " ";
    cout << dp[reNode[1]] << '\n'; 
}
int main (){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("cf.inp", "r", stdin); //freopen("cf.out", "w", stdout);
    int tests = 1; //cin >> tests; 
    while(tests--) TwinHter();
}
