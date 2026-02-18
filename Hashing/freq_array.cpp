#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {1, 2, 1, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int hasharray[12] = {0};
    for (int i = 0; i < n; i++)
    {
        hasharray[arr[i]] += 1;
    }
    int number;
    cout<<"Enter number to search: ";
    cin >> number;
    if(number>=0 && number<12){
        cout<<hasharray[number];
    }
    else
    cout<<0;
    return 0;
}
