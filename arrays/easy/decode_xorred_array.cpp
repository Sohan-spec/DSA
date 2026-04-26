#include<bits/stdc++.h>
using namespace std;
vector<int> optimal_soln(vector<int>arr,int first){
    vector<int>result;
    result.emplace_back(first);
    int n=arr.size();
    for(int i=0;i<n;i++){
        result.emplace_back(result[i]^arr[i]);
    }
    return result;
}
int main()
{
    vector<int>arr={1,2,3};
    vector<int>result=optimal_soln(arr,1);
    for(int x:result){
        cout<<x<<"\t";
    }
}