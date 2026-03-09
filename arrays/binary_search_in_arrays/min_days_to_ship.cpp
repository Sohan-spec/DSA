#include<bits/stdc++.h>
using namespace std;
int calc_days(vector<int>&arr,int capacity){
    int days=1,load=0;
    for(int i=0;i<arr.size();i++){
        if(load + arr[i] > capacity){
            days+=1;
            load=arr[i];
        }
        else{
            load+=arr[i];
        }
    }
    return days;
}
int brute_force(vector<int>&arr,int days){
    int maxe=*max_element(arr.begin(),arr.end());
    int sum=0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
    }
    for (int capacity=maxe;capacity<=sum;capacity++){
        int daystaken=calc_days(arr,capacity);
        if(daystaken<=days){
            return capacity;
        }
    }return -1;
}
int optimal_soln(vector<int>&arr,int days){
    int low=*max_element(arr.begin(),arr.end());
    int high=accumulate(arr.begin(),arr.end(),0); //this is for summation of an array
    while(low<=high){
        int mid=(low+high)/2;
        if(calc_days(arr,mid) <= days){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return low;
}
int main()
{
    vector<int>arr={1,2,3,4,5,6,7,8,9,10};
    cout<<optimal_soln(arr,5);
    // cout<<calc_days(arr,16);
}