#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long

const long long MAXN = 1e5 + 7;
const long long INF  = 1e9 + 7;
using namespace std;

ll n, m, a[MAXN];
int main() {
    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i < n; i++) {
        if(binary_search(a + 1, a + n + 1, a[i] + m) == true) {
            cout << a[i] << " " << a[i] + m;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
