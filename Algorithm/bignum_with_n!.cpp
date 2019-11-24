#include <bits/stdc++.h>
using namespace std;

vector<int> bn;
int n;
int main()
{
    cin >> n;
    bn.push_back(1);
    for(int i = 2; i <= n; i++)
    {
        for(int j = 0; j < bn.size(); j++)
            bn[j] *= i;
        for(int j = 0; j < bn.size(); j++)
        {
            if(bn[j] < 10)
                continue;
            if(j == bn.size() - 1)
                bn.push_back(0);
            bn[j + 1] += bn[j] / 10;
            bn[j] = bn[j] % 10;
        }
    }
    for(int i = bn.size() - 1; i >= 0; i--)
        cout << bn[i];
    return 0;
}
