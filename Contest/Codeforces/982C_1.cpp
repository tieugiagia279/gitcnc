#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const long long INF = 1e18 + 1;

int n, cnt[100005], cut = 0, visit[100005];
vector< vector<int> > s(100005);
queue<int> star;

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
        cnt[x]++;
        cnt[y]++;
    }

    for(int i = 1; i<= n; i++) {
        if(cnt[i] == 1) star.push(i);
    }

    while(!star.empty()) {
        int poit = star.top();
        star.pop();
    }
    return 0;
}
