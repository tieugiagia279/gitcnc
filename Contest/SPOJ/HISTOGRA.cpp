#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, h[100005], l[100005], r[100005], su;
stack<ll> a, b;
int main()
{
    while(1)
    {
        su = 0;
        cin >> n;
        if(n == 0) break;
        for(int i = 1; i <= n; i++) cin >> h[i];
        for(int i = 1; i <= n; i++)
        {
            if(a.empty() || !a.empty() && (h[i] >= h[a.top()]))
                a.push(i);
            else
            {
                r[a.top()] = i;
                a.pop();
                i--;
            }
        }
        while(!a.empty())
        {
            r[a.top()] = n + 1;
            a.pop();
        }
        for(int i = n; i >= 1; i--)
        {
            if(b.empty() || !b.empty() && (h[i] >= h[b.top()]))
                b.push(i);
            else
            {
                l[b.top()] = i;
                b.pop();
                i++;
            }
        }
        while(!b.empty())
        {
            l[b.top()] = 0;
            b.pop();
        }
        su = 0;
        for(int i = 1; i <= n; i++)
            su = max(su, h[i] * (r[i] - l[i] - 1));
        cout << su << "\n";
    }
    return 0;
}
