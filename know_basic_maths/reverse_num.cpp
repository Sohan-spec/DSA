#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"n:\n";
    cin>>n;
    int revnum=0;
    while(n!=0)
    {
        int rem=n%10;
        revnum=revnum*10+rem;
        n/=10;
    }
    cout<<revnum;
}