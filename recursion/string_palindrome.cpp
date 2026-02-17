#include<bits/stdc++.h>
using namespace std;
bool helper(int l,int r, string&s){
    if(l>=r)return true;
    if(s[l]!=s[r])return false;
    return helper(l+1,r-1,s);
}
bool checkpalindrome(string &s){
    string clean="";
    for(char c:s){
        if(isalnum(c)){
            clean+=tolower(c);
        }
    }
    return helper(0,clean.size()-1,clean);
}
int main()
{
    string s;
    cout<<"Enter str:";
    getline(cin,s);
    bool result=checkpalindrome(s);
    cout<<boolalpha<<result;
}