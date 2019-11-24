#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll tree[200005], lazy[200005];

void down(ll id, ll l, ll r) {
    ll value = lazy[id];
    lazy[id * 2] += value;
    tree[id * 2] += (r - l + 1) * value;

    lazy[id * 2 + 1] += value;
    tree[id * 2 + 1] += (r - l + 1) * value;

    lazy[id] = 0;
}

void update(ll id, ll l, ll r, ll u, ll v, ll val) {
    if(l > v || r < u || l > r) return;

    if(u <= l && r <= v) {
        tree[id] += (r - l + 1) * val;
        lazy[id] += val;
        return;
    }
    ll m = (l + r) / 2;

    down(id, l, r);

    update(id * 2, l, m, u, v, val);
    update(id * 2 + 1, m + 1, r, u, v, val);

    tree[id] = (tree[id * 2] + tree[id * 2 + 1]);
}

ll get(ll id, ll l, ll r, ll u, ll v) {
    if(l > v || r < u) return 0;

    if(u <= l && r <= v) return tree[id];

    ll m = (l + r) / 2;

    down(id, l, r);

    return (get(id * 2, l, m, u, v) + get(id * 2 + 1, m + 1, r, u, v));
}

ll n, m, type, val, x, y;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> n >> m;
    while(m--) {
        cin >> type >> x >> y;
        if(type == 0) {
            cin >> val;
            update(1, 1, n, x, y, val);
        } else {
            cout << get(1, 1, n, x, y) << "\n";
        }
    }
    return 0;
}
