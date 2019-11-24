#include <bits/stdc++.h>
using namespace std;

stack<int> a;
int main()
{
    int k, h;
    cin >> k >> h;
    while(k)
    {
        a.push(k % 2);
        k /= 2;
    }
    while(!a.empty())
    {
        cout << a.top();
        a.pop();
    }
    return 0;
}
