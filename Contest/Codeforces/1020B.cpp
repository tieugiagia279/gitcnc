#include <bits/stdc++.h>
#define fi frist
#define se second
using namespace std;
typedef long long ll;
const long long INF = 1e18 + 1;
int n, a[1005];
stack<int> s;
bool check[1005];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) check[j] = false;
        s.push(i);
        while(!s.empty()) {
            int v = s.top();
            if(check[v] == false) {
                check[v] = true;
                s.push(a[v]);
            }
            else {
                cout << v << " ";
                break;
            }
        }
    }
    return 0;
}
