#include<bits/stdc++.h>
using namespace std;
bool ispossible(vector<int>&arr,int m,int barrier){
    int allocatedstu=1,pages=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]>barrier)return false;
        if(pages+arr[i]>barrier){
            allocatedstu+=1;
            pages=arr[i];
        }
        else{
            pages+=arr[i];
        }
        
    }if(allocatedstu>m)return false;
    return true;
}
int optimal_soln(vector<int>&arr,int m){
    if(m>arr.size())return -1;
    int low=*max_element(arr.begin(),arr.end());
    int high=accumulate(arr.begin(),arr.end(),0);
    while(low<=high){
        int mid=(low+high)/2;
        if(ispossible(arr,m,mid)){
            high=mid-1;
        }
        else{
            low=mid+1;
        }

    }
    return low;
}
int main()
{
    vector<int>arr={12, 34, 67, 90};
    cout<<optimal_soln(arr,2);
}