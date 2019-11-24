#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const long long INF = 1e18 + 1;

int n, x, y, visit[100005], papa[100005], cut = 0;
vector<vector<int> > s(100005);

int DFS(int k) {
    visit[k] = 1;
    int cnt = 1;

    for(int i = 0; i < s[k].size(); i++) {
        int child = s[k][i];
//        if(child == papa[k]) continue;

        if(visit[child] == 0) {
//            papa[child] = k;
            cnt += DFS(child);
        }
    }

    if(cnt % 2 == 0) cut++;
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n;
    if(n % 2) {cout << -1; return 0;}

    for(int i = 1; i < n; i++) {
        cin >> x >> y;
        s[x].push_back(y);
        s[y].push_back(x);
    }
    DFS(1);
    cout << cut - 1;
    return 0;
}
