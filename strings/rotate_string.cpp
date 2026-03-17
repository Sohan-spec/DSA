#include<bits/stdc++.h>
using namespace std;
bool optimal_soln(string s,string goal){
    if(s.length()!=goal.length())return false;
    return (s+s).find(goal)!=string::npos;
}
int main()
{
    string s="skanda";
    string goal="daskan";
    cout<<boolalpha<<optimal_soln(s,goal);
}