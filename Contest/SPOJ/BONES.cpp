#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const long long INF = 1e18 + 1;
const int MaxN = 1e5 + 5;

int a, b, c, s[100], maxx = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> a >> b >> c;
    for(int i = 1; i <= a; i++) {
        for(int j = 1; j <= b; j++) {
            for(int k = 1; k <= c; k++) {
                s[i + j + k]++;
                maxx = max(maxx, s[i + j + k]);
            }
        }
    }
    for(int i = 3; i <= a + b + c; i++) {
        if(s[i] == maxx) {
            cout << i;
            break;
        }
    }
    return 0;
}
