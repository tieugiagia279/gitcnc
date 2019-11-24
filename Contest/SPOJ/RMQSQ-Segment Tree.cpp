#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll st[500005];

void update(ll id, ll l, ll r, ll i, ll v)
{
    if(i < l || i > r || l > r)
        return;
    if(l == r)
    {
        st[id] = v;
        return;
    }
    else
    {
        ll mid = (l + r) / 2;
        update(id * 2, l, mid, i, v);
        update(id * 2 + 1, mid + 1, r, i, v);

        st[id] = min(st[id * 2], st[id * 2 + 1]);
    }

}

ll get(ll id, ll l, ll r, ll u, ll v)
{
    if(v < l || r < u)
        return 1e9;

    if(u <= l && r <= v)
        return st[id];

    ll mid = (l + r) / 2;
    return min(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}
ll n, q, h, l, r;
int main()
{
    cin >> n;
    for(int i = 0; i < 4 * n; i++)
        st[i] = 1e9;
    for(int i = 1; i <= n; i++)
    {
        cin >> h;
        update(1, 1, n, i, h);
    }
    cin >> q;
    while(q--)
    {
        cin >> l >> r;
        cout << get(1, 1, n, l + 1, r + 1) << "\n";
    }
    return 0;
}
