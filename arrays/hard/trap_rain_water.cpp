#include<bits/stdc++.h>
using namespace std;
int brute_force(vector<int>&arr){
    int n=arr.size();
    int water=0;
    for(int i=0;i<n;i++){
       int left_max=0;
       for(int j=0;j<=i;j++){
        left_max=max(left_max,arr[j]);
       }
       int right_max=0;
       for(int j=i;j<=n;j++){
        right_max=max(right_max,arr[j]);
       }
       water+=min(left_max,right_max)-arr[i];

    }
    return water;
}
int better_soln(vector<int>&arr){
    int water=0;
    int n=arr.size();
    vector<int>left_max(n),right_max(n);
    left_max[0]=arr[0];
    for(int i=1;i<n;i++){
        left_max[i]=max(left_max[i-1],arr[i]);
    }
    right_max[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--){
        right_max[i]=max(right_max[i+1],arr[i]);
    }
    for(int i=0;i<n;i++){
        water+=min(left_max[i],right_max[i])-arr[i];
    }
    return water;
}