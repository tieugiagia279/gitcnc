#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
const long long INF = 1e18 + 1;

stack<pair<int, int> > s;
pair<int, int> p;
pair<bool, pair<int, int> > mark[55][55];
int n, m, x, y;
char a[55][55];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(mark[i][j].fi == true) continue;

            s.push(make_pair(i, j));
            mark[i][j].fi = true;

            while(!s.empty()) {
                p = s.top();
                s.pop();

                x = p.fi; y = p.se;

                for(int u = -1; u <= 1; u++)
                for(int v = -1; v <= 1; v++) {
                    if((u != 0 && v != 0) || (u == 0 && v == 0) || a[x][y] != a[x + u][y + v]) continue;
                    if(!mark[x + u][y + v].fi) {
                        s.push(make_pair(x + u, y + v));
                        mark[x + u][y + v].fi = true;
                        mark[x + u][y + v].se.fi = x;
                        mark[x + u][y + v].se.se = y;
                    }
                    else {
                        if(mark[x][y].se.fi != x + u || mark[x][y].se.se != y + v) {
                            cout << "Yes";
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout << "No";
    return 0;
}
