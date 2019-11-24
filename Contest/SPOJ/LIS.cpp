#include <bits/stdc++.h>
#define fi frist
#define se second
using namespace std;
typedef long long ll;
const long long INF = 1e18 + 1;

ll a[50005], h[50005], n, W, res;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n >> W;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    h[1] = 1; res = 1;
    for(int i = 2; i <= n; i++) {
        if(a[i] < a[h[1]]) {
            h[1] = i;
        }
        else {
            if(a[i] > a[h[res]]) {
                res++;
                h[res] = i;
            }
            else {
                int l = 1, r = res;

                while(l < r) {
                    int m = (l + r + 1) / 2;
                    if(a[i] > a[h[m]])
                        l = m;
                    else
                        r = m - 1;
                }
                int m = l;
                if(a[i] > a[h[m]] && a[i] < a[h[m + 1]])
                    h[m + 1] = i;
            }
        }
    }
    cout << res;
    return 0;
}
