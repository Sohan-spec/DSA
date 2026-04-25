#include<bits/stdc++.h>
using namespace std;
vector<int> brute_force(vector<int>arr1,vector<int>arr2){
    int n=arr1.size();
    int m=arr2.size();
    unordered_map<int,int>mpp;
    for(int i=0;i<n;i++){
        mpp[arr1[i]]++;
    }
    vector<int>result;
    for(int i=0;i<m;i++){
        while(mpp[arr2[i]]>0){
            result.emplace_back(arr2[i]);
            mpp[arr2[i]]--;
        }
    }
    vector<int>temp;
    for(auto &p:mpp){
        while(p.second>0){
            temp.emplace_back(p.first);
            p.second--;
        }
    }
    sort(temp.begin(),temp.end());
    for(int x:temp){
        result.emplace_back(x);
    }
    return result;
}
int main()
{
    vector<int>arr1={28,6,22,8,44,17};
    vector<int>arr2={22,28,8,6};
    vector<int>result=brute_force(arr1,arr2);
    for(int x:result){
        cout<<x<<"\t";
    }
    return 0;
}