#include<bits/stdc++.h>
using namespace std;
bool brute_force(vector<int>&arr){
    int n=arr.size();
    if(n<3)return false;
    int i=0;
    while(i+1<n && arr[i]<arr[i+1]){
        i++;
    }
    if(i==0 || i==n-1){
        return false;
    }
    while(i+1<n && arr[i]>arr[i+1]){
        i++;
    }
    return i==n-1;
}
int main()
{
    vector<int>arr={0,2,3,3,5,2,1,0};
    cout<<boolalpha<<brute_force(arr);
}