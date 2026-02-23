#include<bits/stdc++.h>
using namespace std;
vector<int> brute_force(vector<int>&arr){
    if(arr.empty())return {};
    vector<int>result;
    for(int i=0;i<arr.size();i++){
        bool isgreater=false;
        for(int j=i+1;j<arr.size();j++){
            if(arr[i]>arr[j]){
                isgreater=true;
            }
            else{
                break;
            }
        }
        if(isgreater){
            result.emplace_back(arr[i]);
        }
    }result.emplace_back(arr[arr.size()-1]);
    return result;
}
vector<int>optimal_soln(vector<int>&arr){
    vector<int>result;
    int max_elem=INT_MIN;
    for(int i=arr.size()-1;i>=0;i--){
        if(arr[i]>max_elem){
            max_elem=arr[i];
            result.emplace_back(arr[i]);
        }
    }reverse(result.begin(),result.end());
    return result;
}
int main()
{
    vector<int>arr={1, 2, 5, 3, 1, 2};
    vector<int>temp=optimal_soln(arr);
    for(auto it:temp){
        cout<<it<<" ";
    }
}