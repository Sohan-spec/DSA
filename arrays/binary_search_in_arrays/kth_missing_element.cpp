#include<bits/stdc++.h>
using namespace std;
int brute_force(vector<int>&arr,int k){
 for(int i=0;i<arr.size();i++){
    if(arr[i]<=k){
        k++;
    }
    else{
        break;
    }
 }
 return k;
}
int optimal_soln(vector<int>&arr,int k){
    int low=0,high=arr.size()-1;
    while(low<=high){
        int mid=(low+high)/2;
        int missing=arr[mid]-(mid+1);
        if(missing<k){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return low+k;
}
int main()
{
    vector<int>arr={2,3,4,7,11};
    cout<<optimal_soln(arr,5);
}