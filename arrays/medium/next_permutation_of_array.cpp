#include<bits/stdc++.h>
using namespace std;
vector<int> brute_force(vector<int>&nums){ //this takes like O(n!*n)
    vector<vector<int>>all;
    vector<int>temp=nums;
    sort(temp.begin(),temp.end());
    do{
        all.emplace_back(temp);
    }while(next_permutation(temp.begin(),temp.end()));
    for(int i=0;i<all.size();i++)
    {
        if(all[i]==nums){
            if(i==all.size()-1){
                return all[0];
            }
            return all[i+1];
        }
    }
    return nums;
}
vector<int>optimal_soln(vector<int>&arr){
    int index=-1;
    for(int i=arr.size()-2;i>=0;i--){
        if(arr[i]<arr[i+1]){
            index=i;
            break;
        }
    }
    if(index==-1){
        reverse(arr.begin(),arr.end());
        return arr;
    }
    for(int i=arr.size()-1;i>index;i--){
        if(arr[i]>arr[index]){
        swap(arr[i],arr[index]);
        break;
    }
        
    }
    reverse(arr.begin()+index+1,arr.end());
    return arr;
}
int main()
{
    vector<int>arr={2,3,1};
    vector<int>temp=optimal_soln(arr);
    for(auto it:temp){
        cout<<it<<" ";
    }
    return 0;

}