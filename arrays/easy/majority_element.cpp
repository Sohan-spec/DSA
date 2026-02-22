#include<bits/stdc++.h>
using namespace std;
int brute_force(vector<int>&arr){
    map<int,int>freq_map;
    for(int i=0;i<arr.size();i++)
    {
        freq_map[arr[i]]+=1;
    }
    for(auto it:freq_map){
        if(it.second>(arr.size()/2)){
            return it.first;
        }
    }
    return -1;
}
int optimal_soln(vector<int>&arr)
{
    int elem,count=0;
    for(int i=0;i<arr.size();i++) // this returns the most occuring element
    {
        if(count==0){
            count=1;
            elem=arr[i];
        }
        else if(elem==arr[i]){
            count++;
        }
        else{
            count--;
        }
    }
    count=0;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]==elem){
            count++;
        }
    }
    if(count>(arr.size()/2)){
        return elem;
    }
    return -1;
}
int main()
{
    vector<int>arr={2,2,1,1,1,2,2};
    cout<<optimal_soln(arr);
    return 0;
}