#include<bits/stdc++.h>
using namespace std;
    // Creater: MrBB.TwinHTer - 2HT.
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef pair<ll, ll> lll;
typedef string str;
#define fi first
#define se second
#define pb push_back
#define ppb pop_back
#define pmod (int)1000000007
#define oo (ll)9023372036854775007
#define pd (int)1
const int base = 311;
const ll Hmod[] = {(int)1e9 + 2277, (int)1e9 + 5277, (int)1e9 + 8277, (int)1e9+ 9277};
const int gh = 151;
int test_case;
//==========================Pt==========================
int cnt = 0;
int dp[20][50][2];
int d[50];
int cal(int id = cnt, int sum = 0, int tight = 1) {
	if(sum>3) return 0;
	if(id==0) {
		if(sum<=3) return 1;
		return 0;
	}
	if(dp[id][sum][tight]!=-1) return dp[id][sum][tight];
	
	int res = 0;
	int dig = 9;
	if(tight==1) dig = d[id];
	for(int i=0; i<=dig; i++) {
		int ntight = 0;
		if(i==dig) ntight = tight;
		res += cal(id-1, sum+(i!=0), ntight);
	}
	dp[id][sum][tight] = res;
	return res;
}
void solve() {
	ll l, r; cin >> l >> r;
	l--;
	cnt = 0;
	for(int i=0; i<=19; i++) {
		for(int j=0; j<=49; j++) {
			for(int t=0; t<=1; t++) {
				dp[i][j][t] = -1;
			}
		}
	}
	 while(l>0) {
		d[++cnt] = l%10;
		l/=10;
	}
	int s1 = cal();
	cnt = 0;
	memset(dp, -1, sizeof(dp));
	while(r>0) {
		d[++cnt] = r%10;
		r/=10;
	}
	int s2 = cal();
	cout << s2-s1 << endl;
}
//==========================CT==========================
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> test_case; while(test_case--)
		solve(); 
}