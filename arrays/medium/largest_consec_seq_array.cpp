#include<bits/stdc++.h>
using namespace std;
int brute_force(vector<int>&arr){
    if(arr.empty())return 0;
    int count=0;int max_count=0;
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size()-1;i++)
    {
        if(arr[i]==arr[i+1])continue;
        if((arr[i+1]-arr[i])==1){
            count++;
            max_count=max(max_count,count);
        }
        else{
            count=0;
        }
    }
    return max_count+1;
}
int optimal_soln(vector<int>&arr){
    if(arr.empty())return 0;
    int longest=1;
    unordered_set<int>st;
    for(auto it:arr){
        st.insert(it);
    }
    for(auto it:st){
        if(st.find(it-1)==st.end()){
            int count=1;
            int x=it;
            while(st.find(x+1)!=st.end()){
                x+=1;
                count+=1;
            }
            longest=max(longest,count);
        }
    }
    return longest;
}
int main()
{
    vector<int>arr={100, 4, 200, 1, 3, 2};
    cout<<optimal_soln(arr);
}