#include<bits/stdc++.h>
using namespace std;
bool optimal_soln(vector<int>&arr,int target){
    int low=0,high=arr.size()-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==target){
            return true;
        }
        if(arr[low]==arr[mid] && arr[mid]==arr[high]){
            low++;
            high--;
            continue;
        }
        if(arr[low]<=arr[mid]){
            if(target>=arr[low] && target<=arr[mid]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        else{
            if(target>=arr[mid]&&target<=arr[high]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
    }
    return false;
}
int main()
{
    vector<int>arr={7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    cout<<boolalpha<<optimal_soln(arr,3);
}