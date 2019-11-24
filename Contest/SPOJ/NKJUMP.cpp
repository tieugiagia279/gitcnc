#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const long long INF = 1e18 + 1;
const int MaxN = 1e5 + 5;

int n, a[1005];
vector<vector<int> > graph(1005);
stack<int> traced;
bool visit[1005], mark[1005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);

    for(int i = 1; i <= n - 2; i++) {
        for(int j = i + 1; j <= n - 1; j++) {
            int u = lower_bound(a + 1, a + n + 1, a[i] + a[j]) - a;
            int v = upper_bound(a + 1, a + n + 1, a[i] + a[j]) - a;
            for(int k = u; k < v; k++) {
                graph[i].push_back(k);
                graph[j].push_back(k);
            }
        }
    }

    long long result = 0;

    for(int i = 1; i <= n; i++) {
        ll cnt = 0;
        if(1) {
            traced.push(i);
            visit[i] = true;
            mark[i] = true;
            while(!traced.empty()) {
                ll temp = traced.top();
                traced.pop();
                cnt++;
                for(int j = 0; j < graph[temp].size(); j++) {
                    if(mark[graph[temp][j]] == false) {
                        mark[graph[temp][j]] = true;
                        traced.push(graph[temp][j]);
                        visit[graph[temp][j]] = true;
                    }
                }
            }
        }
        result = max(result, cnt);
        memset(mark, 0, sizeof(mark));
    }
    cout << result;
    return 0;
}
