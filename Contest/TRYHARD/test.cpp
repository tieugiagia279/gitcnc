#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define vll vector<long long>
#define vvll vector<vll>
#define pll pair<long long,long long>
#define vpll vector<pll>
const long long MAXN = 1e5 + 7;
const long long INF  = 1e9 + 7;
using namespace std;

ll m, n, x;
vvll a(105);

void viewA() {
    for(int i = 1; i <= m; i++) {
        for(int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);

    cin >> m >> n;
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> x;
            a[i].push_back(x);
        }
    }
    viewA();
    return 0;
}
