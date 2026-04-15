#include<bits/stdc++.h>
using namespace std;
int brute_force(vector<int>&arr){ // this is O(n^2)
    if(arr.empty())return -1;
    for(int i=0;i<arr.size();i++){
        int suml=0;
        int sumr=0;
        for(int j=0;j<i;j++){
            suml+=arr[j];
        }
        for(int j=i+1;j<arr.size();j++){
            sumr+=arr[j];
        }
        if(suml==sumr)return i;
    }
    return -1;
}

int optimal_soln(vector<int>&arr){
    if(arr.empty())return -1;
    int total=0;
    for(auto x:arr){
        total+=x;
    }
    int left=0;
    for(int i=0;i<arr.size();i++){
        int right=total-left-arr[i];
        if(left==right){
            return i;
        }
        left+=arr[i];
    }
    return -1;
}
int main()
{
    vector<int>arr={1,7,3,6,5,6};
    cout<<brute_force(arr)<<endl;
    cout<<optimal_soln(arr);
}