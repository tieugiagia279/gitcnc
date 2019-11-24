#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const long long INF  = 1e18 + 1;
const long long MAXN =  1e5 + 5;
const long long MOD  =  1e9 + 7;

double tinh_i(ll x1, ll y1, ll x2, ll y2) {
    return (x1 * x1 + y1 * y1 - x2 * x2 - y2 * y2) / double(2 * x1 - 2 * x2);
}

double kc(ll x1, ll y1, ll x2, ll y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

ll t, x, xx, y, yy;
double res, m;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
//
    freopen("MINDIST.inp", "r", stdin);
    freopen("MINDIST.out", "w", stdout);

    cin >> t;
    while(t--) {
        cin >> x >> y >> xx >> yy;
        m = tinh_i(x, y, xx, yy);
        res = kc(x, y, m, 0) + kc(xx, yy, m, 0);
        cout << int(res) << endl;
    }
    return 0;
}
