#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const long long INF = 1e18 + 1;
const int MaxN = 1e5 + 5;
string a, b, c;
int z[2 * MaxN];
void Z() {
    int l = 0, r = 0, k;
    int n = c.size();
    z[0] = n;
    for(int i = 1; i < n; i++) {
        if(i > r) {
            r = l = i;
            while(r < n && c[r - l] == c[r]) r++;
            z[i] = r - l; r--;
        }
        else {
            k = i - l;
            if(z[k] < r - i + 1) {
                z[i] = z[k];
            }
            else {
                l = i;
                while(r < n && c[r - l] == c[r]) r++;
                z[i] = r - l; r--;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> a >> b;
    c = b + "$" + a;
    Z();

    for(int i = 0; i < b.size(); i++) {
        if(z[c.size() - b.size() + i] == b.size() - i) {
            a.erase(c.size() - 2 * b.size() + i - 1, b.size() - i);
            break;
        }
    }
    cout << a << b;
    return 0;
}
