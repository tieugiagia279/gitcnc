#include <bits/stdc++.h>
#define fi frist
#define se second
using namespace std;
typedef long long ll;
const long long INF = 1e18 + 1;

deque<int> s;
int n, k, t, a[17005];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> t;
    while(t--) {
        cin >> n >> k;
        for(int i = 0; i < n; i++) cin >> a[i];

        for(int i = 0; i < n; i++) {
            while(!s.empty() && s.front() <= i - k) s.pop_front();
            while(!s.empty() && a[s.back()] >= a[i]) s.pop_back();

            s.push_back(i);
            if(i >= k - 1)
                cout << a[s.front()] << " ";
        }
        s.clear();
        cout << endl;
    }
    return 0;
}
