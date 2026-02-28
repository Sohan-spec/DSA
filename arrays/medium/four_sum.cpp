#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> better_soln(vector<int>&arr,int target){
    set<vector<int>>stt;
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            unordered_set<int>hs;
            for(int k=j+1;k<arr.size();k++){
                int needed=target-(arr[i]+arr[j]+arr[k]);
                if(hs.find(needed)!=hs.end()){
                    vector<int>temp={arr[i],arr[j],arr[k],needed};
                    sort(temp.begin(),temp.end());
                    stt.insert(temp);
                }
                hs.insert(arr[k]);
            }
        }
    }
    vector<vector<int>>ans(stt.begin(),stt.end());
    return ans;
}
vector<vector<int>> optimal_soln(vector<int>&arr,int target){
    vector<vector<int>>ans;
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size();i++){
        if(i>0 && arr[i]==arr[i-1])continue;
        for(int j=i+1;j<arr.size();j++){
            if(j>i+1 && arr[j]==arr[j-1])continue;
            int k=j+1;
            int l=arr.size()-1;
            while(k<l){
                int sum=arr[i]+arr[j]+arr[k]+arr[l];
                if(sum>target){
                    l--;
                }
                else if(sum<target){
                    k++;
                }
                else{
                    ans.push_back({arr[i],arr[j],arr[k],arr[l]});
                    k++;
                    l--;
                    while(k<l && arr[k]==arr[k-1])k++;
                    while(k<l && arr[l]==arr[l+1])l--;

                }
            }
        }
    }
    return ans;
}
int main()
{
    vector<int>arr={1,0,-1,0,-2,2};
    vector<vector<int>>temp=optimal_soln(arr,0);
    for(int i=0;i<temp.size();i++){
        for(int j=0;j<temp[i].size();j++){
            cout<<temp[i][j]<<" ";
        }
        cout<<endl;
    }
}