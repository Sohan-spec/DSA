#include<bits/stdc++.h>
using namespace std;
void printpattern(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=n;j>i;j--){
            cout<<"*";
        }
        for(int j=0;j<2*i;j++)
        {
            cout<<" ";
        }
        for(int j=n;j>i;j--)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++){
            cout<<"*";
        }
        for(int j=0;j<2*(n-i-1);j++)
        {
            cout<<" ";
        }
        for(int j=0;j<=i;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}
int main()
{
    int n;
    cout<<"n:\n";
    cin>>n;
    printpattern(n);
    return 0;
}