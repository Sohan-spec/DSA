#include<bits/stdc++.h>
using namespace std;
void better_soln(vector<int>&arr1,vector<int>&arr2){
    int m=arr1.size();
    int n=arr2.size();
    int left=m-1;
    int right=0;
    while(left>=0 && right <n){
        if(arr1[left]>arr2[right]){
            swap(arr1[left],arr2[right]);
            left--;
            right++;
        }
        else{
            break;
        }
    }
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
    for(int i=0;i<n;i++){
        arr1.push_back(arr2[i]);
    }
    sort(arr1.begin(),arr1.end());
}
void optimal_soln(vector<int>&arr1,int m,vector<int>&arr2,int n){
    int len=m+n;
    int gap=(len/2)+(len%2);
    while(gap>0){
        int left=0;
        int right=gap;
        while(right < len){
            //both are in arr1
            if(left<m && right<m ){
                if(arr1[left]>arr1[right]){
                    swap(arr1[left],arr1[right]);
                }
            }
            //both are in arr2
            else if(left>=m){
                if(arr2[left-m]>arr2[right-m]){
                    swap(arr2[left-m],arr2[right-m]);
                }
            }
            //if they're in different arrays
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
        arr1[m+i]=arr2[i];
    }
}
int main()
{
    vector<int>arr1={1,2,3,0,0,0};
    vector<int>arr2={2,5,6};
    optimal_soln(arr1,3,arr2,3);
    for(auto it:arr1){
        cout<<it<<" ";
    }
}