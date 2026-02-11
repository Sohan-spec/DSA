#include<bits/stdc++.h>
using namespace std;
void printpattern(int n)
{
    int spaces=2*(n-1);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
          cout<<j;
        }
        for(int j=1;j<=spaces;j++)
        {
            cout<<" ";
        }
        for(int j=i;j>0;j--)
        {
            cout<<j;
        }
        cout<<endl;
        spaces-=2;
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