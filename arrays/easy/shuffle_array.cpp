#include<bits/stdc++.h>
using namespace std;
vector<int>brute_force(vector<int>arr,int n){
    vector<int>x;
    vector<int>y;
    for(int i=0;i<n;i++){
        x.emplace_back(arr[i]);
    }
    for(int i=n;i<arr.size();i++){
        y.emplace_back(arr[i]);
    }
    vector<int>result;
    for(int i=0;i<n;i++){
        result.emplace_back(x[i]);
        result.emplace_back(y[i]);
    }
    return result;
}
vector<int>optimal_soln(vector<int>arr,int n){
    vector<int>result;
    for(int i=0;i<n;i++){
        result.emplace_back(arr[i]);
        result.emplace_back(arr[i+n]);
    }
    return result;
}
int main()
{
    vector<int>arr={2,5,1,3,4,7};
    vector<int>ans=optimal_soln(arr,3);
    for(int x:ans){
        cout<<x<<"\t";    
    }
}