#include<bits/stdc++.h>
using namespace std;

string optimal_soln(string s){
    int n=s.length();
    for(int i=n-1;i>=0;i--){
        if((int)s[i]%2!=0){
            return s.substr(0,i+1);
        }
    }
    return "";
}
int main()
{
    vector<string> s={"flower","flow","flight"};
    string n=*min_element(s.begin(),s.end(),[](const string&a,const string&b){
        return a.size()<b.size();
    });
    cout<<n;
}