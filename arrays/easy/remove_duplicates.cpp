#include<bits/stdc++.h>
using namespace std;
vector<int> remove_duplicates(const vector<int>&arr)
{
    unordered_map<int,int>array_map;
    vector<int>temp;
    for(int i=0;i<arr.size();i++)
    {
        array_map[arr[i]]+=1;
    }
    for(auto it: array_map){
        temp.push_back(it.first);
    }
    return temp;
}
int main()
{
    vector<int>arr={0,0,1,2,-2,3,1,8,5,9,2,1};
    vector<int>temp=remove_duplicates(arr);
    for(int i:temp)
    {
        cout<<i<<endl;
    }
}