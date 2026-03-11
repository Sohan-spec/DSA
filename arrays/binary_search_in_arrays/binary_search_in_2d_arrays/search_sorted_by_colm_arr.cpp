#include<bits/stdc++.h>
using namespace std;
bool optimal_soln(vector<vector<int>>&arr,int target){
    int m=arr.size();
    int n=arr[0].size();
    int row=0,col=n-1;
    while(row<n && col>=0 ){
        if(arr[row][col]==target){
            return true;
        }
        else if(arr[row][col]>target){
            col--;
        }
        else{
            row++;
        }
    }
    return false;
}
int main()
{
    vector<vector<int>>arr={{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    cout<<boolalpha<<optimal_soln(arr,26);
}