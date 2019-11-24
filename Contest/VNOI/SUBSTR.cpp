#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const long long INF  = 1e18 + 1;
const long long MAXN =  1e6 + 5;
const long long MOD  =  1e9 + 7;
int z[2 * MAXN];

void z_function(string text) {
    ll l = 0, r = 0, n;
    n = text.size();
    z[0] = n;
    for(int i = 1; i < n; i++) {
        if(i > r) {
            r = l = i;
            while(r < n && text[r] == text[r - l]) r++;
            z[i] = r - l;
            r--;
        }
        else {
            ll k = i - l;
            if(z[k] < r - i + 1) {
                z[i] = z[k];
            }
            else {
                l = i;
                while(r < n && text[r] == text[r - l]) r++;
                z[i] = r - l;
                r--;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);

    string a, b;
    cin >> a >> b;
    a = b + "$" + a;
    z_function(a);

    for(int i = 1; i < a.size(); i++) {
        if(z[i] == b.size()) {
            cout << i - b.size()<< " ";
        }
    }
    return 0;
}
