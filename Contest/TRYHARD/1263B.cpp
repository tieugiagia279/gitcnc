#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define vll vector<long long>
#define pll pair<long long,long long>
#define vpll vector<pll>
const long long MAXN = 1e5 + 7;
const long long INF  = 1e9 + 7;
using namespace std;

ll t, n, res;
string a, x;
map<string, bool> s;
vector<string> sa;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);

    cin >> t;
    while(t--) {
        s.clear();
        sa.clear();
        cin >> n;
        res = 0;
        for(int i = 1; i <= n; i++) {
            cin >> a;
            x = a;
            if(s[a] == false) s[a] = true;
            else {
                for(int i = 0; i <= 3; i++) {
                    ll flag = 0;
                    x = a;
                    for(char j = '0'; j <= '9'; j++) {
                        x[i] = j;
                        if(s[x] == false) {
                            s[x] = true;
                            res++;
                            flag = 1;
                            break;
                        }
                    }
                    if(flag == 1) break;
                }
            }
            sa.push_back(x);
        }
        cout << res << "\n";
        for(vector<string>::iterator it = sa.begin(); it != sa.end(); it++)
            cout << *(it) << "\n";
    }
    return 0;
}
