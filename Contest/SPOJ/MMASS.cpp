#include <bits/stdc++.h>
using namespace std;

stack<int> a;
char x;
int su, k;

int main()
{
    //freopen("STPAR.inp", "r", stdin);
    while(cin >> x)
    {
        if(x == ' ')
            continue;
        if(x != ')')
        {
            if(x == '(') a.push(0);
            else if(x == 'C') a.push(12);
            else if(x == 'H') a.push(1);
            else if(x == 'O') a.push(16);
            else if(x >= '2' && x <= '9')
            {
                k = a.top();
                a.pop();
                k *= int(x - '0');
                a.push(k);
            }
        }
        else
        {
            su = 0;
            while(a.top() != 0)
            {
                su += a.top();
                a.pop();
            }
            a.pop();
            a.push(su);
        }
    }
    su = 0;
    while(!a.empty())
    {
        su += a.top();
        a.pop();
    }
    cout << su;
    return 0;
}
