#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> brute_force(vector<int>&arr){
    set<vector<int>>stt;
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            for(int k=j+1;k<arr.size();k++){
                if(arr[i]+arr[j]+arr[k]==0){
                    vector<int>temp={arr[i],arr[j],arr[k]};
                    sort(temp.begin(),temp.end());
                    stt.insert(temp);
                }
            }
        }
    }
    vector<vector<int>>ans(stt.begin(),stt.end());
    return ans;
}
vector<vector<int>> better_soln(vector<int>&arr){
    set<vector<int>>stt;
    for(int i=0;i<arr.size();i++){
        set<int>hs;
        for(int j=i+1;j<arr.size();j++){
            if(hs.find(-(arr[i]+arr[j]))!=hs.end()){
                vector<int>temp={arr[i],arr[j],-(arr[i]+arr[j])};
                sort(temp.begin(),temp.end());
                stt.insert(temp);
            }
            hs.insert(arr[j]);
        }
    }
    vector<vector<int>>ans(stt.begin(),stt.end());
    return ans;
}
vector<vector<int>> optimal_soln(vector<int>&arr){
    vector<vector<int>>ans;
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size();i++){
        if(i>0 && arr[i]==arr[i-1])continue;
        int j=i+1;
        int k=arr.size()-1;
        while(j<k){
            int sum=arr[i]+arr[j]+arr[k];
            if(sum>0){
                k--;
            }
            else if(sum <0){
                j++;
            }
            else{
                vector<int>temp={arr[i],arr[j],arr[k]};
                ans.emplace_back(temp);
                j++;
                k--;
                while(j < k && arr[j]==arr[j-1])j++;
                while(j<k && arr[k]==arr[k+1])k--;
            }
        }
    }
    return ans;
}
int main()
{
    vector<int>arr={-1,0,1,2,-1,-4};
    vector<vector<int>>temp=optimal_soln(arr);
    for(int i=0;i<temp.size();i++){
        for(int j=0;j<temp[i].size();j++){
            cout<<temp[i][j]<<" ";
        }
        cout<<endl;
    }
}