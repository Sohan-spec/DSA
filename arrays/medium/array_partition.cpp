#include<bits/stdc++.h>
using namespace std;
int brute_force(vector<int>&arr){
    if(arr.empty())return 0;
    sort(arr.begin(),arr.end());
    int sum=0;
    for(int i=0;i<arr.size();i+=2){
        sum+=arr[i];
    }
    return sum;
}
int main()
{
    vector<int>arr={1,4,3,2};
    cout<<brute_force(arr);
}