#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const long long INF = 1e18 + 1;
const int MaxN = 1e5 + 5;

stack<pair<int, int> >s;
int n, a;
long long res = 0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);



    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a;
        while(!s.empty() && s.top().fi < a)
            res += s.top().se, s.pop();
        if(!s.empty()) {
            if(s.top().fi == a) {
                res += s.top().se++;
                if(s.size() > 1) ++res;
            } else {
                ++res;
                s.push(make_pair(a, 1));
            }
        } else {
            s.push(make_pair(a, 1));
        }
    }
    cout << res;
    return 0;
}
