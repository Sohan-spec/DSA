#include<bits/stdc++.h>
using namespace std;
int optimal_soln(string s){
    int i=0,n=s.length();
    //this is for spaces
    while(i<n && s[i]==' ')i++;
    int sign=1;
    //this is for like the signs
    if(i<n && (s[i]=='+' || s[i] =='-')){
        if(s[i]=='-')sign=-1;
        i++;
    }

    int res=0;
    while(i<n && isdigit(s[i])){
        int digit=s[i]-'0';
        if(res>(INT_MAX-digit)/10){
            return sign==1?INT_MAX:INT_MIN;
        }
        res=res*10+digit;
        i++;
    }
    return sign*res;
}
int main(){
    string s="1337c0d3";
    cout<<optimal_soln(s);
}