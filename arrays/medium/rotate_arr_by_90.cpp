#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> brute_force(vector<vector<int>>&arr){
    int n=arr.size();
    int m=arr[0].size();
    vector<vector<int>>matrix(m,vector<int>(n));
    for(int i=0;i<arr.size();i++)
    {
        for(int j=0;j<arr[i].size();j++){
            matrix[j][n-i-1]=arr[i][j];
        }
    }
    return matrix;
}
void rotateMatrix(vector<vector<int>>& matrix) {
        // int n=arr.size();
        // int m=arr[0].size();
        // vector<vector<int>>result(m,vector<int>(n));
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         result[j][n-i-1]=arr[i][j];
        //     }
        // }
        // for(int i=0;i<result.size();i++){
        //     for(int j=0;j<result[0].size();j++){
        //         cout<<result[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        for(int i=0;i<matrix[0].size();i++){
            for(int j=i;j<matrix.size();j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<matrix.size();i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
int main()
{
    vector<vector<int>>arr={{1,2,3},{4,5,6},{7,8,9}};
    rotateMatrix(arr);
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[i].size();j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}