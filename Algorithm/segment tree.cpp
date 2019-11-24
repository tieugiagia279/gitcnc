#include <bits/stdc++.h>
using namespace std;

int T[10230997];
int n, m;

int max(int a, int b){
    return a > b ? a : b;
}

int query(int node, int l, int r, int u, int v){
    if (v < l || r < u || l > r) {
            return 0;
    }
    if (u <= l && l <= r && r<=v)
        return T[node];
    int mid = (l + r) / 2;
    int q1 = query(node * 2, l, mid, u, v);
    int q2 = query(node * 2 + 1, mid + 1, r, u, v);
    return max(q1, q2);
}

void update(int node, int l, int r, int i, int v){
    if (i < l || i > r || l > r)
        return;

    if (l != r){
        update(node * 2, l, (l + r) / 2, i, v);
        update(node * 2 + 1, (l + r) / 2+ 1, r, i, v);
        T[node] = max(T[node * 2], T[node * 2 + 1]);
    }
    else T[node] += v;
}

int main(){
    int p, q, c, x;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> x;
        update(1, 1, n, i, x);
    }
    while (m--){
        cin >> c >> p >> q;
        if (c == 1) update(1, 1, n, p, q);
        if (c == 2) cout << query(1, 1, n, p, q) << '\n';
    }
    return 0;
}
