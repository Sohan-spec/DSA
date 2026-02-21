#include<bits/stdc++.h.>
using namespace std;
int find_non_repeated_number(const vector<int>&arr) //this is O(nlogm) + O(n/2 + 1)
{
    unordered_map<long long,int>array_map;
    for(int i=0;i<arr.size();i++)
    {
        array_map[arr[i]]+=1;
    }
    for(auto it:array_map){
        if(it.second==1)
        {
            return it.first;
        }
    }
    return -1;
}
int using_arrays_hashing(const vector<int>&arr){
    int maxi=*max_element(arr.begin(),arr.end());
    vector<int>temp(maxi+1);
    for(int i:arr){
        temp[i]+=1;
    }
    for(int i=0;i<temp.size();i++)
    {
        if(temp[i]==1){
            return i;
        }
    }
    return -1;

}
int optimal_approach(vector<int>&arr)
{
    int xorr=0;
    for(int i=0;i<arr.size();i++)
    {
        xorr=xorr^arr[i];
    }
    return xorr;
}
int main()
{
    vector<int>arr={1,1,2,2,3,3,4,4,8,10,10};
    cout<<optimal_approach(arr);
}
