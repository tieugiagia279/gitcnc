#include <bits/stdc++.h>
#define fi frist
#define se second
using namespace std;
typedef long long ll;
const long long INF = 1e18 + 1;
int n, a[1005][1005], ax, ay, bx, by, cx, cy;
stack<pair<int, int> > s;
pair<int, int> p;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    cin >> n;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == ax || j == ay || (ax - i) == (ay - j) || (ax + i) == (ay + j) || (ax - i) == (j - ay) || (i - ax) == (ay - j))
                a[i][j] = 1;
        }
    }
    s.push(make_pair(bx, by));
    a[bx][by] = 1;
    while(!s.empty()) {
        p = s.top();
        bx = p.first;
        by = p.second;
        s.pop();
        if(bx > n || bx < 1 || by > n || by < 1) continue;
        if(bx == cx && by == cy) {
            cout << "YES";
            exit(0);
        }
        for(int i = -1; i <= 1; i++) {
            for(int j = -1; j <= 1; j++) {
                if(a[bx + i][by + j] == 0) {
                    s.push(make_pair(bx + i, by + j));
                    a[bx + i][by + j] = 1;
                }
            }
        }
    }
    cout << "NO";
    return 0;
}
