#include<bits/stdc++.h>
using namespace std;
vector<int>optimal_soln(vector<int>arr){
    vector<int>result;
    int n=arr.size();
    result.reserve(2*n);
    for(int i=0;i<2*n;i++){
        result.emplace_back(arr[i%n]);
    }
    return result;
}
int main()
{
    vector<int>arr={1,2,1};
    vector<int>result=optimal_soln(arr);
    for(int x:result){
        cout<<x<<"\t";
    }
}