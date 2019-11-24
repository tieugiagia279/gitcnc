#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int tonguoc(int a)
{
    int su = 1;
    int m = sqrt(a);
    if(a < 2) return su;
    for(int i = 2; i <= m; i++)
        if(a % i == 0) su = su + i + a / i;

    if(a == m * m) su -= m;
    return su;
}

int l, r, res = 0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> l >> r;
    for(int i = l; i <= r; i++)
        if(i < tonguoc(i)) res++;

    cout << res;
    return 0;
}
