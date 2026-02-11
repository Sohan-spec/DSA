#include <bits/stdc++.h>
using namespace std;
void printpattern(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n - 1; j++)
        {
            cout << " ";
        }
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        for(int j=0;j<i;j++){
            cout<<" ";
        }
        for(int j=n;j>i;j--)
        {
            cout<<"*";
        }
        for(int j=i;j<n-1;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}
int main()
{
    int n;
    cout << "n:\n";
    cin >> n;
    printpattern(n);
    return 0;
}