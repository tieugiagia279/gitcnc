#include <bits/stdc++.h>
#define fi frist
#define se second
using namespace std;
typedef long long ll;
const long long INF = 1e18 + 1;

stack<int> s;
vector<int> a[100005], b[100005];

int n, m, cat[100005], mark[100005], x, y, res = 0;
bool dx[100005];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> cat[i];

    for(int i = 1; i < n; i++) {
        cin >> x >> y;
        b[x].push_back(y);
        b[y].push_back(x);
    }

    s.push(1);
    while(!s.empty()) {
        int apex = s.top();
        s.pop();
        dx[apex] = true;
        for(int i = 0; i < b[apex].size(); i++) {
            if(dx[b[apex][i]] == false) {
                s.push(b[apex][i]);
                a[apex].push_back(b[apex][i]);
            }
        }
    }

    s.push(1);
    if(cat[1]) mark[1]++;
    while(!s.empty()) {
        int apex = s.top();
        s.pop();
        if(a[apex].size() == 0) res++;
        for(int i = 0; i < a[apex].size(); i++) {
            if(cat[a[apex][i]]) mark[a[apex][i]] = mark[apex] + 1;
            if(mark[a[apex][i]] <= m) s.push(a[apex][i]);
        }
    }

    cout << res;
    return 0;
}
