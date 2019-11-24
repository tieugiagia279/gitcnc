#include <bits/stdc++.h>
using namespace std;
int stmax[200005], stmin[200005], a[50005];

void build_max(int id, int l, int r)
{
    if(l > r) return;
    if(l == r) stmax[id] = a[l];
    else
    {
        int m = (l + r) / 2;
        build_max(id * 2, l, m);
        build_max(id * 2 + 1, m + 1, r);

        stmax[id] = max(stmax[id * 2], stmax[id * 2 + 1]);
    }
}

void build_min(int id, int l, int r)
{
    if(l > r) return;
    if(l == r) stmin[id] = a[l];
    else
    {
        int m = (l + r) / 2;
        build_min(id * 2, l, m);
        build_min(id * 2 + 1, m + 1, r);

        stmin[id] = min(stmin[id * 2], stmin[id * 2 + 1]);
    }
}

int get_max(int id, int l, int r, int u, int v)
{
    if(v < l || r < u) return -1e9;
    if(u <= l && r <= v) return stmax[id];

    int m = (l + r) / 2;
    return max(get_max(id * 2, l, m, u, v), get_max(id * 2 + 1, m + 1, r, u, v));
}

int get_min(int id, int l, int r, int u, int v)
{
    if(v < l || r < u) return 1e9;
    if(l >= u && r <= v) return stmin[id];

    int m = (l + r) / 2;
    return min(get_min(id * 2, l, m, u, v), get_min(id * 2 + 1, m + 1, r, u, v));
}
int n, q, x, y, k;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    build_max(1, 1, n);
    build_min(1, 1, n);

    while(q--)
    {
        cin >> x >> y;
        cout << get_max(1, 1, n, x, y) - get_min(1, 1, n, x, y) << "\n";
    }
    return 0;
}
