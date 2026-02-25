#include<bits/stdc++.h>
using namespace std;
int optimal_soln(vector<int>&arr,int target)
{
    map<long long,int>SumMap;
    long long sum=0;
    int count=0;
    for(int i=0;i<arr.size();i++)
    {
        sum+=arr[i];
        long long rem=sum-target;
        if(SumMap.find(rem)!=SumMap.end()){
            count+=SumMap[rem];
        }
        SumMap[sum]++;
    }
    return count;
}
int main()
{
    vector<int>arr={1,2,3};
    cout<<optimal_soln(arr,3);
}