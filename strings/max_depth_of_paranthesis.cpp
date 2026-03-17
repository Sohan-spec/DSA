#include<bits/stdc++.h>
using namespace std;

int brute_force(string s)
{
    int depth=0,max_depth=0;
    for(char c:s){
        if(c=='('){
            depth++;
            max_depth=max(depth,max_depth);
        }
        else if (c==')'){
            depth--;
        }
    }
    return max_depth;
}
int main()
{
    string s="(1)+((2))+(((3)))";
    cout<<brute_force(s);
}