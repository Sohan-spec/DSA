#include <bits/stdc++.h>
using namespace std;
bool brute_force(string s, string t)
{
    vector<char> s1;
    vector<char> s2;
    int n = s.size();
    int m = t.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '#')
        {
            if(!s1.empty())s1.pop_back();
        }
        else
        {
            s1.emplace_back(s[i]);
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (t[i] == '#')
        {
           if(!s2.empty()) s2.pop_back();
        }
        else
        {
            s2.emplace_back(t[i]);
        }
    }
    if (s1 == s2)
        return true;
    return false;
}
int main()
{
    string s1="ab#c";
    string s2="ad#c";
    cout<<boolalpha<<brute_force(s1,s2);
}