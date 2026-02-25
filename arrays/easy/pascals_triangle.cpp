#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> brute_force(int rows){
    vector<vector<int>>triangle;
    for(int i=0;i<rows;i++){
        vector<int>row(i+1,1);
        for(int j=1;j<i;j++){
            row[j]=triangle[i-1][j-1]+triangle[i-1][j];
        }
        triangle.emplace_back(row);
    }
    return triangle;
}
int main()
{
    vector<vector<int>>result=brute_force(5);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}