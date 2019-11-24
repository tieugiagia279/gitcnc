#include <bits/stdc++.h>
#define fi frist
#define se second
using namespace std;
typedef long long ll;
const long long INF = 1e18 + 1;

ll n, m, a[1005][1005], h[1005], l[1005], r[1005], area = 0;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    for(int i = 1; i <= m; i++)
    return 0;
}

l[j] = j;
while(h[l[j] - 1] >= h[j]) l[j] = l[ l[j] - 1 ];
while()
