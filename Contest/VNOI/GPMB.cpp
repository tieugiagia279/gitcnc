#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const long long INF  = 1e18 + 1;
const long long MAXN =  1e5 + 5;
const long long MOD  =  1e9 + 7;

pair<ll, ll> b[40 * MAXN], a[1505];
ll res[40 * MAXN], c[40 * MAXN], sub[1505], n;
void brute() {
    ll k = 0, result = 0;
    for(int i = 1; i < n; i++) {
        for(int j = i + 1; j <= n; j++) {
            k++;
            b[k].se = a[i].fi - a[j].fi;
            b[k].fi = a[j].se - a[i].se;
            c[k] = - (b[k].fi * a[i].fi + b[k].se * a[i].se);
        }
    }

    for(int i = 1; i <= k; i++) {
        for(int j = 1; j <= n; j++) {
            if(b[i].fi * a[j].fi + b[i].se * a[j].se + c[k] == 0) {
                res[i] += sub[j] * sub[j] + 5;
            }
        }
    }
    cout << *max_element(res + 1, res + k + 1);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].fi >> a[i].se >> sub[i];
    }
    brute();
    return 0;
}
