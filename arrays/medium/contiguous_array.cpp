#include<bits/stdc++.h>
using namespace std;
int brute_force(vector<int>&arr){
    if(arr.empty())return -1;
    int max_len=0;
    for(int i=0;i<arr.size();i++){
        int count0=0,count1=0;
        for(int j=i;j<arr.size();j++){
            if(arr[j]==0){
                count0++;
            }
            else{
                count1++;
            }
            if(count0==count1) max_len=max(max_len,j-i+1);
        }
    }
    return max_len;
}
int optimal_soln(vector<int>&arr){
    unordered_map<int,int>mpp;
    mpp[0]=-1;
    int balance=0,max_len=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==0) balance-=1;
        else balance+=1;

        if(mpp.count(balance)){ // .count returns 1 if the key is there and 0 if its not there
            max_len=max(max_len,i-mpp[balance]);
        }
        else{
            mpp[balance]=i;
        }
    }
    return max_len;
}
int main()
{
    vector<int>arr={0,1,1};
    cout<<brute_force(arr);
}