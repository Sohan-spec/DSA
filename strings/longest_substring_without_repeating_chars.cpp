#include<bits/stdc++.h>
using namespace std;
int brute_force(string s){ // this takes TC- > O(n^2) and space of O(n)
    int max_len=0;
    int n=s.length();
    for(int i=0;i<n;i++){
        unordered_set<char>stt;
        for(int j=i;j<n;j++){
            if(stt.find(s[j])!=stt.end()){
                break;
            }
           int len=j-i+1;
           max_len=max(max_len,len);
            stt.insert(s[j]);
        }
    }
    return max_len;
}
int optimal_soln(string s){
    int max_len=0;
    int l=0,r=0;
    int n=s.length();
    unordered_map<char,int>mpp;
    while(r<n){
        if(mpp.find(s[r])!=mpp.end()){
            if(mpp[s[r]]>=l){
                l=mpp[s[r]]+1;
            }
        }
        max_len=max(max_len,r-l+1);
        mpp[s[r]]=r;
        r++;
    }
    return max_len;
}
int main()
{
    string s="abcabcbb";
    cout<<optimal_soln(s);
}