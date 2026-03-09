#include<bits/stdc++.h>
using namespace std;
int calc_sum(vector<int>&arr,int no){
    int sum=0;
    int n=arr.size();
    for(int i=0;i<n;i++){
        sum+=(arr[i]+no-1)/no; // this is equivalent to ceil(expr); and better as double operations are more compute intensive
    }
    return sum;
}
int optimal_soln(vector<int>&arr,int th){
    int low=1;
    int high=*max_element(arr.begin(),arr.end());
    while(low<=high){
        int mid=(low+high)/2;
        if(calc_sum(arr,mid)<=th){
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
    vector<int>arr={1,2,5,9};
    cout<<optimal_soln(arr,5);
}