#include<bits/stdc++.h>
using namespace std;
void print(int n){
    static int i=1;
   cout<<i<<endl;
   i++;
   if(i>n)return;
   print(n);
}
int main()
{
  print(10);
  return 0;
}