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
int main()
{
    vector<int>arr={3,6,7,11};
    cout<<brute_force(arr,8);
}