#include<bits/stdc++.h>
using namespace std;
void printpattern(int n)
{
    
    for(int i=1;i<=n;i++)
    {
        int k=1;
        if(i%2==0)k=0;
        else k=1;
        for(int j=0;j<i;j++){
          cout<<k;
          k=1-k;
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