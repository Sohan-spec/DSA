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
        for(int j=0;j<=i;j++)
        {
            cout<<char('A'+j);
        }
        for(int j=i-1;j>=0;j--)
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