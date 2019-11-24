#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a[100];
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    cout<<upper_bound(a+1,a+n+1,5)-a<<endl;
    cout<<lower_bound(a+1,a+n+1,5)-a<<endl;
    return 0;
}