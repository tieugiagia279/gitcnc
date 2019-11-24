#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

//Hàm kiểm tra một điểm nằm trong hình chữ nhật hay không!!
int pnpoly(float *mx, float *my, float a, float b)
{
  int i, j, c = 0;
  for (i = 0, j = 3; i < 4; j = i++) 
    if (((my[i] > b) != (my[j] > b)) && (a < (mx[j] - mx[i]) * (b - my[i]) / (my[j] - my[i]) + mx[i]))
       c = !c;
  return c;
}


int main()
{
	
	return 0;
}