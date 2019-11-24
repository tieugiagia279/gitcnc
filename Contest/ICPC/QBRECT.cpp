#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, k[1000005], h[100005], l[100005], r[100005], su1, su2;
stack<ll> a, b;
int main()
{
    cin >> m >> n;
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
    su1 = 0;
    for(int i = 1; i <= n; i++)
        su1 = max(su1, h[i] * (r[i] - l[i] - 1));

    for(int i = 1; i <= n; i++) h[i] = m - h[i];
    for(int i = 0; i <= n + 1; i++) {
        l[i] = r[i] = 0;
    }

    while(!a.empty()) a.pop();

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
    su2 = 0;
    for(int i = 1; i <= n; i++)
        su2 = max(su2, h[i] * (r[i] - l[i] - 1));

    cout << max(su1, su2);
    return 0;
}
