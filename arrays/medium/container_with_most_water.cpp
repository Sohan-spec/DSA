#include<bits/stdc++.h>
using namespace std;
int idk_soln(vector<int>&arr){
    if(arr.empty())return -1;
    int max_area=-1;
    int left=0,right=arr.size()-1;
    while(left<right){
        long long area=(right-left)*min(arr[left],arr[right]);
        if(area>max_area){
            max_area=area;
        }
        if(arr[left]<arr[right]){
            left++;
        }
        else{
            right--;
        }
    }
    return max_area;
}
int main()
{
    vector<int>arr={1,8,6,2,5,4,8,3,7};
    cout<<idk_soln(arr);
}