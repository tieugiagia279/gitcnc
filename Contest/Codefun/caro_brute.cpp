#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const long long INF  = 1e18 + 1;
const long long MAXN =  1e5 + 5;
const long long MOD  =  1e9 + 7;

string s = "GOOOOTTTTTTTTTTTTTTTTTTTT";
ll res = 0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    //freopen("test.inp", "r", stdin);
    freopen("caro.txt", "w", stdout);

    for(int i = 0; i < s.size(); i++) {
        cout << s[i];
        if((i + 1) % 5 == 0) cout << endl;
    }
    cout << endl;
    while(next_permutation(s.begin(), s.end())) {
        for(int i = 0; i < s.size(); i++) {
            cout << s[i];
            if((i + 1) % 5 == 0) cout << endl;
        }
        cout << endl;
        res++;
    }
    cout << res;
    return 0;
}
