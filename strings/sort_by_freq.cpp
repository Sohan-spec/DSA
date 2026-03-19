#include<bits/stdc++.h>
using namespace std;
string brute_force(string s){
    unordered_map<char,int>mpp;
    for(char c:s){
        mpp[c]++;
    }
    vector<pair<int,char>>v;
    for (auto it:mpp){
        v.push_back({it.second,it.first});
    }
    sort(v.begin(),v.end(),greater<>());
    string res="";
    for(auto it:v){
        res+=string(it.first,it.second);
    }
    return res;
}
int main(){
    string s="tree";
}