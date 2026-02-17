#include<bits/stdc++.h>
using namespace std;
void print(int n,string s){
   cout<<s<<endl;
   n--;
   if(n==0)return;
   print(n,s);
}
int main()
{
  print(10,"google");
  return 0;
}