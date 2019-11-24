#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const long long INF = 1e18 + 1;

int n, m, x, y, num[10005], low[10005], cnt = 0, res = 0;
vector< vector<int> > a(10005);
stack<int> s;

void tarjan(int k) {
    low[k] = num[k] = ++cnt;
    s.push(k);

    for(int i = 0)
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        cin >> x >> y;
        a[x].push_back(y);
    }

    for(int i = 1; i <= n; i++)
        a[i].push_back(0);


    return 0;
}
