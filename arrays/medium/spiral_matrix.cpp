#include <bits/stdc++.h>
using namespace std;
vector<int> idk_function_name(vector<vector<int>> &arr)
{
    vector<int> temp;
    int top=0;
    int bottom=arr.size()-1;
    int left=0;
    int right=arr[0].size()-1;
    while(top<=bottom && left<=right){
        for(int i=left;i<=right;i++){
            temp.emplace_back(arr[top][i]);
        }
        top++;
        for(int i=top;i<=bottom;i++){
            temp.emplace_back(arr[i][right]);
        }
        right--;
        if(top<=bottom){
            for(int i=right;i>=left;i--){
                temp.emplace_back(arr[bottom][i]);
            }
            bottom--;
        }
        if(left<=right){
            for(int i=bottom;i>=top;i--){
                temp.emplace_back(arr[i][left]);
            }
            left++;
        }
    }
    return temp;
}
int main()
{
    vector<vector<int>>arr={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16},{17,18,19,20}};
    vector<int>temp=idk_function_name(arr);
   for(auto it:temp){
    cout<<it<<" ";
   }
}