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
const ll MX = 100010;
pair<int, int> seg[MX];
void down(int id) {
    int p = seg[id].se; seg[id].se = 0;
    seg[id*2].fi += p; seg[id*2].se += p; 
    seg[id*2+1].fi += p; seg[id*2+1].se += p; 
}
void update(int id, int l, int r, int l2, int r2, int x) {
    if(l > r2 || l2 > r) return;
    if(l <= l2 && r2 <= r) {
        seg[id].fi += x; seg[id].se += x;
    }
    down(id);
}