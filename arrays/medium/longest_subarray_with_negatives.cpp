#include<bits/stdc++.h>
using namespace std;
int longest_subarray(vector<int>&arr,int target)
{
    map<long long,int>SumMap;
    long long sum=0;
    int max_len=0;
    for(int i=0;i<arr.size();i++)
    {
        sum+=arr[i];
        if(sum==target)
        {
            max_len=max(max_len,i+1);
        }
        long long rem=sum-target;
        if(SumMap.find(rem)!=SumMap.end()){
            int len=i-SumMap[rem];
            max_len=max(max_len,len);
        }
        if(SumMap.find(sum) == SumMap.end()){
            SumMap[sum]=i;
        }
    }
    return max_len;
}
int main()
{
    
}