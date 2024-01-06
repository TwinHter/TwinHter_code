const int MX = 200010, LIM = 20;
struct Rec {
    ll x, y, val;
} a[MX];
struct Line {
    ll A, B;
};
int n;
ll dp[MX];
vector<Line> hull;

bool check(Line l1, Line l2, Line l3) {
    //(l1, l3) <= (l1, l2)
    return (ld)(l3.B-l1.B)/(l1.A-l3.A) <= (ld)(l2.B-l1.B)/(l1.A-l2.A);
}
bool cmp(Rec a, Rec b) {return a.x < b.x;}
void add(ll u, ll v) {
    struct Line lst = {u, v};
    while(hull.size() > 0) {
        if(hull[hull.size()-1].A == lst.A) {
            if(hull[hull.size()-1].B >= lst.B) return;
            else hull.popb();
        } else break;
    }

    while(hull.size() >= 2 && check(hull[hull.size()-2], hull[hull.size()-1], lst))
        hull.popb();
    hull.pb(lst);
}
ll F(ll x, Line p) {
    return x*p.A+p.B;
}
void TwinHter() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> a[i].x >> a[i].y >> a[i].val;
    }
    sort(a+1, a+1+n, cmp);

    //dpi = dpj + a[i].x*a[i].y - a[i].val - a[j].x*a[i].y;
    // or a[i].x*a[i].y - a[i].val

    dp[1] = a[1].x*a[1].y-a[1].val;
    ll ans = dp[1];
    add(a[1].x, dp[1]);
    for(int i=2; i<=n; i++) {
        int l = 0, r = hull.size()-1;
        while(l < r) {
            int mid = (l+r)>>1;
            if(F(-a[i].y, hull[mid]) < F(-a[i].y, hull[mid+1])) l=mid+1;
            else r=mid;
        }

        dp[i] = max(1LL*0, F(-a[i].y, hull[l])) + a[i].x*a[i].y-a[i].val;
        add(a[i].x, dp[i]);
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
}
int main (){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("cf.inp", "r", stdin); //freopen("cf.out", "w", stdout);
    int tests = 1; //cin >> tests; 
    while(tests--) TwinHter();
}
