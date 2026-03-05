#include<bits/stdc++.h>
using namespace std;
vector<int> brute_force(vector<int>&arr,int target){
    if(arr.empty())return {-1,-1};
  int first=-1,last=-1;
  for(int i=0;i<arr.size();i++){
    if(arr[i]==target){
        if(first==-1)first=i;
        last=i;
    }
  }
  return {first,last};
}
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
vector<int> optimal_soln(vector<int>&arr,int target){
    int lb=lowerbound(arr,target);
    if(lb>=arr.size() || arr[lb]!=target || lb==-1){
        return {-1,-1};
    }
    return{lb,upperbound(arr,target)-1};
}
int main()
{
    vector<int>arr={5, 7, 7, 8, 8,8, 10};
    vector<int>temp=optimal_soln(arr,8);
    for(int i=0;i<temp.size();i++){
        cout<<temp[i]<<" ";
    }
}