#include<bits/stdc++.h>
using namespace std;
vector<int> brute_force(vector<vector<int>>&arr){
    int peak=-1;
    int m=arr.size();
    int n=arr[0].size();
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++){

            int left  = (j > 0) ? arr[i][j-1] : -1;
            int right = (j < n-1) ? arr[i][j+1] : -1;
            int up    = (i > 0) ? arr[i-1][j] : -1;
            int down  = (i < m-1) ? arr[i+1][j] : -1;
            if(arr[i][j] > left &&
               arr[i][j] > right &&
               arr[i][j] > up &&
               arr[i][j] > down)
            {
                return{i,j};
            }
        }
    }
    return{-1,-1};
}
int main()
{
vector<vector<int>>arr={{1,4},{3,2}};
for(int i=0;i<2;i++){
    cout<<brute_force(arr)[i]<<" ";
}
}