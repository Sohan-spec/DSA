#include<bits/stdc++.h>
using namespace std;
void brute_force(vector<vector<int>>&matrix){
    vector<int>rowmat(matrix.size());
    vector<int>colmat(matrix[0].size());
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            if(matrix[i][j]==0){
                rowmat[i]=1;
                colmat[j]=1;
            }
        }
    }
    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<matrix[i].size();j++){
            if(rowmat[i]==1 || colmat[j]==1){
                matrix[i][j]=0;
            }
        }
    }
}
void optimal_soln(vector<vector<int>>&arr){ //gotta revise this question, didn't understand it well
    bool firstrowzero=false;
    bool firstcolumzero=false;
    int m=arr.size();
    int n=arr[0].size();
    for(int i=0;i<n;i++){
        if(arr[0][i]==0){
            firstrowzero=true;
            break;
        }
    }
    for(int i=0;i<m;i++){
        if(arr[i][0]==0){
            firstcolumzero=true;
            break;
        }
    }
    for(int i=1;i<m;i++){
        for(int j= 1;j<n;j++){
            if(arr[i][j]==0){
                arr[i][0]=0;
                arr[0][j]=0;
            }
        }
    }
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(arr[i][0]==0 || arr[0][j]==0 ){
                arr[i][j]=0;
            }
        }
    }
    if(firstrowzero){
        for(int i=0;i<n;i++){
            arr[0][i]=0;
        }
    }
    if(firstcolumzero){
        for(int i=0;i<m;i++){
            arr[i][0]=0;
        }
    }

}
int main()
{
    vector<vector<int>>arr={{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    // cout<<arr.size();
    optimal_soln(arr);
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[i].size();j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

}