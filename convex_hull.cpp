#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <bitset>
#include <iomanip>
#include <tuple>
#include <map>
#include <unordered_map>
#include <unordered_set>
#define llong long long
#define ldouble long double
#define ll long long
#define ld long double
#define int llong
 
using namespace std;
 
struct Point2D {
    int x, y;
 
    bool operator < (const Point2D &other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
 
    Point2D operator - (const Point2D &other) const {
        return {x - other.x, y - other.y};
    }
};
 
struct Line {
    llong a, b, c;
};
 
llong cross(const Point2D &A, const Point2D &B) {
    return 1LL * A.x * B.y - 1LL * A.y * B.x;
}
 
bool CW(const Point2D &A, const Point2D &B, const Point2D &C) {
    return cross(B - A, C - A) < 0;
}
 
bool CCW(const Point2D &A, const Point2D &B, const Point2D &C) {
    return cross(B - A, C - A) > 0;
}
 
vector<Point2D> Convexhull(vector<Point2D> &A) {
    sort(A.begin(), A.end());
    int n = A.size();
 
    vector<Point2D> Top, Down;
    Top.push_back(A[0]), Down.push_back(A[0]);
    for(int i = 1; i < n; ++i) {
        if (i == n - 1 || CW(A[0], A[i], A[n - 1])) {
            while (Top.size() > 1 && !CW(Top[Top.size() - 2], Top.back(), A[i])) Top.pop_back();
            Top.push_back(A[i]);
        }
 
        if (i == n - 1 || CCW(A[0], A[i], A[n - 1])) {
            while (Down.size() > 1 && !CCW(Down[Down.size() - 2], Down.back(), A[i])) Down.pop_back();
            Down.push_back(A[i]);
        }
    }
 
    vector<Point2D> ans; ans.clear();
    for(int i = 0; i < (int) Top.size(); ++i) ans.push_back(Top[i]);
    for(int i = Down.size() - 2; i > 0; --i) ans.push_back(Down[i]);
 
    return ans;
}
 
ldouble dist(const Point2D &A) {
    return sqrt(A.x * A.x + A.y * A.y);
}
 
ldouble dist(const Line &A, const Point2D &B) {
    return 1.0L * abs(A.a * B.x + A.b * B.y + A.c) / sqrt(A.a * A.a + A.b * A.b);
}
 
int n, R;
 
void hhoangcp() {
    cin >> n >> R;
    vector<Point2D> P(n, {0, 0});
    for(Point2D &a: P) cin >> a.x >> a.y;
 
    P = Convexhull(P);
}
 
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
 
    int tests = 1; //cin >> tests;
    while(tests--) hhoangcp();
 
    return 0;
}