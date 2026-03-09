#include<bits/stdc++.h>
using namespace std;
int brute_force(vector<int>&arr,int hrs){
    int maxe=*max_element(arr.begin(),arr.end());
    for(int i=1;i<=maxe;i++){
        int sum=0;
        for(int j=0;j<arr.size();j++){
            sum+=(arr[j]+i-1)/i;
        }
        if (sum<=hrs){
            return i;
        }
    }
    return maxe;
}
int optimal_soln(vector<int>&arr,int hrs){
    int maxe=*max_element(arr.begin(),arr.end());
    int low=1,high=maxe;
    while(low<=high){
        int mid=(low+high)/2;
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=ceil((double)arr[i]/(double)mid);
        }
        if(sum<=hrs){
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
    vector<int>arr={3,6,7,11};
    cout<<optimal_soln(arr,8);
}