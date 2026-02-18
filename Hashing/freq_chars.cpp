#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cout<<"enter string: ";
    getline(cin,s);
    int hash[26]={0};
     for(int i=0;i<s.size()-1;i++)
    {
        hash[s[i]-'a']+=1;
    }
    cout<<"Enter char to search for: ";
    char c;
    cin>>c;
    cout<<"Freq: "<<hash[c-'a'];
    
}