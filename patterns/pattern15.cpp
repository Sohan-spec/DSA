#include<bits/stdc++.h>
using namespace std;
void printpattern(int n)
{
    for(int i=n;i>0;i--)
    {
        for(int j=0;j<i;j++)
        {
            cout<<char('A'+j);
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