#include <bits/stdc++.h>
using namespace std;


bool ss(pair<int, int> &a, pair<int, int> &b) {
    return a.second > b.second || (a.second == b.second && a.first < b.first);
}

int n, h[100005], res;
pair<int, int> a[100005];
int main() {
    freopen("input.txt", "r", stdin);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second;

    sort(a + 1, a + n + 1, ss);

    for(int i = 1; i <= n; i++) {
        cout << a[i].first << " " << a[i].second << endl;
    }
    h[1] = 1;
    res = 1;
    for(int i = 2; i <= n; i++) {
        if(a[i].first < a[h[1]].first)
            h[1] = i;
        else {
            if(a[i].first >= a[res].first) {
                res++;
                h[res] = i;
            }
            else {
                int l = 1, r = res;
                while(l < r) {
                    int m = (l + r + 1) / 2;
                    if(a[i].first > a[h[m]].first)
                        l = m;
                    else
                        r = m - 1;
                }
                if(a[h[l]].first < a[i].first && a[i].first < a[h[l + 1]].first)
                    h[l + 1] = i;
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << h[i] << " ";
    }
    cout << endl;
    cout << res;
    return 0;
}
