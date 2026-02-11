#include<bits/stdc++.h>
using namespace std;
void printpattern(int n){
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++){
            cout<<" ";
        }
        for(int j=n;j>i;j--)
        {
            cout<<"*";
        }
        for(int j=n;j>i+1;j--){
            cout<<"*";
        }
        cout<<endl;

    }
}
int main()
{
    int n;
    cout<<"Enter number of rows\n";
    cin>>n;
    printpattern(n);
    return 0;
}