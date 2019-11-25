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

    float res;
    for(int i = 1; i <= n; i++) {
        res = -INF;
        for(int j = i + 1; j <= n; j++) {
            float x = (a[j].se - a[i].se) / (float)(a[j].fi - a[i].fi);
            if(x >= res) {
                b[i].fi++;
                res = x;
            }
        }
        res = INF;
        for(int k = i - 1; k >= 1; k--) {
            float x = (a[k].se - a[i].se) / (float)(a[k].fi - a[i].fi);
            if(x <= res) {
                b[i].fi++;
                res = x;
            }
        }
    }

    sort(b + 1, b + n + 1, ss);
    for(int i = 1; i <= n; i++) cout << b[i].fi << endl;
    return 0;
}

