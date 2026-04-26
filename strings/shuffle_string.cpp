#include<bits/stdc++.h>
using namespace std;
string brute_force(string s, vector<int>&indices){
    unordered_map<int,char>mpp;
    for(int i=0;i<indices.size();i++){
        mpp[indices[i]]=s[i];
    }
    for(int i=0;i<indices.size();i++){
        s[i]=mpp[i];
    }
    return s;
}
string optimal_soln(string s, vector<int>&indices){
    int n=s.size();
    string result="";
    for(int i=0;i<n;i++){
        result[indices[i]]=s[i];
    }
    return result;
}
int main()
{
    vector<int>indices={4,5,6,7,0,2,1,3};
    cout<<optimal_soln("codeleet",indices);
}