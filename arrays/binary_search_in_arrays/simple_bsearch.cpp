#include<bits/stdc++.h>
using namespace std;
int binary_search(vector<int>&arr,int target){
    if(arr.empty())return -1;
    int low=0;
    int high=arr.size()-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]>target){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return -1;
}
int main()
{
    vector<int>arr={-1,3,8,9,10,16,29};
    cout<<binary_search(arr,9);
}