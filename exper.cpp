#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const long long INF  = 1e18 + 1;
const long long MAXN =  1e5 + 5;
const long long MOD  =  1e9 + 7;

bool ss(pair<ll,ll> a, pair<ll,ll> b) {
    return a.se < b.se;
}

bool check(ll xa, ll ya, ll xb, ll yb, ll xc, ll yc) {
    ll x = xc - xa;
    ll y = xb - xc;
    if(ya * y + yb * x > (xb - xa) * yc)
        return true;
    else return false;
}

bool check2(ll xa, ll ya, ll xb, ll yb, ll xc, ll yc) {
    if(yc <= ya || yc <= yb) return true;
    else return false;
}

ll n, here[MAXN];
pair<ll,ll> a[MAXN], b[MAXN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    freopen("exper.inp", "r", stdin);
    freopen("exper.out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].fi >> a[i].se;
        b[i].fi = a[i].fi;
        b[i].se = i;
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);

    for(int i = 1; i <= n; i++) {
        b[i].fi = 0;
    }

    for(int i = 1; i <= n - 1; i++) {
        for(int j = i + 1; j <= n; j++) {
            ll flag = 0;
            for(int k = i + 1; k <= j - 1; k++) {
                if(check2(a[i].fi, a[i].se, a[j].fi, a[j].se, a[k].fi, a[k].se) == false) {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) {
                b[i].fi++;
                b[j].fi++;
            }
        }
    }

    sort(b + 1, b + n + 1, ss);
    for(int i = 1; i <= n; i++) cout << b[i].fi << " ";
    return 0;
}

