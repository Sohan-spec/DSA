#include<bits/stdc++.h>
using namespace std;
int brute_force(vector<int>&arr){
    int count=0;
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            if(arr[i]>arr[j]){
                count++;
                // swap(arr[i],arr[j]);
                cout<<i<<" "<<j<<endl;
            }
        }
    }
    return count;
}
int merge(vector<int>&arr,int low,int mid,int high){
    vector<int>temp;
    int left=low;
    int right=mid+1;

    int count=0;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.emplace_back(arr[left]);
            left++;
        }else{
            temp.emplace_back(arr[right]);
            right++;
            count+=(mid-left+1);
        }
    }
    while(left<=mid){
        temp.emplace_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.emplace_back(arr[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
    return count; 
}
int mergesort(vector<int>&arr,int low,int high){
    int count=0;
    if(low>=high)return count;
    int mid=(low+high)/2;
    count+=mergesort(arr,low,mid);
    count+=mergesort(arr,mid+1,high);
    count+=merge(arr,low,mid,high);
    return count;
}
int main()
{
    vector<int>arr={5,6,2,3,8};
    cout<<mergesort(arr,0,arr.size()-1);
}