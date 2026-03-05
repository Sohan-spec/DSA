#include<bits/stdc++.h>
using namespace std;
int lowerbound(vector<int>&arr,int target){
        int low=0,high=arr.size()-1;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]>=target){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    int upperbound(vector<int>&arr,int target){
        int low=0,high=arr.size()-1;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]>target){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    int countOccurrences( vector<int>& arr, int target) {
        int lb=lowerbound(arr,target);
        int ub=upperbound(arr,target);
        if(lb==-1 || arr[lb]!=target)return -1;
        if(ub==-1 ) return arr.size()-lb;
        return(ub-lb);
    }
int main()
{
    vector<int>arr={0, 0, 1, 1, 1, 2, 3};
    cout<<countOccurrences(arr,1);
}