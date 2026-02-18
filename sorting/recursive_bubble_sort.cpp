#include<bits/stdc++.h>
using namespace std;
void rec_bubble_sort(vector<int>&arr,int n)
{
    if(n==1)return;
     bool swapped=false;
    for(int i=0;i<=n-2;i++)
    {
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
            swapped=true;
        }
    }
    if(!swapped)return;
    rec_bubble_sort(arr,n-1);
}
int main()
{
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    vector<int>arr(n);

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    rec_bubble_sort(arr,n);
    cout<<"After sorting:\n";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}