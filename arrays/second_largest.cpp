#include<bits/stdc++.h>
using namespace std;
int sl(vector<int>&arr)
{
    if(arr.size()<2)return -1;
    int largest=INT_MIN;
    int secl=INT_MIN;

    for(int num:arr)
    {
      if(num>largest)
      {
        secl=largest;
        largest=num;
      }
      else if(num>secl && num <largest){
        secl=num;
      }
    }
    return secl;
}
int main()
{
    vector<int>arr={8,8,7,6,5};
    cout<<sl(arr);
}