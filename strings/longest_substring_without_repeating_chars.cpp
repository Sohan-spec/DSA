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
int main()
{
    string s="abcabcbb";
    cout<<brute_force(s);
}