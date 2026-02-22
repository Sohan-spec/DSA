#include <bits/stdc++.h>
using namespace std;
vector <int> two_sum_exists(vector<int> &arr, int target) //this works only for positives
{
    if(arr.empty())return {};
    int left = 0;
    int right = 0;
    long long sum = arr[0];
    while (right < arr.size())
    {
        while (left <= right && sum > target)
        {
            sum -= arr[left];
            left++;
        }
        if (sum == target)
        {
            return{left,right};
        }
        right+=1;
        if (right < arr.size())
        {
            sum += arr[right];
        }
    }
    return {};
    
}
vector<int>brute_force(const vector<int>&arr,int target){
    if(arr.empty())return {};
    vector<int>temp;
    for(int i=0;i<arr.size();i++)
    {
        for(int j=i+1;j<arr.size();j++)
        {
            if(arr[i]+arr[j]==target){
                temp.push_back(i);
                temp.push_back(j);
                return temp;
            }
        }
    }
    return {};
}
vector<int> using_hash_map(const vector<int>&arr,int target)
{
    map<long long,int>SumMap;
    for(int i=0;i<arr.size();i++)
    {
        long long a=arr[i];
        int rem=target-a;
        if(SumMap.find(rem) !=SumMap.end()){
            return {SumMap[rem],i};
        }
        SumMap[a]=i;
    }
    return {};
}
vector<int> optimal_approach(vector<int>&arr,int target)
{
    vector<pair<int,int>>temp;
    for(int i=0;i<arr.size();i++)
    {
        temp.emplace_back(arr[i],i);
    }
    sort(temp.begin(),temp.end());
    int left=0;
    int right=temp.size()-1;
    long long sum=0;
    while(left<right)
    {
        sum=temp[left].first+temp[right].first;
        if(sum<target){
            left++;
        }
        else if(sum>target){
            right--;
        }
        else{
            return{temp[left].second,temp[right].second};
        }
    }
    return {};
}
int main()
{
    vector<int> arr = {1, 3, 5, -7, 6, -3};
    vector<int>temp=using_hash_map(arr,0);
    for(int i=0;i<temp.size();i++)
    {
        cout<<temp[i]<<endl;
    }
}
