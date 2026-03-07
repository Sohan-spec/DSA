#include<bits/stdc++.h>
using namespace std;
int peak_elem(vector<int>&arr){
    int n=arr.size();
    if(n==1)return 0;
    int low=1,high=n-2;
    if(arr[0]>arr[1])return 0;
    if(arr[n-1]>arr[n-2]) return n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
            return mid;
        }
        else if(arr[mid]>arr[mid-1] && arr[mid]<arr[mid+1]){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}
int main()
{
    vector<int>arr={1,2,1,3,5,6,4};
    cout<<peak_elem(arr);
}