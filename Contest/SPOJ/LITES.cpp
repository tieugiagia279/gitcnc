#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll tree[200005], lazy[200005];

void down(ll id, ll l, ll r) {
    if(lazy[id] == 0) return;
    ll m = (r + l) / 2;
    lazy[id * 2] = 1 - lazy[id * 2];
    tree[id * 2] = m - l + 1 -  tree[id * 2];

    lazy[id * 2 + 1] = 1 - lazy[id * 2 + 1];
    tree[id * 2 + 1] = r - m -  tree[id * 2 + 1];

    lazy[id] = 0;
}

void update(ll id, ll l, ll r, ll u, ll v) {
    if(l > v || r < u || l > r) return;
    if(u <= l && r <= v) {
        tree[id] = r - l + 1 - tree[id];
        lazy[id] = 1 - lazy[id];
        return;
    }
    ll m = (l + r) / 2;

    down(id, l, r);

    update(id * 2, l, m, u, v);
    update(id * 2 + 1, m + 1, r, u, v);

    tree[id] = tree[id * 2] + tree[id * 2 + 1];
}

ll get(ll id, ll l, ll r, ll u, ll v) {
    if(l > v || r < u) return 0;

    if(u <= l && r <= v) return tree[id];

    ll m = (l + r) / 2;

    down(id, l, r);
    tree[id] = tree[id * 2] + tree[id * 2 + 1];
    return (get(id * 2, l, m, u, v) + get(id * 2 + 1, m + 1, r, u, v));
}

ll n, m, type, x, y;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> n >> m;
    while(m--) {
        cin >> type >> x >> y;
        if(type == 0) {
            update(1, 1, n, x, y);
        } else {
            cout << get(1, 1, n, x, y) << "\n";
        }
    }
    return 0;
}
