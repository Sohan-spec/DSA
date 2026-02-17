#include<bits/stdc++.h>
using namespace std;
void helper(int l,int r,int arr[])
{
    if(l>=r)return;
    swap(arr[l],arr[r]);
    helper(l+1,r-1,arr);
}
int main()
{
    // int arr[6]={1,2,3,4,5,6};
    // int r=5;
    // for(int i=0;i<6;i++)
    // {
    //     int temp=arr[i];
    //     arr[i]=arr[r];
    //     arr[r]=temp;
    //     r--;
    //     if(i==r)break;
    // }
    // for(int i=0;i<6;i++){
    //     cout<<arr[i]<<endl;
    // }
    int arr[]={8,0,0,8,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    helper(0,n-1,arr);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
}