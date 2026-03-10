#include<bits/stdc++.h>
using namespace std;
int brute_force(vector<int>&arr1,vector<int>&arr2,int k){
    int m=arr1.size();
    int n=arr2.size();
    int len=m+n;
    int gap=(len/2)+(len%2);
    while(gap>0){
        int left=0;
        int right=gap;
        while(right<len){
            if(left<m && right<m){
                if(arr1[left]>arr1[right]){
                    swap(arr1[left],arr1[right]);
                }
            }
            else if(left>=m){
                if(arr2[left-m]>arr2[right-m]){
                    swap(arr2[left-m],arr2[right-m]);
                }
            }
            else{
                if(arr1[left]>arr2[right-m]){
                    swap(arr1[left],arr2[right-m]);
                }
            }
            left++;
            right++;
        }
        if(gap==1)break;
        gap=(gap/2)+(gap%2);
    }
    for(int i=0;i<n;i++){
        arr1.emplace_back(arr2[i]);
    }
    return arr1[k-1];
}
int another_brute(vector<int>&arr1,vector<int>&arr2,int k){
    int left=0,right=0;
    vector<int>temp;
    while(left<arr1.size() && right<arr2.size()){
        if(arr1[left]<=arr2[right]){
            temp.emplace_back(arr1[left]);
            left++;
        }
        else{
            temp.emplace_back(arr2[right]);
            right++;
        }
    }
    while(left<arr1.size()){
        temp.emplace_back(arr1[left]);
        left++;
    }
    while(right<arr2.size()){
        temp.emplace_back(arr2[right]);
        right++;
    }
    return temp[k-1];
}
int main()
{
    vector<int>arr1={2, 3, 6, 7, 9};
    vector<int>arr2={1, 4, 8, 10};
    cout<<another_brute(arr1,arr2,5);
}