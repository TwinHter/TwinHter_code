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
void solve() {
	int n, m; cin >> n >> m;
	vector<int> a[n+10];
	for(int i=1; i<=n; i++) {
		par[i] = -1;
		a[i].clear();
	for(int i=1; i<=m; i++) {
		int u, v; cin >> u >> v;
		a[u].pb(v); a[v].pb(u);
	}
}
int main (){
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("cf.inp", "r", stdin); freopen("cf.out", "w", stdout);
	cin >> tc; while(tc--)
	solve();
}
