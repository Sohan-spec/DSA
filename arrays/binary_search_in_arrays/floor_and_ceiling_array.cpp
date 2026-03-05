#include<bits/stdc++.h>
using namespace std;
vector<int> floor_ceiling(vector<int>&arr,int target){
    if(arr.empty())return {};
        int low=0;
        int high=arr.size()-1;
        int floor=-1,ceiling=-1;
        while(low<=high){
            int mid=(low+high)/2; //it says use low +(high-low)/2
            if(arr[mid]==target){
                ceiling=arr[mid];
                floor=arr[mid];
                return {floor,ceiling};
            }
            else if(arr[mid]>target){
                high=mid-1;
                ceiling=min(ceiling,arr[mid]);
            }
            else{
                low=mid+1;
                floor=max(floor,arr[mid]);
            }
        }
        return {floor,ceiling};
}
int main()
{
    vector<int>arr={3, 4, 4, 7, 8, 10};
    for(int i=0;i<2;i++){
        cout<<floor_ceiling(arr,5)[i]<<" ";
    }
}