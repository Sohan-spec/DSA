#include<bits/stdc++.h>
using namespace std;
int lower_bound(vector<int>&arr,int target){
    if(arr.empty())return arr.size()-1;
    for(int i=0;i<arr.size();i++){
        if(arr[i]>=target){
            return i;
        }
    }
    return arr.size()-1;
}
int upper_bound(vector<int>&arr,int x){
    if(arr.empty())return arr.size()-1;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>x){
                return i;
            }
        }
        return arr.size()-1;
}
int main()
{
    vector<int>arr={1,2,2,3};
    cout<<lower_bound(arr,2);
}