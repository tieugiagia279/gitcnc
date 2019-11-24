#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const long long INF = 1e18 + 1;
const int MaxN = 1e6 + 5;

string text, pattern;
int z[2 * MaxN];

void Zalgorithm() {
    int L = 0, R = 0, k;
    int n = text.size();
    z[0] = n;
    for(int i = 1; i < n; i++) {
        if(i > R) {
            L = R = i;
            while(R < n && text[R - L] == text[R]) R++;
            z[i] = R - L;
            R--;
        }
        else {
            k = i - L;
            if(z[k] < R - i + 1) {
                z[i] = z[k];
            }
            else {
                L = i;
                while(R < n && text[R - L] == text[R]) R++;
                z[i] = R - L;
                R--;
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> text >> pattern;
    text = pattern + "$" + text;

    int tsize = text.size(), psize = pattern.size();
    Zalgorithm();
    for(int i = 1; i < tsize; i++) {
        if(z[i] == psize)
            cout << i - psize << " ";
    }
    return 0;
}
