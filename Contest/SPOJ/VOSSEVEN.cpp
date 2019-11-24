#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const long long INF = 1e18 + 1;
const int MaxN = 1e5 + 5;

string s;
int a[10 * MaxN], pos = 0, b[10 * MaxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> s;
    for(int i = s.size() - 1; i >= 0; i--) {
        if(s[i] != '7') pos = 0;
        else pos++;
        a[i] = pos;
    }
    for(int i = 0; i < s.size(); i++) {
        if(a[i]) b[a[i]]++;
    }
    for(int i = s.size() - 1; i > 0; i--) {
        b[i] += b[i + 1];
    }

    for(int i = 1; i <= s.size(); i++) {
        if(b[i] == 0) break;
        printf("%d %d\n", i, b[i]);
    }
    return 0;
}
