#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long

const long long MAXN = 1e5 + 7;
const long long INF  = 1e9 + 7;
using namespace std;

ll n, k, a[MAXN], res = 0, phantuz = 1;
deque<ll> Min, Max;
int main() {
//    freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);


    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) {
        while(!Min.empty() && a[i] <= a[Min.back()]) Min.pop_back();
        Min.push_back(i);

        while(!Max.empty() && a[i] >= a[Max.back()]) Max.pop_back();
        Max.push_back(i);

        while(!Max.empty() && !Min.empty() && a[Max.front()] - a[Min.front()] > k) {
            if(Max.front() < Min.front()) {
                phantuz = Max.front() + 1;
                Max.pop_front();
            }
            else if(Min.front() < Max.front()) {
                phantuz = Min.front() + 1;
                Min.pop_front();
            }
            else {
                Max.pop_front();
                Min.pop_front();
                phantuz = Max.front() + 1;
            }
        }
        res = max(res, i - phantuz + 1);
    }
    cout << res;
    return 0;
}
