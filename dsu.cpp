#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front

string apb = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
const ll pd = 998244353;  // 1e9+7
ll oo = 1e18 + 1, tc;
const ll MX = 210010;
struct query{
	int st, ed, lim, cs;
};

int par[MX];
int find_par(int u) {
	return par[u] < 0 ? u : (par[u] = find_par(par[u]));
}
void union_dsu(int u, int v) {
	u = find_par(u); v = find_par(v);
	if(u == v) return;
	if(par[u] > par[v]) swap(u, v);
	par[u] += par[v]; par[v] = u;
}
bool cmp(query a, query b) {
	return a.lim < b.lim;
}

void solve() {
	int n, m; cin >> n >> m;
	pii h[n+10]; int b[n+10];
	vector<int> a[n+10];
	for(int i=1; i<=n; i++) {
		par[i] = -1;
		a[i].clear();
	}

	for(int i=1; i<=n; i++) {
		cin >> h[i].fi;
		h[i].se = i; b[i] = h[i].fi;
	}
	sort(h+1, h+1+n);

	for(int i=1; i<=m; i++) {
		int u, v; cin >> u >> v;
		a[u].pb(v); a[v].pb(u);
	}

	int q; cin >> q;
	struct query qr[q+10];
	for(int i=1; i<=q; i++) {
		int e; cin >> qr[i].st >> qr[i].ed >> e;
		qr[i].lim = b[qr[i].st] + e; qr[i].cs = i;
	}
	sort(qr+1, qr+1+q, cmp);

	int l = 1, ans[q+10];
	h[n+1].fi = -1;
	fill(&ans[0], &ans[0] + q + 10, 0);
	for(int i=1; i<=n; i++) {
		int p = h[i].se;
		for(int u:a[p]) {
			if(b[u] <= h[i].fi) union_dsu(u, p);
		}
		
		while(l <= q && qr[l].lim >= h[i].fi && qr[l].lim < h[i+1].fi) {
			int start = qr[l].st, end = qr[l].ed;
			if(find_par(start) == find_par(end)) ans[qr[l].cs] = 1;
			l += 1;
		}
	}
	while(l <= q) {
		int start = qr[l].st, end = qr[l].ed;
		if(find_par(start) == find_par(end)) ans[qr[l].cs] = 1;
		l += 1;
	}

	for(int i=1; i<=q; i++)
	    cout << (ans[i] ? "YES" : "NO") << endl;
}
int main (){
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("cf.inp", "r", stdin); freopen("cf.out", "w", stdout);
	cin >> tc; while(tc--)
	solve();
}