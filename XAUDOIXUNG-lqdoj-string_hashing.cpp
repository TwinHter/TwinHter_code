#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define fi first
#define se second
#define mp make_pair
string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
const ll pd = 1e9 + 7; //998244353;
ll oo = 1e18 +1, tc;
const ll MX = 501000;
const int base = 31;
const int hmod = 1e9 + 7;
ll pw[MX], rpw[MX], hpre[MX], hsuf[MX];
ll n;
ll sqrr(ll a, int mod = hmod) {
	return a*a%hmod;
}
ll rev(ll a, int mod = hmod-2) {
	// a^(mod-2) % hmod
	if(mod == 0) return 1;
	if(mod % 2 == 0) return sqrr(rev(a, mod/2));
	else return a*rev(a, mod-1)%hmod; 
}
bool check(int l1, int r1, int l2, int r2) {
	// pre l->r = suf r-l
	ll a1 = (hpre[r1+1]-hpre[l1] + hmod) % hmod;
	a1 = (a1 * rpw[l1]) % hmod;
	ll a2 = (hsuf[l2+1]-hsuf[r2+2] + hmod) % hmod;
	a2 = (a2 * rpw[n-1-r2]) % hmod;
	if(a1 == a2) return 1;
	else return 0;
}
void solve(){
	string s; cin >> s;
	n = s.size();
	pw[0] = 1; rpw[0] = rev(1);
	for(int i=1; i<=n; i++) {
		pw[i] = pw[i-1]*base % hmod;
		rpw[i] = rev(pw[i]);
	}

	hpre[0] = 0;
	hpre[1] = s[0] - 'a';
	for(int i=1; i<n; i++) {
		hpre[i+1] = (hpre[i]+(s[i]-'a')*pw[i]%hmod) % hmod; 
	}
	hsuf[n+1] = 0;
	hsuf[n] = s[n-1] - 'a';
	for(int i=n-2; i>=0; i--) {
		hsuf[i+1] = (hsuf[i+2]+(s[i]-'a')*pw[n-1-i]%hmod) % hmod;
	}

	ll ans = 0;
	// 1 mid
	for(int i=0; i<n; i++) {
		int lim = min(i, (int)n-1-i);
		ll pluss = 0;
		for(int l=0, r=lim; l<=r;) {
			int mid = l + (r-l)/2;
			if(check(i-mid, i, i, i+mid) == 1) {
				l = mid+1;
				pluss = mid+1;
			}
			else r = mid-1;
		}
		ans += pluss;
	}
	//2 mid	
	for(int i=0; i<n-1; i++) {
		if(s[i] != s[i+1]) continue;
		int lim = min(i, (int)n-2-i);
		ll pluss = 0;
		for(int l=0, r=lim; l<=r; ) {
			int mid = l + (r-l)/2;
			if(check(i-mid, i, i+1, i+1+mid)) {
				l = mid+1;
				pluss = mid + 1;
			}
			else r = mid-1;
		}
		ans += pluss;
	}
	cout << ans << endl;
}
int main (){
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("cf.inp", "r", stdin); freopen("cf.out", "w", stdout);//
	//cin >> tc; while(tc--) 
	solve();
}