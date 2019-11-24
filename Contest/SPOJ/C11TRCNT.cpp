#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const long long INF = 1e9 + 1;

ll num_air(ll x) {
    return (x * (x - 1) * (x - 2)) / 6;
}

bool check(ll a, ll b, ll x, ll y, ll m, ll n) {
    if((m - a) * (y - b) == (n - b) * (x - a)) return true;
    else return false;
}

ll n, res = 0, peak[205];
pair<ll, ll> a[205];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n;
    for(ll i = 1; i <= n; i++) cin >> a[i].fi >> a[i].se;

    for(ll i = 1; i <= n - 2; i++) {
        for(ll j = i + 1; j <= n - 1; j++) {
            for(ll k = j + 1; k <= n; k++) {
                if(check(a[i].fi , a[i].se, a[j].fi, a[j].se, a[k].fi, a[k].se)) {
                    peak[i]++;
                    peak[j]++;
                    peak[k]++;
                }
            }
        }
    }

    res = num_air(n);
    ll temp = 0, maxx = 0, pos = 0;

    for(ll i = 1; i <= n; i++) {
        temp += peak[i];
    }
    res -= temp / 3;

    for(ll i = 1; i <= n; i++) {
        if(peak[i] > maxx) {
            maxx = peak[i];
            pos = i;
        }
    }
    cout << res << " " << pos;
    return 0;
}
