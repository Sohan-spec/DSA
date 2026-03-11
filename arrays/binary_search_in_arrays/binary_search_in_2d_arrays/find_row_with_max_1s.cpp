#include <bits/stdc++.h>
using namespace std;
int brute_force(vector<vector<int>> &arr)
{
    int prev_count = -1;
    int index = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < arr[i].size(); j++)
        {
            if (arr[i][j] == 1)
            {
                count++;
            }
        }
        if (count > prev_count)
        {
            prev_count = count;
            index = i;
        }
    }
    return index;
}
int lowerbound(vector<int>&arr,int target){
    int low=0,high=arr.size()-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>=target){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return low;
}
int optimal_soln(vector<vector<int>>&arr){
    int count_max=0,index=-1;
    for(int i=0;i<arr.size();i++){
        int count=arr[i].size() -lowerbound(arr[i],1);
        if(count>count_max){
            count_max=count;
            index=i;
        }
    }
    return index;
}
int main()
{
    vector<vector<int>> arr = {{0,0,1,1,1}, {0, 0, 0,0,0}, {0, 1, 1,1,1},{0,0,0,0,0},{0,1,1,1,1}};
    cout << optimal_soln(arr);
}