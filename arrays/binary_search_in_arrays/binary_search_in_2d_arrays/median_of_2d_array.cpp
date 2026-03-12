#include<bits/stdc++.h>
using namespace std;
int brute_force(vector<vector<int>>&arr){
    int m=arr.size();
    int n=arr[0].size();
    vector<int>temp;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            temp.emplace_back(arr[i][j]);
        }
    }
    sort(temp.begin(),temp.end());
    return(temp[((m*n)/2)+1]);
}
int main(){
vector<vector<int>>arr={{1,5,7,9,11},{2,3,4,5,10},{9,10,12,14,16}};
cout<<brute_force(arr);
}