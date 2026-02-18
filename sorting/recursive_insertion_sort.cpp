#include<bits/stdc++.h>
using namespace std;
void rec_insertion_sort(vector<int>&arr,int start,int n)
{
    if(start==n)return;
    int i=start;
    while(i>0 && arr[i-1]>arr[i]){
        swap(arr[i-1],arr[i]);
        i--;
    }
    rec_insertion_sort(arr,start+1,n);

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

    rec_insertion_sort(arr,0,n);
    cout<<"After sorting:\n";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}