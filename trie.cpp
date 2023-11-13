#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair
string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
const ll pd = 998244353;  // 1e9+7
ll oo = 1e18 + 1, tc;
const ll MX = 1810010;
int cur = 0;
struct Trie {
	int c[2], cnt = 0, exist = 0;
} node[MX];
int new_node() {
	cur++;
	node[cur].c[0] = -1; node[cur].c[1] = -1;
	return cur;
}
void add(string s) {
	int pos = 0;
	for(char p:s) {
		ll ch = p-'0', f = node[pos].c[ch];
		if(f == -1) {
			node[pos].c[ch] = new_node();
		}
		pos = node[pos].c[ch];
		node[pos].cnt += 1;
	}
	node[pos].exist++;
}
void del(string s) {
	int pos = 0;
	for(char p:s) {
		ll ch = p-'0', f = node[pos].c[ch];
		pos = node[pos].c[ch];
		node[pos].cnt -= 1;
	}
	node[pos].exist--;
}
int find(string s) {
	int pos = 0;
	for(char p:s) {
		ll ch = p-'0'; pos = node[pos].c[ch];
		if(pos == -1) return 0;
	}
	return node[pos].cnt;
}
void solve() {
	int n; cin >> n;
	node[0].c[0] = -1; node[0].c[1] = -1;
	while(n--) {
		char type; cin >> type;
		if(type == '?') {
			string s; cin >> s;
			reverse(s.begin(), s.end());
			while(s.size() < 18) s = s + '0';
			cout << find(s) << endl;
			continue;
		}
 
		ll x; cin >> x;
		string s = "", num = "01";
		while(x > 0) {
			s += num[(x%10) % 2];
			x /= 10;
		}
		while(s.size() < 18) s = s + '0';
		if(type == '+') add(s);
		if(type == '-') del(s);
	}
}
int main (){
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("cf.inp", "r", stdin); freopen("cf.out", "w", stdout);
	//cin >> tc; while(tc--)
	solve();
}