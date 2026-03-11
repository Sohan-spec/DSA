#include<bits/stdc++.h>
using namespace std;
bool brute_force(vector<vector<int>>&arr,int target){
    for(int i=0;i<arr.size();i++){
        int low=0,high=arr[i].size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[i][mid]==target){
                return true;
            }
            else if(arr[i][mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
    }
    return false;
}
bool optimal_soln(vector<vector<int>>&arr,int target){
    int m=arr.size();
    int n=arr[0].size();
    int low=0,high=(m*n)-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid/n][mid%n]==target){
            return true;
        }
        else if(arr[mid/n][mid%n]>target){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return false;
}
int main()
{
    vector<vector<int>>arr={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    cout<<boolalpha<<optimal_soln(arr,7);
}