//Thuật toán truy hồi tối ưu phân tích số

#include <bits/stdc++.h>
using namespace std;
long a[1000];                       // chỉ cần 1 mảng để lưu các giá trị
long m, n, v;

int main()
{
    cin>>n;
    a[0] = 1;                       // khởi tạo mảng 1 chiều a lưu dòng 0 của bảng
    for(m=1;m<=n;m++)               // dùng a để tính lại chính nó
    {
        for(v=m;v<=n;v++)
        {
            a[v] = a[v] + a[v-m];
        }
    }
    for(m=1;m<=n;m++)
    {
        cout<<a[m]<<" ";
    }
    return 0;
}
