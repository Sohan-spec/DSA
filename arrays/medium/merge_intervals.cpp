#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> brute_force(vector<vector<int>>&arr){
    vector<vector<int>>ans;
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size();i++){
        int start=arr[i][0];
        int end=arr[i][1];
        if(!ans.empty() && end<=ans.back()[1])continue;
        for(int j=i+1;j<arr.size();j++){
            if(arr[j][0]<=end){
                end=max(end,arr[j][1]);
            }
            else{
                break;
            }
        }
        ans.push_back({start,end});
    }
    return ans;
}
vector<vector<int>> optimal_soln(vector<vector<int>>&arr){
    vector<vector<int>>ans;
    sort(ans.begin(),ans.end());
    for(int i=0;i<arr.size();i++){
        if(ans.empty() || arr[i][0]>ans.back()[1]){
            ans.push_back(arr[i]);
        }
        else{
            ans.back()[1]=max(ans.back()[1],arr[i][1]);
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>>arr={{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>>temp=optimal_soln(arr);
    for(int i=0;i<temp.size();i++){
        for(int j=0;j<temp[i].size();j++){
            cout<<temp[i][j]<<" ";
        }
        cout<<endl;
    }
}