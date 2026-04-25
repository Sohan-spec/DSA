#include<bits/stdc++.h>
using namespace std;
bool optimal_soln(vector<int>&arr){
    if(arr.empty())return true;
    int i=0,j=1;
    int n=arr.size();
    while(j<n && arr[i]==arr[j]){
        i++;
        j++;
    }
    if(j==n)return true;
    if(arr[i]>arr[j]){
        while(j<n){
            if(arr[i]<arr[j]){
                return false;
            }
            i++;
            j++;
        }
    }
    else{
        while(j<n){
            if(arr[j]<arr[i]){
                return false;
            }
            i++;
            j++;
        }
    }
    return true;
}
int main()
{
    vector<int>arr={1,1,0};
    cout<<boolalpha<<optimal_soln(arr);
}