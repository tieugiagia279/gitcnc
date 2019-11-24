#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const long long INF = 1e18 + 1;
const int MaxN = 1e5 + 5;

ll n, m, res = 0, k, x[1005];
vector<int> a, b;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n >> m;
    for(int i = n; i >= 1; i--) {cin >> x[i];}
    for(int i = 1; i <= n; i++) {a.push_back(x[i]);}
    for(int i = m; i >= 1; i--) {cin >> x[i];}
    for(int i = 1; i <= m; i++) {b.push_back(x[i]);}

    if(n > m) for(int i = m; i < n; i++) b.push_back(0);
    else if(n < m) for(int i = n; i < m; i++) a.push_back(0);

    for(int i = 0; i < a.size(); i++) {
        a[i] += b[i];
        if(i == a.size() - 1 && a[i] > 9) a.push_back(0);

        a[i + 1] += a[i] / 10;
        a[i] %= 10;
    }
    k = 0;
    for(int i = a.size() - 1; i >= 0; i--) {
        k++;
        cout << a[i];
        if(k == 50) {
            cout << "\n";
            k = 0;
        }
    }
    return 0;
}
