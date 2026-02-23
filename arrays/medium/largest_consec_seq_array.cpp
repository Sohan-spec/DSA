#include<bits/stdc++.h>
using namespace std;
int brute_force(vector<int>&arr){
    if(arr.empty())return 0;
    int count=0;int max_count=0;
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size()-1;i++)
    {
        if(arr[i]==arr[i+1])continue;
        if((arr[i+1]-arr[i])==1){
            count++;
            max_count=max(max_count,count);
        }
        else{
            count=0;
        }
    }
    return max_count+1;
}
int main()
{
    vector<int>arr={100, 4, 200, 1, 3, 2};
    cout<<brute_force(arr);
}