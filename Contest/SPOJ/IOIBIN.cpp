#include <bits/stdc++.h>
using namespace std;

int traced(int a[], int x)
{
    while(a[x] != x)
        x = a[x];
    return x;
}
int q, a[100005], x, y, m, pos;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> q;
    while(q--)
    {
        cin >> x >> y >> m;
        if(!a[x]) a[x] = x;
        if(!a[y]) a[y] = y;
        if(m == 2)
        {
            if(traced(a, x) == traced(a, y)) cout << 1;
            else cout << 0;
            cout << "\n";
        }
        else if(m == 1)
            a[traced(a, y)] = traced(a, x);
    }
    return 0;
}
