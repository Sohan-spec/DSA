#include<bits/stdc++.h>
using namespace std;
bool ispossible(vector<int>&arr,int day,int m,int k){
    int count=0, no_of_boq=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]<=day){
            count++;
        }
        else{
            no_of_boq+=(count/k);
            count=0;
        }
    }
    no_of_boq+=(count/k);
    if(no_of_boq>=m)return true;
    return false;
}
int brute_force(vector<int>&arr,int m,int k){
    if(arr.size()<m*k)return -1;
    int mini=*min_element(arr.begin(),arr.end());
    int maxe=*max_element(arr.begin(),arr.end());
    for(int i=mini;i<=maxe;i++){
        if(ispossible(arr,i,m,k))return i;
    }
    return -1;
}
int optimal(vector<int>&arr,int m,int k){
    if(arr.size()<m*k)return -1;
    int low=*min_element(arr.begin(),arr.end());
    int high=*max_element(arr.begin(),arr.end());
    int ans=high;
    while(low<=high){
        int mid=(low+high)/2;
        if(ispossible(arr,mid,m,k)){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
int main()
{
    vector<int>arr={7,7,7,7,12,7,7};
    cout<<optimal(arr,2,3);
}