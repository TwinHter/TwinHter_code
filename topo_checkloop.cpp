#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
const ll pd = 998244353;  // 1e9+7
ll oo = 1e18 + 1, tc;
const ll MX = 310010;
ll a[MX], k, vis[MX], dp[MX], ok = 0;
vector<int> ed[MX];
deque<int> topo;
void dfs(int u, ll gt, int sta) {
	vis[u] = sta;
	for(int v:ed[u]) {
		if(a[v] > gt) continue;
		if(vis[v] == sta) {
			ok = 1; return;
		}
		if(vis[v] == 0) dfs(v, gt, sta);
	}
	vis[u] = -sta;
	topo.pb(u);
}
void dfs2(int u, int gt) {
	if(dp[u] > 0) return;
	dp[u] = 1;
	for(int v:ed[u]) {
		if(a[v] > gt) continue;
		dfs2(v, gt);
		dp[u] = max(dp[u], dp[v] + 1);
	}
}
void solve() {
	int n, m; cin >> n >> m >> k; 

	for(int i=1; i<=n; i++) cin >> a[i];
	for(int i=1; i<=m; i++) {
		int u, v; cin >> u >> v;
		ed[u].pb(v);
	}

	int ans = -1;
	for(ll l=0, r=1000000000; l<=r; ) {
		ll mid = l + (r-l)/2;
		for(int i=1; i<=n; i++) vis[i] = 0;
		ok = 0;

		int cnt = 0;
		topo.clear();
		for(int i=1; i<=n; i++) {
			if(!vis[i] && a[i] <= mid) dfs(i, mid, ++cnt);
		}

		if(!ok) {
			for(int i=1; i<=n; i++) dp[i] = 0;
			while(!topo.empty()) {
				int p = topo.back(); topo.pob();
				if(dp[p] == 0) dfs2(p, mid);
			}

			for(int i=1; i<=n; i++) {
				if(dp[i] >= k) ok = 1;
			}
		}

		if(ok) {
			ans = mid; r = mid-1;
		}
		else {
			l = mid+1;
		}
	}
	cout << ans << endl;
}
int main (){
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("cf.inp", "r", stdin); freopen("cf.out", "w", stdout);
	//cin >> tc; while(tc--)
	solve();
}