#include<bits/stdc++.h>
using namespace std;
string optimal_soln(string s){
    int count=0;
    string result="";
    for(char c:s){
        if(c==')'){
            count--;
        }
        if(count!=0)result+=c;
        if(c=='('){
            count++;
        }
    }
    return result;
}
int main()
{
    string s="(()())(())";
    cout<<optimal_soln(s);
}