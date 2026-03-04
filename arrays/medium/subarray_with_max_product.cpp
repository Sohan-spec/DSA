#include<bits/stdc++.h>
using namespace std;
int brute_force(vector<int>&arr){
    int maxi=INT_MIN;
    for(int i=0;i<arr.size();i++){
        int prod=1;
        for(int j=i;j<arr.size();j++){
            prod*=arr[j];
            maxi=max(maxi,prod);
        }
    }
    return maxi;
}
long long optimal(vector<int>&arr){
    long long prefix=1,suffix=1;
    long long maxi=INT_MIN;
    int n=arr.size();
    for(int i=0;i<n;i++){
        if(prefix==0)prefix=1;
        if(suffix==0)suffix=1;
        prefix*=(long long)arr[i];
        suffix*=(long long)arr[n-i-1];
        maxi=max(maxi,max(prefix,suffix));
    }
    return maxi;
}
int main()
{
    vector<int>arr={1,0,-5,2,3,-8,-9};
    cout<<optimal(arr);
    return 0;
}