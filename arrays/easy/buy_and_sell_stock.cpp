#include<bits/stdc++.h>
using namespace std;
int brute_force(vector<int>&arr){
    int max_profit=INT_MIN;int profit=0;
    for(int i=0;i<arr.size()-1;i++)
    {
        for(int j=arr.size()-1;j>i;j--){
            profit=arr[j]-arr[i];
            if(profit>max_profit){
                max_profit=profit;
            }
        }
    }
    if(max_profit<=0)return 0;
    return max_profit;
}
int optimal(vector<int>&arr){
    int mini=INT_MAX;
    int max_profit=0;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]<mini){
            mini=arr[i];
        }
        else{
            max_profit=max(max_profit,arr[i]-mini);
        }
    }if(max_profit<=0)return 0;
    return max_profit;
}
int main()
{
    vector<int>arr={7,6,4,3,1};
    cout<<optimal(arr);
    return 0;
}