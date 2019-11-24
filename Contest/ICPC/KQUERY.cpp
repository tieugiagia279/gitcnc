#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long

const long long MAXN = 1e5 + 7;
const long long INF  = 1e9 + 7;
using namespace std;

ll node[2 * MAXN];

void update(ll id, ll l, ll r, ll i, ll v) {
    if(i < l || r < i || r < l) return;
    if(l == r) node[id] = v;
    else {
        ll m = (l + r) / 2;
        update(id * 2, l, m, i, v);
        update(id * 2 + 1, m + 1, r, i, v);
        node[id] = node[id * 2] + node[id * 2 + 1];
    }
}

ll query(ll id, ll l, ll r, ll u, ll v) {
    if(r < u || v < l || r < l) return 0;

    if(u <= l && l <= r && r <= v) return node[id];
    else {
        ll m = (l + r) / 2;
        return query(id * 2, l, m, u, v) + query(id * 2, m + 1, r, u, v);
    }
}
ll n, m, q, x, y, z;
int main() {
//    freopen("test.inp", "r", stdin);
//    freopen("test.out", "w", stdin);


    cin >> n;
    return 0;
}
