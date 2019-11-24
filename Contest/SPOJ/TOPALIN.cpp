#include <bits/stdc++.h>
using namespace std;

string s;
int res = 0, cnt[300], root[300];

int tra(int x) {
    while(root[x] != x)
        x = root[x];
    return x;
}
int st, en;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//    freopen("input.txt", "r", stdin);
    for(int i = 0; i < 260; i++) {
        cnt[i] = 0;
        root[i] = i;
    }
    getline(cin, s);
    int n = s.size();

    for(int i = 0; i < n; i++)
        cnt[(int)s[i]]++;

    for(int i = 0; 2 * (i + 1) <= n; i++) {
        st = (int)s[i];
        en = (int)s[n - 1 - i];

        if(tra(st) != tra(en)) {
            if(cnt[st] < cnt[en]) {
                root[tra(st)] = tra(en);
                res += cnt[st];
            }
            else {
                root[tra(en)] = tra(st);
                res += cnt[en];
            }
        }
    }
    cout << res;
    return 0;
}
